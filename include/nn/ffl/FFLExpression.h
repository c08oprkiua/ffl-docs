#ifndef FFL_EXPRESSION_H_
#define FFL_EXPRESSION_H_

#include <nn/ffl/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum FFLExpression
{
    FFL_EXPRESSION_NORMAL,
    FFL_EXPRESSION_SMILE,
    FFL_EXPRESSION_ANGER,
    FFL_EXPRESSION_SORROW,
    FFL_EXPRESSION_SURPRISE,
    FFL_EXPRESSION_BLINK,
    FFL_EXPRESSION_OPEN_MOUTH,
    FFL_EXPRESSION_HAPPY_OPEN_MOUTH,
    FFL_EXPRESSION_ANGER_OPEN_MOUTH,
    FFL_EXPRESSION_SORROW_OPEN_MOUTH,
    FFL_EXPRESSION_SURPRISE_OPEN_MOUTH,
    FFL_EXPRESSION_BLINK_OPEN_MOUTH,
    FFL_EXPRESSION_WINK_LEFT,
    FFL_EXPRESSION_WINK_RIGHT,
    FFL_EXPRESSION_WINK_LEFT_OPEN_MOUTH,
    FFL_EXPRESSION_WINK_RIGHT_OPEN_MOUTH,
    FFL_EXPRESSION_LIKE_WINK_LEFT,
    FFL_EXPRESSION_LIKE_WINK_RIGHT,
    FFL_EXPRESSION_FRUSTRATED,
    
    FFL_EXPRESSION_MAX = 19,
}
FFLExpression;

#ifdef __cplusplus
}
#endif

#endif // FFL_EXPRESSION_H_
