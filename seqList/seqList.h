/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : seqList.h
#   Last Modified : 2020-02-25 10:50
#   Describe      :
#
# ====================================================*/

#ifndef __SEQUENCE_H
#define __SEQUENCE_H

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

#ifdef __cplusplus
	extern "C" {
#endif

typedef struct {
	ElemType *elem;		// sequence list base adddress
	int length;			// number of element
	unsigned int listSize;	// current allocation memory
} seqList;

bool initList(seqList *L);

unsigned int lengthOfList(seqList* const L);

bool getElem(seqList *L, int i, ElemType *e);

void clearList(seqList *L);

bool insertElemOfList(seqList *L, int pos, ElemType e);

bool delElemOfList(seqList *L, int pos, ElemType *e);

int getPositionOfList(seqList *L, ElemType e);

int locateOfList(seqList *L, ElemType e2,
		bool (*cmp)(ElemType E, ElemType e));

int intersectionOfList(seqList* const La,
		seqList* const Lb, seqList *res);

void del_repeat_elem(seqList *L);

bool destoryList(seqList *L);

void asc_seq_list(seqList* const L);

#ifdef __cplusplus
}
#endif

#endif
