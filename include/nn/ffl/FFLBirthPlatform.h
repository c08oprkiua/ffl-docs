#ifndef FFL_BIRTH_PLATFORM_H_
#define FFL_BIRTH_PLATFORM_H_

#include <nn/ffl/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Enumeration for which platform the Mii was originally created on. 
typedef enum FFLBirthPlatform
{
    //! This Mii was made on a Wii.
    FFL_BIRTH_PLATFORM_WII     = 1, 
    //! This Mii was made on a DS or DSi.
    FFL_BIRTH_PLATFORM_NTR     = 2, 
    //! This Mii was made on a 3DS.
    FFL_BIRTH_PLATFORM_CTR     = 3, 
    //! This Mii was made on a Wii U or Switch.
    FFL_BIRTH_PLATFORM_WII_U   = 4 
}
FFLBirthPlatform;

#ifdef __cplusplus
}
#endif

#endif // FFL_BIRTH_PLATFORM_H_