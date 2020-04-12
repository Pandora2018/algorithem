/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : cirLinkedList.h
#   Last Modified : 2020-04-12 17:03
#   Describe      :
#
# ====================================================*/


#ifndef __CLINKED_LIST_
#define __CLINKED_LIST_

#include <stdbool.h>

/* support c++ */
#ifdef __cplusplus
	extern "C" {
#endif

typedef int status;

/* define "ElemType" */
typedef struct book
{
	char id[10];
	char name[30];
	float price;
	char describe[60];
} ElemType;


/* linked list node define */
typedef struct _node
{
	ElemType data;
	struct _node* next;
} node;

/* linked list point define */
typedef node* cPlist;

/* operator linked list */
cPlist cirLinkedListIniti(void);

bool cirLinkedListEmpty(cPlist pl);

node* cirLinkedListNewNode(node* prev_node);

static node* cirLinkedListCreateNode(void);

unsigned int cirLinkedListLength(cPlist pl);

void cirLinkedListVisit(cPlist pl);

bool cirLinkedListClear(cPlist pl);

bool cirLinkedListTakeElem(cPlist pl, int pos, ElemType* e);

int cirLinkedListFindElem(cPlist pl, ElemType* specified_elem,
		status (*compare)(ElemType* cirLinkedListElem, ElemType* specifiedElem));

bool cirLinkedListInsertNode(cPlist pl, int pos);

bool cirLinkedListDeleteNode(cPlist pl, int pos, node* no);

bool cirLinkedListHeadInsert(cPlist pl, int num);

bool cirLinkedListTailInsert(cPlist pl, int num);

bool cirLinkedListDestory(cPlist pl);

#ifdef __cplusplus
}
#endif

#endif
