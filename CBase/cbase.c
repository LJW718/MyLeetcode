//
// Created by Administrator on 2022/9/12.
//

#include <stdio.h>
#include "cbase.h"

int BigLittleEndian() {
	MY_UNION myUnion;
	myUnion.x = 1;
	if (myUnion.y == 1) {
		// 大端模式：高地址存放低字节，低地址存放高字节，高低低高
		// 高字节-------低字节
		// 12   34   56   78
		// 低地址-------高地址
		printf("Big Endian\n");
	} else {
		// 小端模式：高高低低
		printf("Little Endian\n");
	}
	return 0;
}

typedef struct _BIT_FIELD_STRUCT {
    UINT8 a:1;
    UINT8 b:3;
    UINT8 c:4;
    UINT8 d;
}BIT_FIELD_STRUCT;

void BitFieldTest() {
    printf("BitFieldTest:\n");
    BIT_FIELD_STRUCT xx;
    printf("sizeof(BIT_FIELD_STRUCT) = %llu\n", sizeof(BIT_FIELD_STRUCT));
    xx.a = 2;
    xx.b = 8;
    xx.c = 17;
    xx.d = 20;
    printf("abc out of bounds: a = %d, b = %d, c = %d, d = %d\n", xx.a, xx.b, xx.c, xx.d);
    xx.a = 1;
    xx.b = 7;
    xx.c = 15;
    xx.d = 20;
    printf("abc not out of bounds: a = %d, b = %d, c = %d, d = %d\n", xx.a, xx.b, xx.c, xx.d);
}

void BitShiftTest() {
    printf("BitShiftTest:\n");
    UINT8 arr1[4] = {0x12, 0x34, 0x56, 0x78};
    UINT16 OI = (UINT16)(arr1[0] << 8);
    OI |= (UINT16)(arr1[1]);
    printf("OI = %x\n", OI);
}

/**************************************函数指针******************************************/
void PrintRes(UINT8 res) {
    printf("res = %d\n", res);
}

UINT8 SumXY(UINT8 x, UINT8 y) {
    return x + y;
}

const FUNC_PTR_T gFuncPtr[MAX_NUM] = {
        {PrintRes, SumXY},
};

void TestFuncPtr(UINT8 a, UINT8 b) {
    UINT8 num = sizeof(gFuncPtr) / sizeof(gFuncPtr[0]);
    for (UINT8 i = 0; i < num; i++) {
        Print prt = gFuncPtr[i].pPrint;
        Sum summ = gFuncPtr[i].pSum;
        UINT8 res = summ(a, b);
        printf("TestFuncPtr:\n");
        prt(res);
    }
}

