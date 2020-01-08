/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : sequence.c
#   Last Modified : 2020-01-08 16:34
#   Describe      : sequence list algorithem
#
# ====================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sequence.h"

bool initList(seqList list)
{
	unsigned int MAXSIZE;
	printf("sequence list maxsize : ");
	scanf("%u", &MAXSIZE);

	list.elem = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
	if (!list.elem) return false;

	list.length = 0;

	return true;
}


unsigned int listLength(seqList list)
{
	return (list.length);
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




bool destoryList(seqList list)
{
	if (list.elem)
	{
		free(list.elem);
		printf("sequence list not exist.\n");
	} else
	{
		printf("sequence list is empty.\n");
		return false;	
	}

	return true;
}
