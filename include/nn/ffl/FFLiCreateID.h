#ifndef FFLI_CREATE_ID_H_
#define FFLI_CREATE_ID_H_

#include <nn/ffl/FFLCreateID.h>

#ifdef __cplusplus
extern "C" {
#endif

#define FFLI_CREATE_ID_BASE_SIZE  (6)

/**
 * @ingroup IDs
 * 
 * @brief The base ID of various ID types.
 * 
 */

typedef struct FFLiCreateIDBase
{
    // Unsure if this is correct
    union
    {
        u8 data[FFLI_CREATE_ID_BASE_SIZE];
        u16 value16[FFLI_CREATE_ID_BASE_SIZE / sizeof(u16)];
    };
}
FFLiCreateIDBase;
NN_STATIC_ASSERT(sizeof(FFLiCreateIDBase) == FFLI_CREATE_ID_BASE_SIZE);

#define FFLI_CREATE_ID_FLAG_UNKNOWN_0   (1 << 4)
#define FFLI_CREATE_ID_FLAG_TEMPORARY   (1 << 5)
#define FFLI_CREATE_ID_FLAG_UNKNOWN_2   (1 << 6)
#define FFLI_CREATE_ID_FLAG_NORMAL      (1 << 7)

/**
 * @ingroup IDs
 * 
 * @brief A structure for Mii IDs which contains flags about certain Mii attributes.
 * 
 * This builds upon and contains FFLiCreateIDBase.
 */

typedef struct FFLiCreateID
{
    /**
     * @brief A bitfield of various flags for the Mii.
     * 
     * Bit 4 is related to if the Mii is from an NTR console.
     * Bit 5 indicates whether the Mii is temporary or not
     * Bit 6 is related to if the Mii is from an NTR console.
     * Bit 7 indicates whether the Mii is normal or special.
     * 
     */
    u8                  flags;
    u8                  _1;
    u8                  _2;
    u8                  databaseIndex;
    //! The underlying @ref FFLICreateIDBase
    FFLiCreateIDBase    base;
}
FFLiCreateID;
NN_STATIC_ASSERT(sizeof(FFLiCreateID) == FFL_CREATE_ID_SIZE);

/**
 * @brief Checks if a Mii ID is null or not.
 * 
 * @param pCreateID the ID to check.
 * @return True if the ID is null, else false.
 */
BOOL FFLiIsNullMiiID(const FFLCreateID* pCreateID);

/**
 * @brief Makes a FFLCreateID into a new, temporary Mii ID. 
 * 
 * @param pCreateID The FFLCreateID to initialize.
 */
void FFLiGetTemporaryMiiID(FFLCreateID* pCreateID);
/**
 * @brief Checks if a Mii ID is normal or not.
 * 
 * @param pCreateID The ID to check.
 * @return True if the Mii ID is for a normal Mii, else false.
 */
BOOL FFLiIsNormalMiiID(const FFLCreateID* pCreateID);
/**
 * @brief Checks if a Mii ID is for a special Mii.
 * 
 * This internally just returns the opposite of @ref FFLiIsNormalMiiID
 * 
 * @param pCreateID The ID to check.
 * @return True if the Mii ID is for a special Mii, else false.
 */
BOOL FFLiIsSpecialMiiID(const FFLCreateID* pCreateID);
/**
 * @brief Checks if a Mii ID is for a Mii originating from a Nintendo DS.
 * 
 * @param pCreateID The ID to check.
 * @return True if the Mii is from a DS, else false.
 */
BOOL FFLiIsNTRMiiID(const FFLCreateID* pCreateID);
/**
 * @brief Returns whether a Mii ID is for a temporary Mii or not.
 * 
 * @param pCreateID the FFLCreateID to check.
 * @return BOOL 
 */
BOOL FFLiIsTemporaryMiiID(const FFLCreateID* pCreateID);

/**
 * @brief Checks if a Mii ID is valid.
 * 
 * An ID is valid when it is not null and not temporary.
 * 
 * @param pCreateID The ID to check.
 * @return True if the ID is valid, else false. 
 */
BOOL FFLiIsValidMiiID(const FFLCreateID* pCreateID);
/**
 * @brief Compares two Mii IDs to determine if they are the same or not.
 * 
 * This will fail if one or both of the IDs are not valid IDs. See @ref FFLiIsValidMiiID
 * 
 * @param a First FFLCreateID for comparing.
 * @param b Second FFLCreateID for comparing.
 * @return True if they are the same, else false.
 */
BOOL FFLiIsSameMiiID(const FFLCreateID* a, const FFLCreateID* b);

#ifdef __cplusplus
}
#endif

#endif // FFLI_CREATE_ID_H_
