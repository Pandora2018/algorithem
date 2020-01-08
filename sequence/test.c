/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : test.c
#   Last Modified : 2020-01-08 15:43
#   Describe      :
#
# ====================================================*/

#include <stdio.h>
#include "sequence.h"

int main(void)
{
	seqList testList;	
	bool res = initList(testList);
	
	if (res)
		printf("sequence list initialization OK!\n");
	else
		printf("sequence list initialization FAIL!\n");

	return 0;
}
