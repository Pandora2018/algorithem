/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : linked_list.h
#   Last Modified : 2020-02-26 20:27
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


/* define "ElemType" */
typedef struct eample
{
	char id[10];
	char name[20];
	float price;
	char describe[30];
} ElemType;


/* linked list node define */
typedef struct _node
{
	ElemType member;
	struct _node *next;
} node;


/* linked list point define */
typedef node* plist;


/* operator linked list */
bool initi_linked_list(plist pl);

bool linked_list_empty(plist pl);

bool destory_linked_list(plist pl);

unsigned int linked_list_length(plist pl);






#ifdef __cplusplus
}
#endif

#endif
