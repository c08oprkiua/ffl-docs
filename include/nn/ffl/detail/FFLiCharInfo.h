#ifndef FFLI_CHARINFO_H_
#define FFLI_CHARINFO_H_

#include <nn/ffl/FFLBirthPlatform.h>
#include <nn/ffl/FFLCreateID.h>
#include <nn/ffl/FFLFontRegion.h>
#include <nn/ffl/FFLGender.h>

#include <nn/ffl/FFLiAuthorID.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct FFLiCharInfo
{
    u32                 miiVersion;
    struct
    {
        s32             faceType;
        s32             facelineColor;
        s32             faceLine;
        s32             faceMakeup;
        s32             hairType;
        s32             hairColor;
        s32             hairDir;
        s32             eyeType;
        s32             eyeColor;
        s32             eyeScale;
        s32             eyeScaleY;
        s32             eyeRotate;
        s32             eyeSpacingX;
        s32             eyePositionY;
        s32             eyebrowType;
        s32             eyebrowColor;
        s32             eyebrowScale;
        s32             eyebrowScaleY;
        s32             eyebrowRotate;
        s32             eyebrowSpacingX;
        s32             eyebrowPositionY;
        s32             noseType;
        s32             noseScale;
        s32             nosePositionY;
        s32             mouthType;
        s32             mouthColor;
        s32             mouthScale;
        s32             mouthScaleY;
        s32             mouthPositionY;
        s32             mustacheType;
        s32             beardType;
        s32             beardColor;
        s32             mustacheScale;
        s32             mustachePositionY;
        s32             glassType;
        s32             glassColor;
        s32             glassScale;
        s32             glassPositionY;
        s32             moleType;
        s32             moleScale;
        s32             molePositionX;
        s32             molePositionY;
    } parts;
    u32                 height;
    u32                 build;
    u16                 name[10 + 1];
    u16                 creatorName[10 + 1];
    FFLGender           gender;
    u32                 birthMonth;
    u32                 birthDay;
    u32                 favoriteColor;
    u8                  favoriteMii;
    u8                  copyable;
    u8                  ngWord;
    u8                  localOnly;
    u32                 regionMove;
    FFLFontRegion       fontRegion;
    u32                 pageIndex;
    u32                 slotIndex;
    FFLBirthPlatform    birthPlatform;
    FFLCreateID         creatorID;
    u16                 _112;   // Set to zero
    u32                 _114;   // Set to FFLiMiiDataCore._0_24_27
    FFLiAuthorID        authorID;
}
FFLiCharInfo;
NN_STATIC_ASSERT(sizeof(FFLiCharInfo) == 0x120);

/**
 * @brief This enum contains the errors to return for verifying FFLiCharInfo 
 * via FFLiVerifyCharInfoWithReason.
 * 
 * These errors (except FFLI_VERIFY_CHAR_INFO_REASON_OK) mean that a value
 * was found to be outside of the bounds of the valid range for that value.
 * 
 */
typedef enum FFLiVerifyCharInfoReason
{
    //No errors were found in verifying the FFLiCharInfo.
    FFLI_VERIFY_CHAR_INFO_REASON_OK                         =  0,
    //There was an error with the face type in the FFLiCharInfo.
    FFLI_VERIFY_CHAR_INFO_REASON_FACE_TYPE_INVALID          =  1,
    //There was an error with the faceline color in the FFLiCharInfo.
    FFLI_VERIFY_CHAR_INFO_REASON_FACELINE_COLOR_INVALID     =  2,
    //There was an error with the faceline in the FFLiCharInfo.
    FFLI_VERIFY_CHAR_INFO_REASON_FACE_LINE_INVALID          =  3,
    //There was an error with the face makeup in the FFLiCharInfo.
    FFLI_VERIFY_CHAR_INFO_REASON_FACE_MAKE_INVALID          =  4,
    //There was an error with the hair type in the FFLiCharInfo.
    FFLI_VERIFY_CHAR_INFO_REASON_HAIR_TYPE_INVALID          =  5,
    //There was an error with the hair color in the FFLiCharInfo.
    FFLI_VERIFY_CHAR_INFO_REASON_HAIR_COLOR_INVALID         =  6,
    //There was an error with the hair direction in the FFLiCharInfo.
    FFLI_VERIFY_CHAR_INFO_REASON_HAIR_DIR_INVALID           =  7,
    //There was an error with the eye type in the FFLiCharInfo.
    FFLI_VERIFY_CHAR_INFO_REASON_EYE_TYPE_INVALID           =  8,
    //There was an error with the eye color in the FFLiCharInfo.
    FFLI_VERIFY_CHAR_INFO_REASON_EYE_COLOR_INVALID          =  9,
    //There was an error with the eye x scale in the FFLiCharInfo.
    FFLI_VERIFY_CHAR_INFO_REASON_EYE_SCALE_INVALID          = 10,
    //There was an error with the eye y scale in the FFLiCharInfo.
    FFLI_VERIFY_CHAR_INFO_REASON_EYE_SCALE_Y_INVALID        = 11,
    //There was an error with the eye rotation in the FFLiCharInfo.
    FFLI_VERIFY_CHAR_INFO_REASON_EYE_ROTATE_INVALID         = 12,
    //There was an error with the eye spacing in the FFLiCharInfo.
    FFLI_VERIFY_CHAR_INFO_REASON_EYE_SPACING_INVALID        = 13,
    //There was an error with the vertical eye position in the FFLiCharInfo.
    FFLI_VERIFY_CHAR_INFO_REASON_EYE_POS_INVALID            = 14,
    //There was an error with the eyebrow type in the FFLiCharInfo.
    FFLI_VERIFY_CHAR_INFO_REASON_EYEBROW_TYPE_INVALID       = 15,
    //There was an error with the eyebrow color in the FFLiCharInfo.
    FFLI_VERIFY_CHAR_INFO_REASON_EYEBROW_COLOR_INVALID      = 16,
    //There was an error with the eyebrow x scale in the FFLiCharInfo.
    FFLI_VERIFY_CHAR_INFO_REASON_EYEBROW_SCALE_INVALID      = 17,
    //There was an error with the eyebrow y scale in the FFLiCharInfo.
    FFLI_VERIFY_CHAR_INFO_REASON_EYEBROW_SCALE_Y_INVALID    = 18,
    FFLI_VERIFY_CHAR_INFO_REASON_EYEBROW_ROTATE_INVALID     = 19,
    FFLI_VERIFY_CHAR_INFO_REASON_EYEBROW_SPACING_INVALID    = 20,
    FFLI_VERIFY_CHAR_INFO_REASON_EYEBROW_POS_INVALID        = 21,
    FFLI_VERIFY_CHAR_INFO_REASON_NOSE_TYPE_INVALID          = 22,
    FFLI_VERIFY_CHAR_INFO_REASON_NOSE_SCALE_INVALID         = 23,
    FFLI_VERIFY_CHAR_INFO_REASON_NOSE_POS_INVALID           = 24,
    FFLI_VERIFY_CHAR_INFO_REASON_MOUTH_TYPE_INVALID         = 25,
    FFLI_VERIFY_CHAR_INFO_REASON_MOUTH_COLOR_INVALID        = 26,
    FFLI_VERIFY_CHAR_INFO_REASON_MOUTH_SCALE_INVALID        = 27,
    FFLI_VERIFY_CHAR_INFO_REASON_MOUTH_SCALE_Y_INVALID      = 28,
    FFLI_VERIFY_CHAR_INFO_REASON_MOUTH_POS_INVALID          = 29,
    FFLI_VERIFY_CHAR_INFO_REASON_BEARD_TYPE_INVALID         = 30,
    FFLI_VERIFY_CHAR_INFO_REASON_BEARD_COLOR_INVALID        = 31,
    FFLI_VERIFY_CHAR_INFO_REASON_MUSTACHE_TYPE_INVALID      = 32,
    FFLI_VERIFY_CHAR_INFO_REASON_MUSTACHE_SCALE_INVALID     = 33,
    FFLI_VERIFY_CHAR_INFO_REASON_MUSTACHE_POS_INVALID       = 34,
    FFLI_VERIFY_CHAR_INFO_REASON_GLASS_TYPE_INVALID         = 35,
    FFLI_VERIFY_CHAR_INFO_REASON_GLASS_COLOR_INVALID        = 36,
    FFLI_VERIFY_CHAR_INFO_REASON_GLASS_SCALE_INVALID        = 37,
    FFLI_VERIFY_CHAR_INFO_REASON_GLASS_POS_INVALID          = 38,
    FFLI_VERIFY_CHAR_INFO_REASON_MOLE_TYPE_INVALID          = 39,
    FFLI_VERIFY_CHAR_INFO_REASON_MOLE_SCALE_INVALID         = 40,
    FFLI_VERIFY_CHAR_INFO_REASON_MOLE_POS_X_INVALID         = 41,
    FFLI_VERIFY_CHAR_INFO_REASON_MOLE_POS_Y_INVALID         = 42,
    FFLI_VERIFY_CHAR_INFO_REASON_HEIGHT_INVALID             = 43,
    FFLI_VERIFY_CHAR_INFO_REASON_BUILD_INVALID              = 44,
    FFLI_VERIFY_CHAR_INFO_REASON_NAME_INVALID               = 45,
    FFLI_VERIFY_CHAR_INFO_REASON_CREATOR_NAME_INVALID       = 46,
    FFLI_VERIFY_CHAR_INFO_REASON_GENDER_INVALID             = 47,
    FFLI_VERIFY_CHAR_INFO_REASON_BIRTHDAY_INVALID           = 48,
    FFLI_VERIFY_CHAR_INFO_REASON_FAVORITE_COLOR_INVALID     = 49,
    FFLI_VERIFY_CHAR_INFO_REASON_REGION_MOVE_INVALID        = 50,
    FFLI_VERIFY_CHAR_INFO_REASON_FONT_REGION_INVALID        = 51,
    FFLI_VERIFY_CHAR_INFO_REASON_PAGE_INDEX_INVALID         = 52,
    FFLI_VERIFY_CHAR_INFO_REASON_SLOT_INDEX_INVALID         = 53,
    FFLI_VERIFY_CHAR_INFO_REASON_BIRTH_PLATFORM_INVALID     = 54,
    FFLI_VERIFY_CHAR_INFO_REASON_CREATOR_ID_INVALID         = 55
}
FFLiVerifyCharInfoReason;

/**
 * @brief Verify a FFLiCharInfo, but simply get whether it is invalid or not.
 * 
 * @param pCharInfo The FFLiCharInfo to check.
 * @param verifyName If true, the name will also be checked for validity.
 * @return BOOL True if the data is valid, else false.
 */
BOOL FFLiVerifyCharInfo(const FFLiCharInfo* pCharInfo, BOOL verifyName);

/**
 * @brief Verify the provided FFLiCharInfo, and return the first found reason it is invalid,
 * if one is found. Otherwise, this will return FFLI_VERIFY_CHAR_INFO_REASON_OK.
 * 
 * Note: This will return upon the first error found, meaning you will need to run this multiple 
 * times on the same data to find several different invalid data fields (after correcting previously found ones)
 * 
 * @param pCharInfo The FFLiCharInfo to check.
 * @param verifyName If true, the name will also be checked for validity.
 * @return FFLiVerifyCharInfoReason The first found invalid parameter in pCharInfo, if one is found.
 */
FFLiVerifyCharInfoReason FFLiVerifyCharInfoWithReason(const FFLiCharInfo* pCharInfo, BOOL verifyName);

#ifdef __cplusplus

}

// --------------------------------------------------------------------------
/**
 * @brief Verify a FFLiCharInfo, but simply get whether it is invalid or not.
 * 
 * @param pCharInfo The FFLiCharInfo to check.
 * @param verifyName If true, the name will also be checked for validity.
 * @return BOOL True if the data is valid, else false.
 */
BOOL FFLiiVerifyCharInfo(const FFLiCharInfo* pCharInfo, BOOL verifyName);

s32 FFLiiGetEyeRotateOffset(s32 type);
s32 FFLiiGetEyebrowRotateOffset(s32 type);
f32 FFLiiGetAdjustedMouthH(f32 height, s32 type);
f32 FFLiiGetAdjustedEyeH(f32 height, s32 type);

// --------------------------------------------------------------------------

/**
 * @brief Check if the input character is valid for a Mii name.
 * 
 * @param c The character to check.
 * @return true The character is valid.
 * @return false The character is invalid.
 */
bool FFLiIsValidCharacterForName(u16 c);

// --------------------------------------------------------------------------

struct FFLAdditionalInfo;

enum FFLiCompareCharInfoFlag
{
    FFLI_COMPARE_CHAR_INFO_FLAG_PARTS           = 1 <<  0,
    FFLI_COMPARE_CHAR_INFO_FLAG_NAME            = 1 <<  1,
    FFLI_COMPARE_CHAR_INFO_FLAG_CREATOR_NAME    = 1 <<  2,
    FFLI_COMPARE_CHAR_INFO_FLAG_CREATOR_ID      = 1 <<  3,
    FFLI_COMPARE_CHAR_INFO_FLAG_GENDER          = 1 <<  4,
    FFLI_COMPARE_CHAR_INFO_FLAG_BIRTH_MONTH     = 1 <<  5,
    FFLI_COMPARE_CHAR_INFO_FLAG_BIRTH_DAY       = 1 <<  6,
    FFLI_COMPARE_CHAR_INFO_FLAG_FAVORITE_COLOR  = 1 <<  7,
    FFLI_COMPARE_CHAR_INFO_FLAG_HEIGHT          = 1 <<  8,
    FFLI_COMPARE_CHAR_INFO_FLAG_BUILD           = 1 <<  9,
    FFLI_COMPARE_CHAR_INFO_FLAG_FACELINE_COLOR  = 1 << 10,
    FFLI_COMPARE_CHAR_INFO_FLAG_MII_VERSION     = 1 << 11,
    FFLI_COMPARE_CHAR_INFO_FLAG_COPYABLE        = 1 << 12,
    FFLI_COMPARE_CHAR_INFO_FLAG_NG_WORD         = 1 << 13,
    FFLI_COMPARE_CHAR_INFO_FLAG_LOCAL_ONLY      = 1 << 14,
    FFLI_COMPARE_CHAR_INFO_FLAG_REGION_MOVE     = 1 << 15,
    FFLI_COMPARE_CHAR_INFO_FLAG_FONT_REGION     = 1 << 16,
    FFLI_COMPARE_CHAR_INFO_FLAG_BIRTH_PLATFORM  = 1 << 17,
};

bool FFLiCompareCharInfoWithAdditionalInfo(s32* pFlagOut, s32 flagIn, const FFLiCharInfo* pCharInfoA, const FFLiCharInfo* pCharInfoB, const FFLAdditionalInfo* pAdditionalInfoA, const FFLAdditionalInfo* pAdditionalInfoB);

#endif

#endif // FFLI_CHARINFO_H_
