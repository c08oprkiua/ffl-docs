#ifndef FFLI_MIIDATA_H_
#define FFLI_MIIDATA_H_

#include <nn/ffl/FFLResult.h>

struct  FFLiCharInfo;
class   FFLiMiiDataCore;
struct  FFLiMiiDataCoreRFL;
class   FFLiMiiDataOfficial;
struct  FFLiStoreDataCFL;

/**
 * @brief Convert a @ref MiiDataCoreRFL to a @ref MiiDataCore
 * 
 * @param pMiiDataCore 
 * @param miiDataCoreRFL 
 * @param replaceName 
 * @return true 
 * @return false 
 */
bool FFLiMiiDataCoreRFL2MiiDataCore(FFLiMiiDataCore* pMiiDataCore, const FFLiMiiDataCoreRFL& miiDataCoreRFL, bool replaceName);

/**
 * @brief 
 * 
 * @param pCharInfo 
 * @param miiDataCoreRFL 
 * @param pCreatorName 
 * @param replaceName 
 * @return true 
 * @return false 
 */
bool FFLiMiiDataCoreRFL2CharInfo(FFLiCharInfo* pCharInfo, const FFLiMiiDataCoreRFL& miiDataCoreRFL, const u16* pCreatorName, bool replaceName);
// bool FFLiMiiDataOfficialRFL2CharInfo(FFLiCharInfo* pCharInfo, const FFLiMiiDataOfficialRFL& miiDataOfficialRFL, bool replaceName);   // Deleted in NSMBU

/**
 * @brief 
 * 
 * @param pMiiDataOfficial 
 */
void FFLiClearCreatorNameFromOfficial(FFLiMiiDataOfficial* pMiiDataOfficial);

/**
 * @brief 
 * 
 * @param pCharInfo 
 * @param miiDataCore 
 * @param pCreatorName 
 * @param resetBirthday 
 */
void FFLiMiiDataCore2CharInfo(FFLiCharInfo* pCharInfo, const FFLiMiiDataCore& miiDataCore, const u16* pCreatorName, bool resetBirthday);

/**
 * @brief 
 * 
 * @param pMiiDataCore 
 * @param charInfo 
 * @param resetBirthday 
 */
void FFLiCharInfo2MiiDataCore(FFLiMiiDataCore* pMiiDataCore, const FFLiCharInfo& charInfo, bool resetBirthday);

/**
 * @brief 
 * 
 * @param pCharInfo 
 * @param miiDataOfficial 
 */
void FFLiMiiDataOfficial2CharInfo(FFLiCharInfo* pCharInfo, const FFLiMiiDataOfficial& miiDataOfficial);

/**
 * @brief 
 * 
 * @param pMiiDataOfficial 
 * @param charInfo 
 * @param resetBirthday 
 */
void FFLiCharInfo2MiiDataOfficial(FFLiMiiDataOfficial* pMiiDataOfficial, const FFLiCharInfo& charInfo, bool resetBirthday);

/**
 * @brief 
 * 
 * @param pCharInfo 
 * @param storeDataCFL 
 * @return FFLResult 
 */
FFLResult FFLiStoreDataCFLToCharInfo(FFLiCharInfo* pCharInfo, const FFLiStoreDataCFL& storeDataCFL);

/**
 * @brief 
 * 
 * @param pStoreDataCFL 
 * @param pCharInfo 
 * @return FFLResult 
 */
FFLResult FFLiCharInfoToStoreDataCFL(FFLiStoreDataCFL* pStoreDataCFL, const FFLiCharInfo* pCharInfo);

/**
 * @brief 
 * 
 * @param storeDataCFL 
 * @param miiDataOfficial 
 */
void FFLiMiiDataOfficialToStoreDataCFL(FFLiStoreDataCFL& storeDataCFL, const FFLiMiiDataOfficial& miiDataOfficial);

// FFLiStoreDataCFLToStoreData(FFLiStoreData& storeData, const FFLiStoreDataCFL& storeDataCFL); // Deleted in NSMBU

#endif // FFLI_MIIDATA_H_
