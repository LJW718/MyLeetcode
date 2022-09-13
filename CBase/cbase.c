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
