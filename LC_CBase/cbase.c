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

/* 
在 C 语言中，对于单个变量（如 int），其内部字节的“地址”永远是“从低到高”增长的，而“字节排列顺序”取决于大小端。

地址增长方向（硬件/栈方向）：指内存地址编号是变大还是变小。

栈（Stack）：通常向下增长（地址从高到低）。

堆（Heap）/ 全局区 / 数组：通常向上增长（地址从低到高）。

固定规律：但在同一个变量内部（比如一个 int 占用的 4 个字节），它们的地址编号一定是连续且递增的（低地址 -> 高地址）。这是 CPU 内存寻址的基本物理规则。

字节增长方向（大小端 Endianness）：指在多字节变量中，低地址处存放的是数据的低位还是高位。
*/

// 检测系统大小端函数
int BigLittleEndian(void)
{
    // 用 0x0001 做测试，其内存分布为：
    // 大端：00 01 (高位字节在前)
    // 小端：01 00 (低位字节在前)
    MY_UNION myUnion;
    myUnion.x = 0x0001;
    LOG_INFO("Memory(low address ---> high address)");
    LOG_INFO("Data (high bytes  ---> low bytes)" );
    LOG_INFO("Data myUnion.x[short] hex = 0x%04X", myUnion.x);
    LOG_INFO("Data myUnion.y[char] hex = 0x%02X", myUnion.y);
    if (myUnion.y == 1)
    {
        // 小端模式：高地址存放高字节，低地址存放低字节，高高低低
        LOG_INFO("Little Endian —— low address store low bytes.");
    }
    else
    {
        // 大端模式：高地址存放低字节，低地址存放高字节，高低低高
        LOG_INFO("Big Endian —— low address store high bytes.");
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
    LOG_INFO("LC_CBASE_DEBUG = %d", LC_CBASE_DEBUG);
    if (!LC_CBASE_DEBUG)
    {
        FUNC_EXIT();
        return;
    }

    BigLittleEndian();

    BitFieldTest();

    BitShiftTest();

    TestFuncPtr(5, 10);
    FUNC_EXIT();
}
