/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : sequence.c
#   Last Modified : 2020-01-31 19:02
#   Describe      : sequence list algorithem
#
# ====================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sequence.h"

bool initList(seqList *L)
{
	unsigned int maxSize;
	printf("sequence list maxsize : ");
	scanf("%u", &maxSize);

	L->elem = (ElemType *)malloc(sizeof(ElemType) * maxSize);
	if (! L->elem) return false;

	L->length = 0;

	return true;
}


unsigned int listLength(seqList *L)
{
	return (L->length);
}


bool getElem(seqList list, int i, ElemType *e)
{
	if (i >= 1 && i <= list.length)
	{
		*e = list.elem[i - 1];
		return true;
	} else
	{
		printf("index not valid\v");
		return false;
	}
}


bool clearList(seqList list)
{
	if (list.length != 0)
		list.length = 0;
	else
	{
		printf("sequence list not element.\n");
		return false;
	}

	return true;
}


bool insertElemOfList(seqList *L, int pos, ElemType e)
{
	unsigned int length = listLength(L);

	if (pos < 1 || pos > length + 1) return false;
	
	for (int index=length;index>=pos;index--)
		L->elem[index] = L->elem[index-1];

	L->elem[pos-1] = e;
	(L->length)++;

	return true;
}


bool delElemOfList(seqList *L, int pos, ElemType *e)
{
	unsigned int len = listLength(L);

	if (pos < 1 || pos > len)
	{
		printf("Position Over Flow!\n");
		exit(-2);
	}

	ElemType *start = L->elem + pos - 1;
	*e = *start;
	ElemType *end = L->elem + len - 1;

	for (++start;start<=end;++start)
		*(start - 1) = *start;
	
	--(L->length);

	return true;
}



bool destoryList(seqList list)
{
	if (list.elem)
	{
		free(list.elem);
		printf("sequence list not exist.\n");
	} else
	{
		printf("sequence list not exist.\n");
		return false;	
	}

	return true;
}
