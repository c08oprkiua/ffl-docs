#ifndef FFL_COLOR_H_
#define FFL_COLOR_H_

#include <nn/ffl/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief The in color type in FFL
 * 
 * This is the in-house type used to store color values in FFL. It's stored in an RGBA float format.
 * This is NOT the same as @ref FavoriteColor
 */

typedef struct FFLColor
{
    //! The red value
    f32 r;
    //! The green value
    f32 g;
    //! The blue value
    f32 b;
    //! The alpha value
    f32 a;
}
FFLColor;
NN_STATIC_ASSERT(sizeof(FFLColor) == 0x10);

#ifdef __cplusplus
}
#endif

#endif // FFL_COLOR_H_
