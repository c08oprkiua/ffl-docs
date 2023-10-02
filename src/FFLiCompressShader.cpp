#include <nn/ffl/FFLiCompressShader.h>
#include <nn/ffl/FFLiInvalidate.h>
#include <nn/ffl/FFLiUtilShaderAllocator.h>

#include <nn/ffl/detail/FFLiCompressUniform.h>

static void InvalidateFetchShader(GX2FetchShader* pShader)
{
    FFLiInvalidateShader(pShader->shaderPtr, pShader->shaderSize);
}

static void InvalidateVertexShader(GX2VertexShader* pShader)
{
    FFLiInvalidateShader(pShader->shaderPtr, pShader->shaderSize);
}

static void InvalidatePixelShader(GX2PixelShader* pShader)
{
    FFLiInvalidateShader(pShader->shaderPtr, pShader->shaderSize);
}

FFLiCompressShader::FFLiCompressShader()
    : m_FetchShader()
    , m_pVertexShader(NULL)
    , m_pPixelShader(NULL)
    , m_Sampler()
{
}

FFLiCompressShader::~FFLiCompressShader()
{
}

bool FFLiCompressShader::UseUB() const
{
    return m_pVertexShader->shaderMode == GX2_SHADER_MODE_UNIFORM_BLOCK;
}

static const char* s_Samplers[1] = {
    "cTexture"
};

bool FFLiCompressShader::SetupLocation()
{
    if (!FFLiUtilShader::GetSamplerLocation(&m_SamplerLocation, m_pPixelShader, s_Samplers[0]))
        return false;

    if (UseUB())
        return SetupLocationForUB();

    return SetupLocationForUR();
}

static const char* s_VertexUniforms[1] = {
    "cTexSizeRCP"
};

static const char* s_PixelUniforms[1] = {
    "cReferLevel"
};

bool FFLiCompressShader::SetupLocationForUR()
{
    if (!FFLiUtilShader::GetUniformLocation(&m_VertexUniformLocation, m_pVertexShader, s_VertexUniforms[0]))
        return false;

    FFLiUtilShader::GetUniformLocation(&m_PixelUniformLocation, m_pPixelShader, s_PixelUniforms[0]);
    return true;
}

static const char* s_VertexUniformBlocks[1] = {
    "cVertexBlock"
};

static const char* s_PixelUniformBlocks[1] = {
    "cPixelBlock"
};

bool FFLiCompressShader::SetupLocationForUB()
{
    if (!FFLiUtilShader::GetUniformBlockLocation(&m_VertexUniformLocation, m_pVertexShader, s_VertexUniformBlocks[0]))
        return false;

    if (!FFLiUtilShader::GetUniformBlockLocation(&m_PixelUniformLocation, m_pPixelShader, s_PixelUniformBlocks[0]))
        return false;

    return true;
}

static FFLiUtilShader::AttributeStreamDesc s_Attributes[2] = {
    { "aPosition", 0, 0, GX2_ATTRIB_FORMAT_32_32_32_FLOAT },
    { "aTexCoord", 1, 0, GX2_ATTRIB_FORMAT_32_32_FLOAT }
};

bool FFLiCompressShader::SetupCPU(const void* pShaderData, u32 shaderIndex, FFLiBufferAllocator* pAllocator)
{
    FFLiUtilShaderAllocator shaderAllocator(pAllocator, 2, pShaderData, shaderIndex);

    if (!FFLiUtilShader::BuildShader(&m_pVertexShader, &shaderAllocator, pShaderData, shaderIndex, false))
        return false;

    if (!FFLiUtilShader::BuildShader(&m_pPixelShader, &shaderAllocator, pShaderData, shaderIndex, false))
        return false;

    if (!FFLiUtilShader::BuildShader(&m_FetchShader, m_pVertexShader, &shaderAllocator, s_Attributes, 2, false))
        return false;

    GX2InitSampler(&m_Sampler, GX2_TEX_CLAMP_MIRROR, GX2_TEX_XY_FILTER_POINT);

    if (!SetupLocation())
        return false;

    return true;
}

void FFLiCompressShader::SetupGPU()
{
    InvalidateFetchShader(&m_FetchShader.fetchShader);
    InvalidateVertexShader(m_pVertexShader);
    InvalidatePixelShader(m_pPixelShader);
}

void FFLiCompressShader::Bind() const
{
    GX2SetFetchShader(&m_FetchShader.fetchShader);
    GX2SetVertexShader(m_pVertexShader);
    GX2SetPixelShader(m_pPixelShader);
}

void FFLiCompressShader::SetTexture(const GX2Texture* pGX2Texture) const
{
    GX2SetPixelSampler(&m_Sampler, m_SamplerLocation);
    GX2SetPixelTexture(pGX2Texture, m_SamplerLocation);
}

void FFLiCompressShader::SetUniform(const FFLiCompressUniform* pUniform) const
{
    if (UseUB())
        SetUniformUB(pUniform);

    else
        SetUniformUR(pUniform);
}

void FFLiCompressShader::SetUniformUR(const FFLiCompressUniform* pUniform) const
{
    const void* pVertexUniform = pUniform->GetVertexUniform();
    const void* pPixelUniform = pUniform->GetPixelUniform();

    GX2SetVertexUniformReg(m_VertexUniformLocation, 4, pVertexUniform);
    GX2SetPixelUniformReg(m_PixelUniformLocation, 4, pPixelUniform);
}

void FFLiCompressShader::SetUniformUB(const FFLiCompressUniform* pUniform) const
{
    const void* pVertexUniform = pUniform->GetVertexUniform();
    const void* pPixelUniform = pUniform->GetPixelUniform();

    GX2SetVertexUniformBlock(m_VertexUniformLocation, 4 * sizeof(u32), pVertexUniform);
    GX2SetPixelUniformBlock(m_PixelUniformLocation, 4 * sizeof(u32), pPixelUniform);
}

u32 FFLiCompressShader::GetBufferSize(const void* pShaderData, u32 shaderIndex)
{
    return FFLiUtilShader::GetBufferSize(2, pShaderData, shaderIndex);
}
