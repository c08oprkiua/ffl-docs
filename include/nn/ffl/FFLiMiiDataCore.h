#ifndef FFLI_MIIDATA_CORE_H_
#define FFLI_MIIDATA_CORE_H_

#include <nn/ffl/FFLCreateID.h>
#include <nn/ffl/FFLStandard.h>

#include <nn/ffl/FFLiAuthorID.h>

// Note: Keep in mind that bitfields are not portable.
//       The Wii U compiler orders fields in bitfield structs such that the first field is at the MSB.
//       However, the 3DS compiler orders fields in bitfield structs such that the first field is at the LSB.
//       Therefore, if you would like to use these structures for 3DS, make sure to reverse the order of fields in every bitfield struct.

/**
 * @defgroup MiiDataCore MiiDataCore
 * 
 * @brief The various data types of Miis.
 * 
 * These are various forms of Mii data that FFL uses, both internal and external.
 */
*/



/**
 * @brief The core Mii data type used by FFL.
 * 
 * This is the base class from which various other data types derive.
 * 
*/
class FFLiMiiDataCore
{
public:
    /** @defgroup setters "Set" Functions
     * @ingroup setters
     * @brief Set the Mii's version.
     * 
     * @param version The Mii version.
    */
    void SetMiiVersion(u8 version)
    {
        m_MiiVersion = version;
    }
    /** @defgroup getters "Get" Functions
     * @ingroup getters
     * 
     * @brief Get the Mii's version.
    */
    u8 MiiVersion() const
    {
        return m_MiiVersion;
    }
    /**
     * @ingroup setters
     * @brief Set if the Mii is copyable or not.
     * 
     * @param enable Whether or not the Mii can be copied.
     */
    void SetCopyable(bool enable)
    {
        m_Copyable = enable;
    }
    /**
     * @ingroup getters
     * @brief Get the value of whether or not the Mii is copyable.
     * 
     * @return true: Mii is copyable.
     * @return false: Mii is not copyable.
     */
    bool Copyable() const
    {
        return m_Copyable;
    }
    /**
     * @ingroup setters
     * @brief Set the profanity flag on the Mii.
     * 
     * This will be enabled if the Mii contains profanity in either its creator or name field.
    */
    void SetNgWord(bool enable)
    {
        m_NgWord = enable;
    }
    /**
     * @ingroup getters
     * @brief Get the profanity flag on the Mii.
     * 
     * This will be enabled if the Mii contains profanity in either its creator or name field.
    */
    bool NgWord() const
    {
        return m_NgWord;
    }

    void SetRegionMove(u16 regionMove)
    {
        m_RegionMove = regionMove;
    }

    u16 RegionMove() const
    {
        return m_RegionMove;
    }
    /**
     * @ingroup setters
     * @brief Set whether or not the Mii is local only.
     * 
     * @param localOnly 
     */
    void SetLocalOnly(bool localOnly)
    {
        m_LocalOnly = localOnly;
    }
    /**
     * @ingroup getters
     * @brief Get whether or not the Mii is local only.
     * 
     * @return true: The Mii is local only.
     * @return false: The Mii is not local only.
     */
    bool LocalOnly() const
    {
        return m_LocalOnly;
    }
    /**
     * @ingroup setters
     * @brief Set the Font Region.
     * 
     * @param region A FFLFontRegion enum. 
     */
    void SetFontRegion(u16 region)
    {
        m_FontRegion = region;
    }

    u16 FontRegion() const
    {
        return m_FontRegion;
    }

    void SetPageIndex(u16 index)
    {
        m_PageIndex = index;
    }

    u16 PageIndex() const
    {
        return m_PageIndex;
    }

    void SetSlotIndex(u16 index)
    {
        m_SlotIndex = index;
    }

    u16 SlotIndex() const
    {
        return m_SlotIndex;
    }

    void SetFlagBit24To27(u16 value)
    {
        _0_24_27 = value;
    }

    u16 FlagBit24To27() const
    {
        return _0_24_27;
    }
    /** @ingroup setters 
     * @brief The original platform the Mii was created on.
     * 
     * @param platform The platform the Mii was created on. See FFLBirthPlatform.
    */
    void SetBirthPlatform(u16 platform)
    {
        m_BirthPlatform = platform;
    }
    /** @ingroup getters 
     * @brief Get the original platform the Mii was created on.
     * 
     * @return u16: See @ref BirthPlatform.
     */
    u16 BirthPlatform() const
    {
        return m_BirthPlatform;
    }

    FFLiAuthorID& AuthorID()
    {
        return m_AuthorID;
    }

    const FFLiAuthorID& AuthorID() const
    {
        return m_AuthorID;
    }

    FFLCreateID& CreatorID()
    {
        return m_CreatorID;
    }

    const FFLCreateID& CreatorID() const
    {
        return m_CreatorID;
    }

    u8* Padding1()
    {
        return _padding1;
    }

    static u32 Padding1Size()
    {
        return sizeof(u8) * 2;
    }
    /**
     * @ingroup setters
     * @brief Set the gender of the Mii.
    */
    void SetGender(u16 gender)
    {
        m_Gender = gender;
    }
    /**
     * @ingroup getters
     * @brief Get the gender of the Mii.
    */
    u16 Gender() const
    {
        return m_Gender;
    }

    void SetBirthMonth(u16 month)
    {
        m_BirthMonth = month;
    }

    u16 BirthMonth() const
    {
        return m_BirthMonth;
    }

    void SetBirthDay(u16 day)
    {
        m_BirthDay = day;
    }

    u16 BirthDay() const
    {
        return m_BirthDay;
    }

    void SetFavoriteColor(u16 value)
    {
        m_FavoriteColor = value;
    }

    u16 FavoriteColor() const
    {
        return m_FavoriteColor;
    }

    void SetFavoriteMii(u8 favoriteMii)
    {
        m_FavoriteMii = favoriteMii;
    }

    bool FavoriteMii() const
    {
        return m_FavoriteMii;
    }

    u16* Name()
    {
        return m_Name;
    }

    const u16* Name() const
    {
        return m_Name;
    }

    void SetHeight(s32 height)
    {
        m_Height = height;
    }

    s32 Height() const
    {
        return m_Height;
    }

    void SetBuild(s32 build)
    {
        m_Build = build;
    }

    s32 Build() const
    {
        return m_Build;
    }

    void SetFaceType(u16 value)
    {
        m_FaceType = value;
    }

    u16 FaceType() const
    {
        return m_FaceType;
    }

    void SetFacelineColor(u16 value)
    {
        m_FacelineColor = value;
    }

    u16 FacelineColor() const
    {
        return m_FacelineColor;
    }

    void SetFaceLine(u16 value)
    {
        m_FaceLine = value;
    }

    u16 FaceLine() const
    {
        return m_FaceLine;
    }

    void SetFaceMake(u16 value)
    {
        m_FaceMakeup = value;
    }

    u16 FaceMake() const
    {
        return m_FaceMakeup;
    }

    void SetHairType(u16 value)
    {
        m_HairType = value;
    }

    u16 HairType() const
    {
        return m_HairType;
    }

    void SetHairColor(u16 value)
    {
        m_HairColor = value;
    }

    u16 HairColor() const
    {
        return m_HairColor;
    }

    void SetHairDir(u16 value)
    {
        m_HairDir = value;
    }

    u16 HairDir() const
    {
        return m_HairDir;
    }

    void SetEyeType(u16 value)
    {
        m_EyeType = value;
    }

    u16 EyeType() const
    {
        return m_EyeType;
    }

    void SetEyeColor(u16 value)
    {
        m_EyeColor = value;
    }

    u16 EyeColor() const
    {
        return m_EyeColor;
    }

    void SetEyeScale(u16 value)
    {
        m_EyeScale = value;
    }

    u16 EyeScale() const
    {
        return m_EyeScale;
    }

    void SetEyeScaleY(u16 value)
    {
        m_EyeScaleY = value;
    }

    u16 EyeScaleY() const
    {
        return m_EyeScaleY;
    }

    void SetEyeRotate(u16 value)
    {
        m_EyeRotate = value;
    }

    u16 EyeRotate() const
    {
        return m_EyeRotate;
    }

    void SetEyeSpacing(u16 value)
    {
        m_EyeSpacingX = value;
    }

    u16 EyeSpacing() const
    {
        return m_EyeSpacingX;
    }

    void SetEyePosition(u16 value)
    {
        m_EyePositionY = value;
    }

    u16 EyePosition() const
    {
        return m_EyePositionY;
    }

    void SetEyebrowType(u16 value)
    {
        m_EyebrowType = value;
    }

    u16 EyebrowType() const
    {
        return m_EyebrowType;
    }

    void SetEyebrowColor(u16 value)
    {
        m_EyebrowColor = value;
    }

    u16 EyebrowColor() const
    {
        return m_EyebrowColor;
    }

    void SetEyebrowScale(u16 value)
    {
        m_EyebrowScale = value;
    }

    u16 EyebrowScale() const
    {
        return m_EyebrowScale;
    }

    void SetEyebrowScaleY(u16 value)
    {
        m_EyebrowScaleY = value;
    }

    u16 EyebrowScaleY() const
    {
        return m_EyebrowScaleY;
    }

    void SetEyebrowRotate(u16 value)
    {
        m_EyebrowRotate = value;
    }

    u16 EyebrowRotate() const
    {
        return m_EyebrowRotate;
    }

    void SetEyebrowSpacing(u16 value)
    {
        m_EyebrowSpacingX = value;
    }

    u16 EyebrowSpacing() const
    {
        return m_EyebrowSpacingX;
    }

    void SetEyebrowPosition(u16 value)
    {
        m_EyebrowPositionY = value;
    }

    u16 EyebrowPosition() const
    {
        return m_EyebrowPositionY;
    }

    void SetNoseType(u16 value)
    {
        m_NoseType = value;
    }

    u16 NoseType() const
    {
        return m_NoseType;
    }

    void SetNoseScale(u16 value)
    {
        m_NoseScale = value;
    }

    u16 NoseScale() const
    {
        return m_NoseScale;
    }

    void SetNosePosition(u16 value)
    {
        m_NosePositionY = value;
    }

    u16 NosePosition() const
    {
        return m_NosePositionY;
    }

    void SetMouthType(u16 value)
    {
        m_MouthType = value;
    }

    u16 MouthType() const
    {
        return m_MouthType;
    }

    void SetMouthColor(u16 value)
    {
        m_MouthColor = value;
    }

    u16 MouthColor() const
    {
        return m_MouthColor;
    }

    void SetMouthScale(u16 value)
    {
        m_MouthScale = value;
    }

    u16 MouthScale() const
    {
        return m_MouthScale;
    }

    void SetMouthScaleY(u16 value)
    {
        m_MouthScaleY = value;
    }

    u16 MouthScaleY() const
    {
        return m_MouthScaleY;
    }

    void SetMouthPosition(u16 value)
    {
        m_MouthPositionY = value;
    }

    u16 MouthPosition() const
    {
        return m_MouthPositionY;
    }

    void SetMustacheType(u16 value)
    {
        m_MustacheType = value;
    }

    u16 MustacheType() const
    {
        return m_MustacheType;
    }

    void SetBeardType(u16 value)
    {
        m_BeardType = value;
    }

    u16 BeardType() const
    {
        return m_BeardType;
    }

    void SetBeardColor(u16 value)
    {
        m_BeardColor = value;
    }

    u16 BeardColor() const
    {
        return m_BeardColor;
    }

    void SetMustacheScale(u16 value)
    {
        m_MustacheScale = value;
    }

    u16 MustacheScale() const
    {
        return m_MustacheScale;
    }

    void SetMustachePosition(u16 value)
    {
        m_MustachePositionY = value;
    }

    u16 MustachePosition() const
    {
        return m_MustachePositionY;
    }

    void SetGlassType(u16 value)
    {
        m_GlassType = value;
    }

    u16 GlassType() const
    {
        return m_GlassType;
    }

    void SetGlassColor(u16 value)
    {
        m_GlassColor = value;
    }

    u16 GlassColor() const
    {
        return m_GlassColor;
    }

    void SetGlassScale(u16 value)
    {
        m_GlassScale = value;
    }

    u16 GlassScale() const
    {
        return m_GlassScale;
    }

    void SetGlassPosition(u16 value)
    {
        m_GlassPositionY = value;
    }

    u16 GlassPosition() const
    {
        return m_GlassPositionY;
    }

    void SetMoleType(u16 value)
    {
        m_MoleType = value;
    }

    u16 MoleType() const
    {
        return m_MoleType;
    }

    void SetMoleScale(u16 value)
    {
        m_MoleScale = value;
    }

    u16 MoleScale() const
    {
        return m_MoleScale;
    }

    void SetMolePositionX(u16 value)
    {
        m_MolePositionX = value;
    }

    u16 MolePositionX() const
    {
        return m_MolePositionX;
    }

    void SetMolePositionY(u16 value)
    {
        m_MolePositionY = value;
    }

    u16 MolePositionY() const
    {
        return m_MolePositionY;
    }

    void SetPlaceHolder(s32 value)
    {
        m_PlaceHolder = value;
    }

    void SwapEndian();

private:
    union
    {
        struct
        {
            u32                 : 1;    // Unused (MSB)
            //! The platform the Mii was made on
            u32 m_BirthPlatform : 3;
            u32 _0_24_27        : 4;

            //! The Mii's slot index in Mii Maker
            u32 m_SlotIndex     : 4;
            //! The Mii's page index in Mii Maker
            u32 m_PageIndex     : 4;

            u32                 : 2;    // Unused
            //! The font file for the system to use with this Mii.
            u32 m_FontRegion    : 2;
            //! The region lock imposed on the Mii.
            u32 m_RegionMove    : 2;
            //! Whether the Mii's name or creator name contains profanity (to censor out)
            u32 m_NgWord        : 1;    // bool
            //! Whether the Mii is copyable
            u32 m_Copyable      : 1;    // bool

            //! The Mii's version
            u32 m_MiiVersion    : 8;    // (LSB)
        };

        u32 _0;
    };

    union
    {
        FFLiAuthorID    m_AuthorID;

        u8  _4[8];
    };

    union
    {
        FFLCreateID m_CreatorID;

        u8  _c[0xA];
    };
    u8  _padding1[2];

    union
    {
        struct
        {
            u16 m_PlaceHolder   : 1;    // Unused (MSB)
            //! Whether the Mii is favorited in Mii Maker
            u16 m_FavoriteMii   : 1;    // bool
            //! The Mii's shirt color
            u16 m_FavoriteColor : 4;
            //! The Mii's birthday day
            u16 m_BirthDay      : 5;
            //! The Mii's birthday month
            u16 m_BirthMonth    : 4;
            //! The Mii's gender
            u16 m_Gender        : 1;    // (LSB)
        };

        u16 _18;
    };

    u16 m_Name[10]; // Wstring

    u8  m_Height;
    u8  m_Build;

    union
    {
        struct
        {
            //! The Mii's makeup
            u16 m_FaceMakeup    : 4;    // (MSB)
            u16 m_FaceLine      : 4;
            //! The Mii's skin color
            u16 m_FacelineColor : 3;
            //! The Mii's facial structure
            u16 m_FaceType      : 4;
            //! Whether the Mii is local only
            u16 m_LocalOnly     : 1;    // bool (LSB)
        };

        u16 _30;
    };
    union
    {
        struct
        {
            u16             : 4;    // Unused (MSB)
            //! If the hair is flipped
            u16 m_HairDir   : 1;
            //! The color of the Mii's hair
            u16 m_HairColor : 3;
            //! The Mii's hair style
            u16 m_HairType  : 8;    // (LSB)
        };

        u16 _32;
    };
    union
    {
        struct
        {
            //! The y stretch scale of the Mii's eyes
            u16 m_EyeScaleY : 3;    // (MSB)
            //! The x stretch scale of the Mii's eyes
            u16 m_EyeScale  : 4;
            //! The color of the Mii's eyes
            u16 m_EyeColor  : 3;
            //! The type of eyes the Mii has
            u16 m_EyeType   : 6;    // (LSB)
        };

        u16 _34;
    };
    union
    {
        struct
        {
            u16                     : 2;    // Unused (MSB)
            //! The vertical placement of the Mii's eyes on its face
            u16 m_EyePositionY      : 5;
            //! The spacing between the Mii's eyes
            u16 m_EyeSpacingX       : 4;
            //! The rotation of the Mii's eyes
            u16 m_EyeRotate         : 5;    // (LSB)
        };

        u16 _36;
    };
    union
    {
        struct
        {
            u16                 : 1;    // Unused (MSB)
            //! The vertical thickness of the Mii's eyebrows
            u16 m_EyebrowScaleY : 3;
            //! The horizontal thickness of the Mii's eyebrows
            u16 m_EyebrowScale  : 4;
            //! The color of the Mii's eyebrows
            u16 m_EyebrowColor  : 3;
            //! The style of the Mii's eyebrows
            u16 m_EyebrowType   : 5;    // (LSB)
        };

        u16 _38;
    };
    union
    {
        struct
        {
            u16                         : 2;    // Unused (MSB)
            //! The vertical placement of the eyebrows on the Mii's face
            u16 m_EyebrowPositionY      : 5;
            //! The spacing between the Mii's eyebrows
            u16 m_EyebrowSpacingX       : 4;
            //! The rotation of the Mii's eyebrows
            u16 m_EyebrowRotate         : 5;    // (LSB)
        };

        u16 _3A;
    };
    union
    {
        struct
        {
            u16                 : 2;    // Unused (MSB)
            //! The vertical placement of the Mii's nose
            u16 m_NosePositionY : 5;
            //! The size of the Mii's nose
            u16 m_NoseScale     : 4;
            //! The shape of the Mii's nose
            u16 m_NoseType      : 5;    // (LSB)
        };

        u16 _3C;
    };
    union
    {
        struct
        {
            //! The vertical scale of the Mii's mouth
            u16 m_MouthScaleY   : 3;    // (MSB)
            //! The horizontal scale of the Mii's mouth
            u16 m_MouthScale    : 4;
            //! The color of the Mii's lips (for types that have colors)
            u16 m_MouthColor    : 3;
            //! The mouth type of the Mii
            u16 m_MouthType     : 6;    // (LSB)
        };

        u16 _3E;
    };
    union
    {
        struct
        {
            u16                     : 8;    // Unused (MSB)
            //! The type of mustache the Mii has
            u16 m_MustacheType      : 3;
            //! The vertical placement of the Mii's mouth
            u16 m_MouthPositionY    : 5;    // (LSB)
        };

        u16 _40;
    };
    union
    {
        struct
        {
            u16                     : 1;    // Unused (MSB)
            //! The vertical position of the Mii's mustache
            u16 m_MustachePositionY : 5;
            //! The size of the Mii's mustache
            u16 m_MustacheScale     : 4;
            //! The color of the Mii's beard
            u16 m_BeardColor        : 3;
            //! The type of beard the Mii has
            u16 m_BeardType         : 3;    // (LSB)
        };

        u16 _42;
    };
    union
    {
        struct
        {
            //! The vertical position of the Mii's glasses
            u16 m_GlassPositionY    : 5;    // (MSB)
            //! The size of the Mii's glasses
            u16 m_GlassScale        : 4;
            //! The color of the Mii's glasses
            u16 m_GlassColor        : 3;
            //! The type of glasses the Mii has
            u16 m_GlassType         : 4;    // (LSB)
        };

        u16 _44;
    };
    union
    {
        struct
        {
            u16                 : 1;    // Unused (MSB)
            //! The vertical position of the Mii's mole
            u16 m_MolePositionY : 5;
            //! The horizontal position of the Mii's mole
            u16 m_MolePositionX : 5;
            //! The size of the Mii's mole
            u16 m_MoleScale     : 4;
            //! Whether or not the Mii's mole is visible
            u16 m_MoleType      : 1;    // (LSB)
        };

        u16 _46;
    };
};
NN_STATIC_ASSERT_IS_POD(FFLiMiiDataCore);
NN_STATIC_ASSERT(sizeof(FFLiMiiDataCore) == 0x48);

class FFLiMiiDataOfficial : public FFLiMiiDataCore
{
public:
    u16* CreatorName()
    {
        return m_CreatorName;
    }

    const u16* CreatorName() const
    {
        return m_CreatorName;
    }

    void SwapEndian();

private:
    u16 m_CreatorName[10];  // Wstring
};
NN_STATIC_ASSERT_IS_POD(FFLiMiiDataOfficial);
NN_STATIC_ASSERT(sizeof(FFLiMiiDataOfficial) == 0x5C);

#define FFL_STOREDATA_SIZE  (0x60)
/**
 * @brief Internal FFLStoreData type
 * 
 * This is FFLStoreData/FFLiStoreDataCFL converted to big endian, 
 * and is what the Wii U internally uses for processing Mii data.
 */
class FFLiStoreData : public FFLiMiiDataOfficial
{
public:
    void SetCRC();
    void SwapEndian();

private:
    u16 _5c;
    u16 m_Crc;
};
NN_STATIC_ASSERT_IS_POD(FFLiStoreData);
NN_STATIC_ASSERT(sizeof(FFLiStoreData) == FFL_STOREDATA_SIZE);

/**
 * @typedef FFLStoreDataCFL
 * @brief A type of Mii data structure that is used to share Mii data around. 
 * 
 * Essentially an alias of FFLStoreData.
 */

struct FFLiStoreDataCFL : FFLStoreData
{
};
NN_STATIC_ASSERT_IS_POD(FFLiStoreDataCFL);
NN_STATIC_ASSERT(sizeof(FFLiStoreDataCFL) == FFL_STOREDATA_SIZE);

class FFLiMiiDataHidden : public FFLiMiiDataCore
{
public:
    void SwapEndian();  // Deleted in NSMBU

private:
    u32 _48[12 / sizeof(u32)];  // Actual type unknown
};
NN_STATIC_ASSERT_IS_POD(FFLiMiiDataHidden);
NN_STATIC_ASSERT(sizeof(FFLiMiiDataHidden) == 0x54);
/**
 * 
 * @brief A type of Mii data structure that is used to share Mii data around. 
 * 
 * This is similar to FFLStoreData, but happens to be even smaller.
 * It uses bitshift operators internally as opposed to bitfields, making it more compiler-agnostic(?).
 */
class FFLiMiiDataCoreRFL
{
public:
    bool LocalOnly() const
    {
        return m_FaceFlag >> 2 & 1;
    }

    u16 Gender() const
    {
        return m_Flag >> 14 & 1;
    }

    u16 BirthMonth() const
    {
        return m_Flag >> 10 & 0xF;
    }

    u16 BirthDay() const
    {
        return m_Flag >> 5 & 0x1F;
    }

    u16 FavoriteColor() const
    {
        return m_Flag >> 1 & 0xF;
    }

    bool FavoriteMii() const
    {
        return m_Flag & 1;
    }

    const u16* Name() const
    {
        return m_Name;
    }

    s32 Height() const
    {
        return m_Height;
    }

    s32 Build() const
    {
        return m_Build;
    }

    u16 FaceType() const
    {
        return m_FaceFlag >> 13;
    }

    u16 FacelineColor() const
    {
        return m_FaceFlag >> 10 & 7;
    }

    u16 FaceLineAndMake() const
    {
        return m_FaceFlag >> 6 & 0xF;
    }

    u16 HairType() const
    {
        return m_HairFlag >> 9;
    }

    u16 HairColor() const
    {
        return m_HairFlag >> 6 & 7;
    }

    u16 HairDir() const
    {
        return m_HairFlag >> 5 & 1;
    }

    u16 EyebrowType() const
    {
        return m_EyebrowFlag[0] >> 11;
    }

    u16 EyebrowRotate() const
    {
        return m_EyebrowFlag[0] >> 6 & 0x1F;
    }

    u16 EyebrowColor() const
    {
        return m_EyebrowFlag[1] >> 13;
    }

    u16 EyebrowScale() const
    {
        return m_EyebrowFlag[1] >> 9 & 0xF;
    }

    u16 EyebrowPosition() const
    {
        return m_EyebrowFlag[1] >> 4 & 0x1F;
    }

    u16 EyebrowSpacing() const
    {
        return m_EyebrowFlag[1] & 0xF;
    }

    u16 EyeType() const
    {
        return m_EyeFlag[0] >> 10;
    }

    u16 EyeRotate() const
    {
        return m_EyeFlag[0] >> 5 & 0x1F;
    }

    u16 EyePosition() const
    {
        return m_EyeFlag[0] & 0x1F;
    }

    u16 EyeColor() const
    {
        return m_EyeFlag[1] >> 13;
    }

    u16 EyeScale() const
    {
        return m_EyeFlag[1] >> 9 & 0xF;
    }

    u16 EyeSpacing() const
    {
        return m_EyeFlag[1] >> 5 & 0xF;
    }

    u16 NoseType() const
    {
        return m_NoseFlag >> 12;
    }

    u16 NoseScale() const
    {
        return m_NoseFlag >> 8 & 0xF;
    }

    u16 NosePosition() const
    {
        return m_NoseFlag >> 3 & 0x1F;
    }

    u16 MouthType() const
    {
        return m_MouthFlag >> 11;
    }

    u16 MouthColor() const
    {
        return m_MouthFlag >> 9 & 3;
    }

    u16 MouthScale() const
    {
        return m_MouthFlag >> 5 & 0xF;
    }

    u16 MouthPosition() const
    {
        return m_MouthFlag & 0x1F;
    }

    u16 MustacheType() const
    {
        return m_BeardFlag >> 14;
    }

    u16 BeardType() const
    {
        return m_BeardFlag >> 12 & 3;
    }

    u16 BeardColor() const
    {
        return m_BeardFlag >> 9 & 7;
    }

    u16 MustacheScale() const
    {
        return m_BeardFlag >> 5 & 0xF;
    }

    u16 MustachePosition() const
    {
        return m_BeardFlag & 0x1F;
    }

    u16 GlassType() const
    {
        return m_GlassFlag >> 12;
    }

    u16 GlassColor() const
    {
        return m_GlassFlag >> 9 & 7;
    }

    u16 GlassScale() const
    {
        return m_GlassFlag >> 5 & 0xF;
    }

    u16 GlassPosition() const
    {
        return m_GlassFlag & 0x1F;
    }

    u16 MoleType() const
    {
        return m_MoleFlag >> 15;
    }

    u16 MoleScale() const
    {
        return m_MoleFlag >> 11 & 0xF;
    }

    u16 MolePositionY() const
    {
        return m_MoleFlag >> 6 & 0x1F;
    }

    u16 MolePositionX() const
    {
        return m_MoleFlag >> 1 & 0x1F;
    }

public:
    u16 m_Flag;
    u16 m_Name[10];
    u8  m_Height;
    u8  m_Build;
    u8  m_CreatorID[4];
    u8  m_SystemID[4];
    u16 m_FaceFlag;
    u16 m_HairFlag;
    u16 m_EyebrowFlag[2];
    u16 m_EyeFlag[2];
    u16 m_NoseFlag;
    u16 m_MouthFlag;
    u16 m_GlassFlag;
    u16 m_BeardFlag;
    u16 m_MoleFlag;
};
NN_STATIC_ASSERT_IS_POD(FFLiMiiDataCoreRFL);
NN_STATIC_ASSERT(sizeof(FFLiMiiDataCoreRFL) == 0x36);

#endif // FFLI_MIIDATA_CORE_H_
