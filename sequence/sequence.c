/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : sequence.c
#   Last Modified : 2020-02-01 18:44
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


int getPositionOfList(seqList *L, ElemType e)
{
	// Get element postion,if not element,then return -1.
	unsigned int len = listLength(L);
	int pos = -1;
	
	for (int in=0;in<len;++in)
	{
		if (L->elem[in] == e)
		{
			pos = in + 1;
			break;
		}
	}

	return pos;
}



bool destoryList(seqList *L)
{
	if (L->elem)
	{
		free(L->elem);
		printf("Sequence List Destory.\n");
	} else
	{
		printf("Sequence List Not Exist.\n");
		return false;	
	}

	return true;
}
