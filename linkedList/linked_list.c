/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : linked_list.c
#   Last Modified : 2020-03-13 18:31
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"


plist linked_list_initi(void)
{
	plist pl = (plist)malloc(sizeof(node));
	if (! pl) return NULL;
	pl->next = NULL;
	return pl;
}


inline bool linked_list_empty(plist pl)
{
	/*
	 * if linked_list is empty, then return true,
	 * not empty return false.
	 */
	return (pl->next ? false : true);
}

node* linked_list_new_node(node* prev_node)
{
	node* n = (node*)malloc(sizeof(node));
	if(! n) exit(EXIT_FAILURE);

	fgets(n->member.id, 10, stdin);
	fgets(n->member.name, 30, stdin);
	scanf("%f", & n->member.price);
	getchar();
	fgets(n->member.describe, 60, stdin);

	prev_node->next = n;
	n->next = NULL;
	return n;
}

static node* linked_list_create_node(void)
{
	node* n = (node*)malloc(sizeof(node));
	if(! n) exit(EXIT_FAILURE);

	fgets(n->member.id, 10, stdin);
	fgets(n->member.name, 30, stdin);
	scanf("%f", & n->member.price);
	getchar();
	fgets(n->member.describe, 60, stdin);

	n->next = NULL;
	return n;
}

unsigned int linked_list_length(plist pl)
{
	unsigned int length = 0;
	
	node* cur_node = pl;

	while (cur_node->next)
	{
		length++;
		cur_node = cur_node->next;
	}

	return length;
}


void linked_list_visit(plist pl)
{
	node* cur_node = pl->next;

	while (cur_node)
	{
		printf("%s%s%.2f\n%s",
				cur_node->member.id,
				cur_node->member.name,
				cur_node->member.price,
				cur_node->member.describe);
		printf("---------------\n");

		cur_node = cur_node->next;
	}

	return;
}


bool linked_list_clear(plist pl)
{
	node* cur_node = pl->next;

	while (cur_node)
	{
		node* next_node = cur_node->next;
		free(cur_node);
		cur_node = next_node;
	}

	pl->next = NULL;

	return true;
}


bool linked_list_take_elem(plist pl, int pos, ElemType* e)
{
	unsigned int cnt, len;
	cnt = 1;
	len = linked_list_length(pl);
	node* cur_node = pl->next;

	if (! linked_list_empty(pl) && (pos > 0 && pos < len + 1))
	{
		while (cnt++ != pos)
			cur_node = cur_node->next;

		*e = cur_node->member;

		return true;
	} else
	{
		printf("the linked list not element or postion error.\n");
		return false;
	}
}


int linked_list_find_elem(plist pl, ElemType* specified_elem,
		status (*compare)(ElemType* linked_list_elem, ElemType* specified_elem))
{
	int pos = 1;
	node* current_node = pl->next;

	while (current_node &&
			! (*compare)(&(current_node->member), specified_elem))
	{
		current_node = current_node->next;
		pos++;
	}

	return (current_node ? pos : -1);
}


bool linked_list_insert_node(plist pl, int pos)
{
	node* cur_node = pl;
	unsigned int cur_pos = 0;

	while (cur_node && cur_pos < pos - 1)
	{
		cur_node = cur_node->next;
		cur_pos++;
	}
	
	if (! cur_node || cur_pos > pos - 1)
		return false;

	node* tmp_node = cur_node->next;
	node* insert_node = linked_list_new_node(cur_node);
	insert_node->next = tmp_node;

	return true;
}


bool linked_list_delete_node(plist pl, int pos, node* no)
{
	node* cur_node = pl;
	unsigned int cur_pos = 0;

	// locate (pos - 1) node
	while (cur_node && cur_pos < pos - 1)
	{
		cur_node = cur_node->next;
		cur_pos++;
	}

	// if pos < 1 or pos > linked_list_length, then return fasle
	if (! cur_node || cur_pos > pos - 1)
		return false;

	node* delete_node = cur_node->next;
	*no = *delete_node;
	cur_node->next = delete_node->next;
	free(delete_node);
	
	return true;
}

bool linked_list_head_insert(plist pl, int num)
{
	node* new_node = NULL;

	if (num <= 0) return false;

	for (int cnt = num; cnt > 0; --cnt)
	{
		new_node = linked_list_create_node();
		new_node->next = pl->next;
		pl->next = new_node;
	}

	new_node = NULL;

	return true;
}

bool linked_list_tail_insert(plist pl, int num)
{
	if (num <= 0) return false;

	node* tail_node = pl;

	// locate linked_list's tail node
	while (tail_node->next)
		tail_node = tail_node->next;

	for (int cnt = num; cnt > 0; --cnt)
	{
		tail_node->next = linked_list_create_node();
		tail_node = tail_node->next;
	}

	return true;
}

bool linked_list_destory(plist pl)
{
	node* cur_node = NULL;

	while (pl)
	{
		cur_node = pl;
		pl = pl->next;
		free(cur_node);
	}
	
	cur_node = NULL;
	
	return true;
}
