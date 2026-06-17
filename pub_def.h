//
// Created by Administrator on 2020/6/25 0025.
//公共头文件，常用的宏在此定义

#ifndef __PUBLIC_DEFINE_H__
#define __PUBLIC_DEFINE_H__

#include <stddef.h>
#include <stdlib.h>

// 计算数组元素个数
#define ARRAY_SIZE(nums) ((sizeof(nums)) / (sizeof(nums[0])))

#define CLEAR_ARRAY(nums, numsSize) do { \
    for (int i = 0; i < numsSize; i++) { \
        nums[i] = 0;                     \
    }                                    \
} while(0);                              \

// 日志打印接口
#define TRACE_PRINT(fmt, ...) \
    fprintf(stderr, "[TRACE][%s:%d][%s]" fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__)

#define FUNC_ENTRY() \
    fprintf(stderr, "[ENTRY][%s:%d][%s]\n", __FILE__, __LINE__, __func__)

#define FUNC_EXIT() \
    fprintf(stderr, "[EXIT][%s:%d][%s]\n", __FILE__, __LINE__, __func__)

#endif
