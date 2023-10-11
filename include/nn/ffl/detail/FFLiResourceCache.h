#ifndef FFLI_RESOURCE_CACHE_H_
#define FFLI_RESOURCE_CACHE_H_

#include <nn/ffl/FFLResourceType.h>

class FFLiResourceHeader;

class FFLiResourceCache
{
public:
    FFLiResourceCache();
    ~FFLiResourceCache();

    FFLiResourceHeader* Header(FFLResourceType resourceType) const;

private:
    struct
    {
        const void* pData;
        u32         size;
    }   m_Res[FFL_RESOURCE_TYPE_MAX];
};
NN_STATIC_ASSERT(sizeof(FFLiResourceCache) == 0x10);

#endif // FFLI_RESOURCE_CACHE_H_
