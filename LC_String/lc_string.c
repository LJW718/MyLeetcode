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

    myAtoi("42");
    myAtoi("   -042");
    myAtoi("1337c0d3");
    myAtoi("0-1");
    myAtoi("words and 987");
    myAtoi("+-12");
    myAtoi("   +0 123");
    myAtoi("   888895936875");
    myAtoi("   -124579624584");
    FUNC_EXIT();
}