#ifndef FFLI_RANDOM_CONTEXT_H_
#define FFLI_RANDOM_CONTEXT_H_

#include <nn/ffl/types.h>

/**
 * @brief A random number generator for FFL.
 * 
 */
class FFLiRandomContext
{
public:
    /**
     * @brief Initalize the context.
     * 
     * @param seed A seed to initialize the context with.
     */
    void Init(u32 seed);

    /**
     * @brief Get a random unsigned 16 bit integer.
     * 
     * @param max ?????
     * @return A randomized 16 bit unsigned integer.
     */
    u16 Random(u16 max);

private:
    u32 m_RndX;
    u32 m_RndY;
    u32 m_RndZ;
};
NN_STATIC_ASSERT(sizeof(FFLiRandomContext) == 0xC);

#endif // FFLI_RANDOM_CONTEXT_H_
