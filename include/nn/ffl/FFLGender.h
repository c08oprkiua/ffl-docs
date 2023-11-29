#ifndef FFL_GENDER_H_
#define FFL_GENDER_H_

#include <nn/ffl/types.h>

#ifdef __cplusplus
extern "C" {
#endif
/**
 * The Mii's gender. 
 * 
 * 
*/
typedef enum FFLGender
{
    //! The Mii is male.
    FFL_GENDER_MALE     = 0,
    //! The Mii is female. 
    FFL_GENDER_FEMALE   = 1,
    //! Signifies the maximum possible values of this enumeration. It is not itself a value. 
    FFL_GENDER_MAX      = 2
}
FFLGender;

#ifdef __cplusplus
}
#endif

#endif // FFL_GENDER_H_
