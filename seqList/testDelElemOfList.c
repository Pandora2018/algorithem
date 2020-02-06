/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : testDelElemOfList.c
#   Last Modified : 2020-01-31 19:02
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"


void visit(seqList *L)
{
	unsigned int len = listLength(L);

	for (int in=0;in<len;++in)
		printf("%d ", L->elem[in]);

	return;
}


int main(void)
{
	seqList list;
	seqList *L = &list;

	if (! initList(L))
	{
		printf("sequence list init false!");
		exit(-1);
	}

	// insert element to list
	for (int in=1;in<=6;++in)
		insertElemOfList(L, in, in * 2);
	
	unsigned int s_len = listLength(L);
	printf("s_len : %u\n", s_len);

	// delete element from list
	ElemType elem;
	ElemType *e = &elem;
	int delPos;
	unsigned int e_len = listLength(L);

	while (e_len)
	{
		visit(L);
		putchar('\n');

		printf("Delete Position : ");
		scanf("%d", &delPos);

		delElemOfList(L, delPos, e);
		printf("-----------\ndelete element : %d\n------------\n", *e);

		e_len = listLength(L);

		if (0 == e_len)
		{
			printf("List is empty\n");
			break;
		}

		printf("e_len : %u\n", listLength(L));

		puts("===================");
	}

	return 0;
}
