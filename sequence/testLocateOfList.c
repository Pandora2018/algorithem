/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : testLocateOfList.c
#   Last Modified : 2020-02-03 20:40
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include "sequence.h"


bool compare(ElemType e1, ElemType e2)
{
	return (e1 > e2 ? true : false);
}


void visit(seqList *L)
{
	unsigned int length = listLength(L);

	for (int in = 0; in < length; in++)
		printf("%d ", L->elem[in]);

	putchar('\n');
	
	return;
}


int main(void)
{
	seqList list;
	seqList *L = &list;

	if (! initList(L))
		printf("List Init Fail\n");

	for (int in = 1; in <= 10; in++)
		insertElemOfList(L, in, in * 2);

	visit(L);

	int elem = 10;
	int pos;

	while ((pos = locateOfList(L, elem, &compare)) != NOTF)
	{
		printf("%d position : %d\n", elem, pos);

		printf("Locate Element : ");
		scanf("%d", &elem);
	}

	return 0;
}
