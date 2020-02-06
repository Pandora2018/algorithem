/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : testGetPositionOfList.c
#   Last Modified : 2020-02-01 18:44
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
	
	visit(L);
	putchar('\n');

	int elem;
	
	printf("Get elem : ");
	scanf("%d", &elem);
	
	int pos = getPositionOfList(L, elem);

	if (pos != -1)
		printf("%d position : %d\n", elem, pos);
	else
		printf("Not elem : %d\n", elem);



	destoryList(L);

	return 0;
}
