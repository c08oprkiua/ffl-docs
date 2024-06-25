#ifndef FFL_MIDDLE_DB_H_
#define FFL_MIDDLE_DB_H_

#include <nn/ffl/FFLAge.h>
#include <nn/ffl/FFLGender.h>
#include <nn/ffl/FFLMiddleDBType.h>
#include <nn/ffl/FFLRace.h>
#include <nn/ffl/FFLResult.h>
#include <nn/ffl/FFLiMiddleDB.h>

#ifdef __cplusplus
extern "C" {
#endif

#define FFL_MIDDLE_DB_SIZE sizeof(FFLiMiddleDB)

typedef struct FFLMiddleDB
{
    union 
    {
        u8 data[FFL_MIDDLE_DB_SIZE];
        u32 data32[FFL_MIDDLE_DB_SIZE / sizeof(u32)];
    };
} 
FFLMiddleDB;
NN_STATIC_ASSERT(sizeof(FFLMiddleDB) == FFL_MIDDLE_DB_SIZE);


/**
 * @brief Get the allocation size of a miiDataNum sized array of 
 * FFLiMiiDataOfficial types.
 * 
 * @param miiDataNum The size of the array.
 * @return u32 The end byte size of the array.
 */
u32 FFLGetMiddleDBBufferSize(u16 miiDataNum);

/// @brief Alias for @ref FFLiInitMiddleDB which takes in a FFLMiddleDB instead of a FFLiMiddleDB.
void FFLInitMiddleDB(FFLMiddleDB* pMiddleDB, FFLMiddleDBType type, void* pMiiData, u16 miiDataNum);

/**
 * @brief Update the provided database.
 * 
 * This will fail if the FFLiManager singleton has not been initalized.
 * 
 * @param pMiddleDB The database to update
 * @return FFLResult 
 */
FFLResult FFLUpdateMiddleDB(FFLMiddleDB* pMiddleDB);

/**
 * @brief Get the database type of a database.
 * 
 * @param pMiddleDB The database to get the type of.
 * @return FFLMiddleDBType The type of the database.
 */
FFLMiddleDBType FFLGetMiddleDBType(const FFLMiddleDB* pMiddleDB);   // Deleted in NSMBU

/**
 * @brief 
 * 
 * @param pMiddleDB 
 * @return s32 
 */
s32 FFLGetMiddleDBSize(const FFLMiddleDB* pMiddleDB);               // Deleted in NSMBU

/**
 * @brief 
 * 
 * @param pMiddleDB 
 * @return s32 
 */
s32 FFLGetMiddleDBStoredSize(const FFLMiddleDB* pMiddleDB);

/**
 * @brief 
 * 
 * @param pMiddleDB 
 * @param gender 
 * @param age 
 * @param race 
 */
void FFLSetMiddleDBRandomMask(FFLMiddleDB* pMiddleDB, FFLGender gender, FFLAge age, FFLRace race);

/**
 * @brief 
 * 
 * @param pMiddleDB 
 * @param gender 
 */
void FFLSetMiddleDBHiddenMask(FFLMiddleDB* pMiddleDB, FFLGender gender);

#ifdef __cplusplus
}
#endif

#endif // FFL_MIDDLE_DB_H_