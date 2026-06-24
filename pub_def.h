//
// Created by Administrator on 2020/6/25 0025.
//公共头文件，常用的宏在此定义

#ifndef __PUBLIC_DEFINE_H__
#define __PUBLIC_DEFINE_H__

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 模块调试宏， 1：开启， 0：关闭
#define LC_ARRAY_DEBUG                      (0)
#define LC_CBASE_DEBUG                      (0)
#define LC_LIST_DEBUG                       (0)
#define LC_MATH_DEBUG                       (0)
#define LC_STRING_DEBUG                     (0)
#define LC_UTHASH_DEBUG                     (1)

/*------------------------------ 自定义数据类型 ------------------------------ */
#ifndef __LC_TYPE_DEFINE__
#define __LC_TYPE_DEFINE__
#define UINT8 unsigned char
#define UINT16 unsigned short int
#define UINT32 unsigned int
#define UINT64 unsigned long long
#define INT8 char
#define INT16 short int
#define INT32 int
#define INT64 long long
#endif

/*------------------------------ 计算数组元素个数 ------------------------------ */
#define ARRAY_SIZE(nums) ((sizeof(nums)) / (sizeof(nums[0])))

#define CLEAR_ARRAY(nums, numsSize) do { \
    for (int i = 0; i < numsSize; i++) { \
        nums[i] = 0;                     \
    }                                    \
} while(0);                              \

/*------------------------------ 最大值、最小值 ------------------------------ */
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/* -------------------- 辅助宏：获取最后一个路径分隔符后的文件名 --------------------- */
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : \
                      (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__))

/* ------------------------------ 通用日志打印基宏 ------------------------------ */
#define LOG_PRINT(level, fmt, ...) \
    fprintf(stderr, "[%s][%s:%d][%s]" fmt "\n", level, __FILENAME__, __LINE__, __func__, ##__VA_ARGS__)

/* ------------------------------ 获取日志等级 ------------------------------ */
UINT8 get_loglevel(void);

/* ------------------------------ 四个等级日志宏 ------------------------------ */
typedef enum
{
    LOG_LVL_INVAILD = 0,
    LOG_LVL_ERROR,
    LOG_LVL_WARN,
    LOG_LVL_INFO,
    LOG_LVL_DEBUG,
    LOG_LVL_MAX,
}E_LOG_LVL;


#define LOG_ERROR(fmt, ...) do {                                                                    \
	if(get_loglevel() >= LOG_LVL_ERROR) {                                                           \
		LOG_PRINT("ERROR", fmt, ##__VA_ARGS__);                                                     \
	}                                                                                               \
} while(0)

#define LOG_WARN(fmt, ...) do {                                                                    \
	if(get_loglevel() >= LOG_LVL_WARN) {                                                           \
		LOG_PRINT("WARN", fmt, ##__VA_ARGS__);                                                     \
	}                                                                                               \
} while(0)

#define LOG_INFO(fmt, ...) do {                                                                    \
	if(get_loglevel() >= LOG_LVL_INFO) {                                                           \
		LOG_PRINT("INFO", fmt, ##__VA_ARGS__);                                                     \
	}                                                                                               \
} while(0)

#define LOG_DEBUG(fmt, ...) do {                                                                    \
	if(get_loglevel() >= LOG_LVL_DEBUG) {                                                           \
		LOG_PRINT("DEBUG", fmt, ##__VA_ARGS__);                                                     \
	}                                                                                               \
} while(0)

/* ------------------------------ 函数入口、出口宏 ------------------------------ */
#define FUNC_ENTRY()  LOG_DEBUG("enter")
#define FUNC_EXIT()   LOG_DEBUG("exit\n")

/* ------------------------------ 未使用参数处理宏 ------------------------------ */
#define UNUSED(Pragma) ((void)(Pragma))

#endif
