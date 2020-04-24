/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : c_linked_list.h
#   Last Modified : 2020-04-24 20:59
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
	ElemType info;
	struct _node* next;
} node;


/* linked list point define */
typedef node* c_plist;


/* operator linked list */
c_plist c_linked_list_initi(void);

bool c_linked_list_empty(c_plist c_pl);

node* c_linked_list_new_node(node* prev_node);

static node* c_linked_list_create_node(void);

unsigned int c_linked_list_length(c_plist c_pl);

void c_linked_list_visit(c_plist c_pl);

bool c_linked_list_clear(c_plist c_pl);

bool c_linked_list_take_elem(c_plist c_pl, int pos, ElemType* e);

int c_linked_list_find_elem(c_plist c_pl, ElemType* specified_elem,
		status (*compare)(ElemType* c_linked_list_elem, ElemType* specified_elem));

bool c_linked_list_insert_node(c_plist c_pl, int pos);

bool c_linked_list_delete_node(c_plist c_pl, int pos, node* no);

bool c_linked_list_head_insert(c_plist c_pl, int num);

bool c_linked_list_tail_insert(c_plist c_pl, int num);

bool c_linked_list_destory(c_plist c_pl);

#ifdef __cplusplus
}
#endif

#endif
