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
#endif //MYLEETCODE_CBASE_H
