/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : testIntersectionOfList.c
#   Last Modified : 2020-02-06 11:11
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "seqList.h"


void visit(seqList *L)
{
	unsigned int length = lengthOfList(L);

	for (int in = 0; in < length; in++)
		// printf("%d ", L->elem[in]);
		fprintf(stdout, "%d ", L->elem[in]);

	putchar('\n');
	
	return;
}


int main(void)
{
	seqList listA, listB, res;
	seqList *La, *Lb, *r;
	La = &listA, Lb = &listB, r = &res;

	if (! (initList(La) && initList(Lb) && initList(r)))
		printf("List Init Fail\n");

	srand((unsigned int)time(NULL));

	for (int in = 1; in <= 10; in++)
		insertElemOfList(La, in, rand() % 10 + 1);

	for (int in = 1; in <= 8; in++)
		insertElemOfList(Lb, in, rand() % 10 + 1);

	visit(La);
	visit(Lb);

	if (intersectionOfList(La, Lb, r) != NOTELEM) visit(r);
	
	/*
	 * intersectionOfList(La, Lb, r);
	 * visit(r);
	 */

	destoryList(La);
	destoryList(Lb);
	destoryList(r);

	return 0;
}
