//
// Created by Administrator on 2022/9/12.
//

#include "cbase.h"

typedef union MY_UNION {
	short x;
	char y;
}MY_UNION;

/**************************************函数指针******************************************/
typedef void (*Print)(UINT8 res);
typedef UINT8 (*Sum)(UINT8 a, UINT8 b);

typedef struct {
    Print pPrint;
    Sum pSum;
}FUNC_PTR_T;

// 检测系统大小端函数
int BigLittleEndian(void)
{
    MY_UNION myUnion;
    myUnion.x = 1;
    if (myUnion.y == 1)
    {
        // 大端模式：高地址存放低字节，低地址存放高字节，高低低高
        // 高字节-------低字节
        // 12   34   56   78
        // 低地址-------高地址
        LOG_DEBUG("Big Endian");
    }
    else
    {
        // 小端模式：高高低低
        LOG_DEBUG("Little Endian");
    }
    return 0;
}

typedef struct _BIT_FIELD_STRUCT
{
    UINT8 a : 1;
    UINT8 b : 3;
    UINT8 c : 4;
    UINT8 d;
} BIT_FIELD_STRUCT;

// 位域测试函数
void BitFieldTest(void)
{
    BIT_FIELD_STRUCT xx;
    LOG_DEBUG("sizeof(BIT_FIELD_STRUCT) = %d", (UINT32)sizeof(BIT_FIELD_STRUCT));

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverflow"
    // 故意触发溢出测试
    xx.a = (UINT8)2;
    xx.b = (UINT8)8;
    xx.c = (UINT8)17;
    xx.d = 20;
#pragma GCC diagnostic pop

    LOG_DEBUG("abc out of bounds: a = %d, b = %d, c = %d, d = %d", xx.a, xx.b, xx.c, xx.d);
    xx.a = 1;
    xx.b = 7;
    xx.c = 15;
    xx.d = 20;
    LOG_DEBUG("abc not out of bounds: a = %d, b = %d, c = %d, d = %d", xx.a, xx.b, xx.c, xx.d);
}

// 移位运算测试函数
void BitShiftTest()
{
    UINT8 arr1[4] = {0x12, 0x34, 0x56, 0x78};
    UINT16 OI = (UINT16)(arr1[0] << 8);
    OI |= (UINT16)(arr1[1]);
    LOG_DEBUG("OI = %x", OI);
}

/**************************************函数指针******************************************/
void PrintRes(UINT8 res)
{
    LOG_DEBUG("res = %d", res);
}

UINT8 SumXY(UINT8 x, UINT8 y)
{
    LOG_DEBUG("x=%d, y=%d", x, y);
    return x + y;
}

const FUNC_PTR_T gFuncPtr[] = {
    {PrintRes, SumXY},
};

void TestFuncPtr(UINT8 a, UINT8 b)
{
    UINT8 num = ARRAY_SIZE(gFuncPtr);
    for (UINT8 i = 0; i < num; i++)
    {
        Print prt = gFuncPtr[i].pPrint;
        Sum summ = gFuncPtr[i].pSum;
        UINT8 res = summ(a, b);
        prt(res);
    }
}

void LC_CBase_Demo(void)
{
    FUNC_ENTRY();
    BigLittleEndian();

    BitFieldTest();

    BitShiftTest();

    TestFuncPtr(5, 10);
    FUNC_EXIT();
}
