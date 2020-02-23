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


void visit(seqList* const L)
{
	unsigned int length = lengthOfList(L);

	for (int in = 0; in < length; in++)
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

	for (int in = 1; in <= 18; in++)
		insertElemOfList(Lb, in, rand() % 10 + 1);

	printf("1st seqList: ");
	visit(La);
	printf("2st seqList: ");
	visit(Lb);

	printf("intersectionOfList: ");
	if (intersectionOfList(La, Lb, r) != NOTELEM)
		visit(r);

	fprintf(stdout, "intersectionOfList count: %u\n",
			r->length);
	
	destoryList(La);
	destoryList(Lb);
	destoryList(r);

	return 0;
}
