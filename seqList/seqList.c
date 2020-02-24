/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : seqList.c
#   Last Modified : 2020-02-24 19:49
#   Describe      : sequence list algorithem
#
# ====================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "seqList.h"

bool initList(seqList *L)
{
	L->elem = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
	if (! L->elem) return false;

	L->length = 0;
	L->listSize = MAXSIZE;

	return true;
}


unsigned int lengthOfList(seqList* const L)
{
	return (L->length);
}


bool getElem(seqList *L, int i, ElemType *e)
{
	if (i >= 1 && i <= L->length)
	{
		*e = L->elem[i - 1];
		return true;
	} else
	{
		printf("Index Not Valid\v");
		return false;
	}
}


void clearList(seqList *L)
{
	L->length = 0;
	return;
}


bool insertElemOfList(seqList *L, int pos, ElemType e)
{
	unsigned int length = lengthOfList(L);

	if (pos < 1 || pos > length + 1) exit(INDEX_ERR);

	if (L->length >= L->listSize)
	{
		ElemType *newbase = (ElemType *)realloc(L->elem,
				sizeof(ElemType) * (L->length + LIST_INCREMENT));

		if (! newbase) exit(ALLOCFAIL);
		L->elem = newbase;
		L->listSize += LIST_INCREMENT;
	}
	
	for (int index=length;index>=pos;index--)
		L->elem[index] = L->elem[index-1];

	L->elem[pos-1] = e;
	(L->length)++;

	return true;
}


bool delElemOfList(seqList *L, int pos, ElemType *e)
{
	unsigned int len = lengthOfList(L);

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
	unsigned int len = lengthOfList(L);
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


int locateOfList(seqList *L, ElemType e2,
		bool (*cmp)(ElemType e1, ElemType e2))
{
	ElemType *current = L->elem;
	int in = 0;
	unsigned int length = lengthOfList(L);

	while (in < length && !(*cmp)(*current++, e2))
		in++;

	if (in < length) return (in + 1);
	else return NOTF;
}

int intersectionOfList(seqList* const La, seqList* const Lb, seqList *res)
{
	int pos = 1;
	unsigned int cntA, cntB;
	cntA = lengthOfList(La);
	cntB = lengthOfList(Lb);

	for (int indexOfA = 0; indexOfA < cntA; ++indexOfA)
	{
		for (int indexOfB = 0; indexOfB < cntB; ++indexOfB)
		{
			if (La->elem[indexOfA] == Lb->elem[indexOfB])
			{
				insertElemOfList(res, pos++, La->elem[indexOfA]);
				break;
			}
		}
	}

	return (res->length ? res->length : NOTELEM);
}


void del_repeat_elem(seqList *L)
{
	unsigned int len = lengthOfList(L);
	ElemType e;

	for (int st = 0; st < len; ++st)
	{
		for (int next = st + 1; next < len; ++next)
		{
			if (L->elem[st] == L->elem[next])
			{
				delElemOfList(L, next + 1, &e);
				len = lengthOfList(L);
				--next;
			}
		}
	}
	
	return;
}


bool destoryList(seqList *L)
{
	if (L->elem)
	{
		free(L->elem);
		printf("Sequence List Destory.\n");
		return true;
	} else
	{
		printf("Sequence List Not Exist.\n");
		return false;	
	}
}
