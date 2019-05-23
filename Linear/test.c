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

#include "sequence.h"
#include <time.h>
#include <stdlib.h>

static void Travera(double *d, unsigned int cnt);

int main(void)
{
	double v[SIZE], tmp;
	sequence test;

	InitialList(&test);

	srand((unsigned int)time(NULL));

	for (int i = 0; i < SIZE; ++i)
	{
		test.list[i] = rand() % 30 + 1;
		test.cnt++;
	}

	TraversalList(test);

	int j = 0;
	unsigned int cnt = GetElemCnt(test);

	for (int i = 0; i < cnt; ++i)
	{
		if (GetElem(test, i, &tmp) && tmp >= 25.00)
			v[j++] = tmp;
	}

	putchar('\n');
	putchar('\n');

	Travera(v, j);

	putchar('\n');
	
	return 0;
}

static void Travera(double *d, unsigned int cnt)
{
	for (int i = 0; i < cnt; ++i)
		printf("%.2f ", *(d + i));

	return;
}
