/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : sequence.h
#   Last Modified : 2020-02-01 18:44
#   Describe      :
#
# ====================================================*/

#ifndef _sequence_h
#define _sequence_h

#include <stdbool.h>

// #define OK 1
// #define ERROR 0
// #define SUCCESS 1
// #define FAIL 0

typedef int ElemType;
// typedef char ElemType;

typedef struct {
	ElemType *elem;		// sequence list base adddress
	int length;			// number of element
} seqList;

bool initList(seqList *L);
unsigned int listLength(seqList *L);
bool getElem(seqList list, int i, ElemType *e);
bool clearList(seqList list);
bool insertElemOfList(seqList *L, int pos, ElemType e);
bool delElemOfList(seqList *L, int pos, ElemType *e);
int getPositionOfList(seqList *L, ElemType e);



bool destoryList(seqList *L);

#endif
