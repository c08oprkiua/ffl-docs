#ifndef FFL_FONT_REGION_H_
#define FFL_FONT_REGION_H_

#include <nn/ffl/types.h>

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @typedef FFLFontRegion
 * 
 * @brief Enumeration for the font file used for the Mii.
 * The font region tells software which font file to use when displaying the text fields of a Mii.
 * 
*/
typedef enum FFLFontRegion
{
    //! Japan, Europe, and USA font file.
    FFL_FONT_REGION_0   = 0,
    //! Chinese font file.
    FFL_FONT_REGION_1   = 1,
    //! Korean font file.
    FFL_FONT_REGION_2   = 2,
    //! Taiwan font file.
    FFL_FONT_REGION_3   = 3
}
FFLFontRegion;

#ifdef __cplusplus
}
#endif

#endif // FFL_FONT_REGION_H_
