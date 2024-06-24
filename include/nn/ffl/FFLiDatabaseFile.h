#ifndef FFLI_DATABASE_FILE_H_
#define FFLI_DATABASE_FILE_H_

#include <nn/ffl/FFLiDatabaseFileHidden.h>
#include <nn/ffl/FFLiDatabaseFileOfficial.h>

/**
 * @brief A combination structure containing a @ref FFLIDatabaseFileOfficial and a @ref FFLiDatabaseFileHidden.
 * 
 */
struct FFLiDatabaseFile
{
    FFLiDatabaseFileOfficial    official;
    FFLiDatabaseFileHidden      hidden;
};
NN_STATIC_ASSERT(sizeof(FFLiDatabaseFile) == 0x4E440);

#endif // FFLI_DATABASE_FILE_H_
