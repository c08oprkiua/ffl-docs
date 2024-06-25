#ifndef FFLI_MIDDLE_DB_H_
#define FFLI_MIDDLE_DB_H_

#include <nn/ffl/FFLAge.h>
#include <nn/ffl/FFLGender.h>
#include <nn/ffl/FFLMiddleDBType.h>
#include <nn/ffl/FFLRace.h>
#include <nn/ffl/FFLResult.h>

class FFLiMiddleDB;

/**
 * @brief Alias for FFLiMiddleDB::GetBufferSize
 * 
 * @param miiDataNum the amount of Miis in database.
 * @return u32 the buffer size of the database.
 */
u32 FFLiGetMiddleDBBufferSize(u16 miiDataNum);

/**
 * @brief Alias for pMiddleDB->Init();
 * 
 * @param pMiddleDB Pointer to the database to initialize.
 * @param type The type of database this class will be.
 * @param pMiiData The array of FFLiMiiDataOfficial classes to make a database out of.
 * @param miiDataNum The size of the array this database is initalizing.
 */
void FFLiInitMiddleDB(FFLiMiddleDB* pMiddleDB, FFLMiddleDBType type, void* pMiiData, u16 miiDataNum);

/**
 * @brief Update a database. How it is updated will depend on its type.
 * 
 * @param pMiddleDB The database to update.
 * @return FFLResult 
 */
FFLResult FFLiUpdateMiddleDB(FFLiMiddleDB* pMiddleDB);

void FFLiSetMiddleDBHiddenMask(FFLiMiddleDB* pMiddleDB, FFLGender gender);
void FFLiSetMiddleDBRandomMask(FFLiMiddleDB* pMiddleDB, FFLGender gender, FFLAge age, FFLRace race);

s32 FFLiGetMiddleDBSize(const FFLiMiddleDB* pMiddleDB);             // Deleted in NSMBU

s32 FFLiGetMiddleDBStoredSize(const FFLiMiddleDB* pMiddleDB);

FFLMiddleDBType FFLiGetMiddleDBType(const FFLiMiddleDB* pMiddleDB); // Deleted in NSMBU

// --------------------------------------------------------------------------

#define FFLI_MIDDLE_DB_PARAM_SIZE   (4)

class FFLiMiddleDBHiddenParam
{
public:
    void Init();

    FFLGender Gender() const
    {
        return FFLGender(m_Gender);
    }

    void Set(FFLGender gender);

private:
    u8  m_Gender;
    u8  m_Padding[3];
};
NN_STATIC_ASSERT_IS_POD(FFLiMiddleDBHiddenParam);
NN_STATIC_ASSERT(sizeof(FFLiMiddleDBHiddenParam) == FFLI_MIDDLE_DB_PARAM_SIZE);

class FFLiMiddleDBRandomParam
{
public:
    void Init();

    FFLGender Gender() const
    {
        return FFLGender(m_Gender);
    }

    FFLAge Age() const
    {
        return FFLAge(m_Age);
    }

    FFLRace Race() const
    {
        return FFLRace(m_Race);
    }

    void Set(FFLGender gender, FFLAge age, FFLRace race);

private:
    u8  m_Gender;
    u8  m_Age;
    u8  m_Race;
    u8  m_Padding[1];
};
NN_STATIC_ASSERT_IS_POD(FFLiMiddleDBRandomParam);
NN_STATIC_ASSERT(sizeof(FFLiMiddleDBRandomParam) == FFLI_MIDDLE_DB_PARAM_SIZE);

class FFLiMiddleDBNetParam
{
public:
    void Init();

private:
    u16 _0;
    u8  m_Padding[2];
};
NN_STATIC_ASSERT_IS_POD(FFLiMiddleDBNetParam);
NN_STATIC_ASSERT(sizeof(FFLiMiddleDBNetParam) == FFLI_MIDDLE_DB_PARAM_SIZE);

struct  FFLiCharInfo;
class   FFLiMiiDataHidden;
class   FFLiMiiDataOfficial;

/**
 * @brief A class that stores and manages a database of Miis.
 * 
 * Databases can be one of several types. The type dictates what 
 * occurs when the database is updated through one of the various 
 * updating functions found throughout FFL.
 * 
 */
class FFLiMiddleDB
{
public:
    /**
     * @brief Get the size of a num sized array of FFLiMiiDataOfficial classes.
     * 
     * @param num the array size.
     * @return u32 The buffer allocation size.
     */
    static u32 GetBufferSize(u16 num);

public:
    /**
     * @brief Initialize a database.
     * 
     * @param type The type of database this class will be.
     * @param pData The array of FFLiMiiDataOfficial classes to make a database out of.
     * @param num The size of the array this database is initalizing.
     */
    void Init(FFLMiddleDBType type, void* pData, u16 num);

    void SetHiddenParam(FFLGender gender);
    void SetRandomParam(FFLGender gender, FFLAge age, FFLRace race);

    //Get the amount of Miis this database can store.
    s32 Size() const;
    //Get the amount of Miis currently stored in the database.
    s32 StoredSize() const;

    //Get what FFLMiddleDBType database this is.
    FFLMiddleDBType Type() const;

    //Clear the database.
    void ClearData();

    const FFLiMiddleDBHiddenParam& HiddenParam() const;
    const FFLiMiddleDBRandomParam& RandomParam() const;

    //Returns if the database is full or not.
    bool IsFull() const;

    /**
     * @brief Add a Mii to the database.
     * 
     * @param charInfo The mii to add.
     */
    void Add(const FFLiCharInfo& charInfo);

    /**
     * @brief Add a Mii to the database.
     * 
     * @param miiDataHidden The mii to add.
     */
    void Add(const FFLiMiiDataHidden& miiDataHidden);

    //Get the Mii at the index.
    const FFLiMiiDataOfficial& Get(u16 index) const;
    //Get the Mii at the index.
    FFLiMiiDataOfficial& Get(u16 index);

    /**
     * @brief Get the FFLiCharInfo of a Mii at the position index in the database.
     * 
     * @param pCharInfo A pointer to the FFLiCharInfo to put the retrieved data into.
     * @param index The index in the database to retrieve from.
     * @return FFLResult FFL_RESULT_ERROR if you request a Mii outside of the bounds of the 
     * database, else FFL_RESULT_OK.
     */
    FFLResult GetCharInfo(FFLiCharInfo* pCharInfo, u16 index) const;

private:
    u32                     m_Magic;
    //The type of database this is.
    FFLMiddleDBType         m_Type;
    //The array of Miis that this database uses, ie. the "literal" database.
    FFLiMiiDataOfficial*    m_pMiiDataOfficial;
    //The amount of Miis stored in the database.
    u16                     m_Size;
    //The amount of Miis this database can store.
    u16                     m_StoredSize;
    union
    {
        u8                      m_ParamData[FFLI_MIDDLE_DB_PARAM_SIZE];
        
        FFLiMiddleDBHiddenParam m_HiddenParam;
        FFLiMiddleDBRandomParam m_RandomParam;
        FFLiMiddleDBNetParam    m_NetParam;
    };
};
NN_STATIC_ASSERT_IS_POD(FFLiMiddleDB);
NN_STATIC_ASSERT(sizeof(FFLiMiddleDB) == 0x14);

#endif // FFLI_MIDDLE_DB_H_
