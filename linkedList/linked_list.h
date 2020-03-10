/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : linked_list.h
#   Last Modified : 2020-03-10 16:41
#   Describe      :
#
# ====================================================*/


#ifndef __LINKED_LIST_
#define __LINKED_LIST_

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
	ElemType member;
	struct _node* next;
} node;


/* linked list point define */
typedef node* plist;


/* operator linked list */
plist linked_list_initi(void);

bool linked_list_empty(plist pl);

node* linked_list_new_node(node* prev_node);

unsigned int linked_list_length(plist pl);

bool linked_list_clear(plist pl);

bool linked_list_take_elem(plist pl, int pos, ElemType* e);

int linked_list_find_elem(plist pl, ElemType* specified_elem,
		status (*compare)(ElemType* linked_list_elem, ElemType* specified_elem));




bool linked_list_destory(plist pl);

#ifdef __cplusplus
}
#endif

#endif
