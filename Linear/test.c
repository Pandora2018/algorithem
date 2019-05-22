/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : test.c
#   Last Modified : 2019-05-22 20:43
#   Describe      :
#
# ====================================================*/

#include <stdio.h>
#include "sequence.h"

int main(void)
{
	double v;
	sequence test;
	
	InitialList(&test);
	
	printf("Enter a value : ");
	scanf("%lf", &v);

	for (int i = 0; i < size; ++i)
		test.list[i] = i * 2.00;

	printf("length : %u\n", GetLength(test));

	for (int i = 0; i < size; ++i)
		printf("%.2f ", test.list[i]);

	/*
	 * if (ListIsEmpty(test))
	 *     printf("test is empty.\n");
	 */

	DeleteElem(&test, 10, &v);

	printf("Elem count : %u\n", GetElemCnt(test));
	
	return 0;
}
