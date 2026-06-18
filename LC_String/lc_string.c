#include "lc_string.h"

void LC_String_Demo(void)
{
    FUNC_ENTRY();
    LOG_INFO("LC_STRING_DEBUG = %d", LC_STRING_DEBUG);
    if (!LC_STRING_DEBUG)
    {
        FUNC_EXIT();
        return;
    }

    intToRoman(1234);

    UINT32 returnSize = 0;
    generateParenthesis(5, &returnSize);

    letterCombinations("234", &returnSize);

    complexNumberMultiply("1+-1i", "1+-1i");

    char words[5][10] = {"abcd", "aabb", "ccvv", "qweq", "sadw"};
    findAndReplacePattern(words, ARRAY_SIZE(words), "qqww", &returnSize);

    FUNC_EXIT();
}