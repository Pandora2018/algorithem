/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : seqList.h
#   Last Modified : 2020-02-06 09:34
#   Describe      :
#
# ====================================================*/

#ifndef _sequence_h
#define _sequence_h

#include <stdbool.h>

#define NOTF -1
#define NOTELEM -1
#define ALLOCFAIL -2
#define INDEX_ERR -3

typedef int ElemType;
// typedef char ElemType;

#ifndef MAXSIZE
	#define MAXSIZE 20
#endif

#define LIST_INCREMENT 10

typedef struct {
	ElemType *elem;		// sequence list base adddress
	int length;			// number of element
	unsigned int listSize;	// current allocation memory
} seqList;

bool initList(seqList *L);
unsigned int lengthOfList(seqList *L);
bool getElem(seqList *L, int i, ElemType *e);
void clearList(seqList *L);
bool insertElemOfList(seqList *L, int pos, ElemType e);
bool delElemOfList(seqList *L, int pos, ElemType *e);
int getPositionOfList(seqList *L, ElemType e);
int locateOfList(seqList *L, ElemType e2,
		bool (*cmp)(ElemType E, ElemType e));

int intersectionOfList(seqList *La,
		seqList *Lb, seqList *res);

bool destoryList(seqList *L);

#endif
