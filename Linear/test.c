/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : test.c
#   Last Modified : 2019-05-23 10:03
#   Describe      :
#
# ====================================================*/

#include <stdio.h>
#include "sequence.h"

int main(void)
{
	double v;
	sequence test;

	printf("Enter value : ");
	scanf("%lf", &v);
	
	InitialList(&test);

	for (int i = 0; i < size; ++i)
	{
		test.list[i] = i * 2.00;
		test.cnt++;
	}

	// test GetLength
	printf("length : %u\n", GetLength(test));

	// test GetElem
	GetElem(test, 15, &v);
	printf("GetElem(10) : %.2f\n", v);

	// test LocateElem
	unsigned int pos;
	if (LocateElem(test, 34.00, &pos))
		printf("pos : %u\n", pos);
	else
		printf("not find.\n");

	// Traveal linear list
	for (int i = 0; i < size; ++i)
		printf("%.2f ", test.list[i]);

	// test DeleteElem
	DeleteElem(&test, 20, &v);
	putchar('\n');
	printf("DeleteElem : %.2f\n", v);

	DeleteElem(&test, 23, &v);
	printf("DeleteElem : %.2f\n", v);

	putchar('\n');

	for (int i = 0; i < size; ++i)
		printf("%.2f ", test.list[i]);

	putchar('\n');

	// test GetLength
	printf("Elem count : %u\n", GetElemCnt(test));

	if (! IsFull(test))
	{
		InsertElem(&test, 20, v);
		/* InsertElem(&test, 21, v); */
		/*
		 * GetElem(test, 10, &v);
		 * printf("v : %.2f\n", v);
		 */
		/* printf("test.list[20] : %.2f\n", test.list[20]); */
	}

	for (int i = 0; i < size; ++i)
		printf("%.2f ", test.list[i]);

	putchar('\n');

	printf("Elem count : %u\n", GetElemCnt(test));

	CleanList(&test);
	
	return 0;
}
