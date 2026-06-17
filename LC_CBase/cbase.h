//
// Created by Administrator on 2022/9/12.
//

#ifndef MYLEETCODE_CBASE_H
#define MYLEETCODE_CBASE_H

#ifndef __MY_UINT__
#define __MY_UINT__
#define UINT8 unsigned char
#define UINT16 unsigned short int
#define UINT32 unsigned int
#define UINT64 unsigned long long
#endif

typedef union MY_UNION {
	short x;
	char y;
}MY_UNION;

// 检测系统大小端函数
int BigLittleEndian();

// 位域测试函数
void BitFieldTest();

// 移位运算测试函数
void BitShiftTest();

/**************************************函数指针******************************************/
#define MAX_NUM 10
typedef void (*Print)(UINT8 res);
typedef UINT8 (*Sum)(UINT8 a, UINT8 b);

typedef struct {
    Print pPrint;
    Sum pSum;
}FUNC_PTR_T;

void TestFuncPtr(UINT8 a, UINT8 b);

#endif //MYLEETCODE_CBASE_H
