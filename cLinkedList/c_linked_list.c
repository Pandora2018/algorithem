/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : c_linked_list.c
#   Last Modified : 2020-04-27 19:10
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "c_linked_list.h"


c_plist c_linked_list_initi(void)
{
	/* Create a head node of circle linked list */
	c_plist c_pl = (c_plist)malloc(sizeof(node));
	if (! c_pl) return NULL;
	c_pl->next = c_pl;
	return c_pl;
}

inline bool c_linked_list_empty(c_plist c_pl)
{
	/*
	 * The c_linked_list is empty,return true,
	 * it's not empty,return false.
	 */
	return (c_pl->next == c_pl ? true : false);
}

node* c_linked_list_new_node(node* prev_node)
{
	node* n = (node*)malloc(sizeof(node));
	if(! n) exit(EXIT_FAILURE);

	fgets(n->info.id, 10, stdin);
	fgets(n->info.name, 30, stdin);
	scanf("%f", & n->info.price);
	getchar();
	fgets(n->info.describe, 60, stdin);

	prev_node->next = n;
	n->next = NULL;
	return n;
}

static node* c_linked_list_create_node(void)
{
	/* The funtion only inner call */

	node* n = (node*)malloc(sizeof(node));
	if(! n) exit(EXIT_FAILURE);

	fgets(n->info.id, 10, stdin);
	fgets(n->info.name, 30, stdin);
	scanf("%f", & n->info.price);
	getchar();
	fgets(n->info.describe, 60, stdin);

	n->next = NULL;
	return n;
}

unsigned int c_linked_list_length(const c_plist c_pl)
{
	unsigned int length = 0;
	
	node* cur_node = c_pl;

	while (cur_node->next != c_pl)
	{
		length++;
		cur_node = cur_node->next;
	}

	return length;
}

void c_linked_list_visit(const c_plist c_pl)
{
	node* cur_node = c_pl->next;

	while (cur_node != c_pl)
	{
		printf("%s%s%.2f\n%s",
				cur_node->info.id,
				cur_node->info.name,
				cur_node->info.price,
				cur_node->info.describe);
		printf("---------------\n");

		cur_node = cur_node->next;
	}

	return;
}

bool c_linked_list_clear(const c_plist c_pl)
{
	/*
	 * Clear circle linked list all element,
	 * but head node not clear.
	 */
	node* cur_node = c_pl->next;

	/* If circle linked list is empty,return fasle. */
	if (cur_node == c_pl)
	{
		printf("Circle Linked List is empty,it's not clear\n");
		return false;
	}

	while (cur_node != c_pl)
	{
		node* next_node = cur_node->next;
		free(cur_node);
		cur_node = next_node;
	}

	/* Circle Linked List is empty after clear. */
	c_pl->next = c_pl;

	return true;
}

bool c_linked_list_take_elem(const c_plist c_pl, int pos, ElemType* e)
{
	unsigned int cnt, len;
	cnt = 1;
	len = c_linked_list_length(c_pl);
	node* cur_node = c_pl->next;

	if (c_linked_list_empty(c_pl) || pos < 0 || pos > len)
		return false;

	while (cnt != pos)
	{
		cur_node = cur_node->next;
		++cnt;
	}

	*e = cur_node->info;

	return true;
}

int c_linked_list_find_elem(const c_plist c_pl,
		ElemType* specified_elem,
		status (*compare)(
			ElemType* c_linked_list_elem,
			ElemType* specified_elem)
		)
{
	/*
	 * Find element from circle linked list,return the element postion,
	 * not find element return zero.
	 */
	int cur_pos = 1;
	node* current_node = c_pl->next;

	while (current_node != c_pl &&
			! (*compare)(&(current_node->info), specified_elem))
	{
		current_node = current_node->next;
		cur_pos++;
	}

	return (current_node != c_pl ? cur_pos : 0);
}

bool c_linked_list_insert_node(c_plist const c_pl, int pos)
{
	node* cur_node = c_pl;
	unsigned int cur_pos = 0;

	/*
	 * Insert postion between 1 and length(c_pl) + 1
	 * in the circle linked list. 
	 */

	if ( pos < 1 || pos > c_linked_list_length(c_pl) + 1)
		return false;

	while (cur_node->next != c_pl && cur_pos < pos - 1)
	{
		cur_node = cur_node->next;
		cur_pos++;
	}
	
	node* tmp_node = cur_node->next;
	node* insert_node = c_linked_list_new_node(cur_node);
	insert_node->next = tmp_node;

	return true;
}

bool c_linked_list_delete_node(c_plist const c_pl, int pos, node* no)
{
	node* cur_node = c_pl;
	unsigned int cur_pos = 0;

	/* If pos < 1 or pos > c_linked_list_length,return fasle. */
	if (pos < 1 || pos > c_linked_list_length(c_pl))
		return false;

	if (c_linked_list_empty(c_pl))
		return false;

	/* Locate (pos - 1) node */
	while (cur_node->next != c_pl && cur_pos < pos - 1)
	{
		cur_node = cur_node->next;
		cur_pos++;
	}

	node* delete_node = cur_node->next;
	*no = *delete_node;
	cur_node->next = delete_node->next;
	free(delete_node);
	
	return true;
}

bool c_linked_list_head_insert(c_plist const c_pl, int num)
{
	node* new_node = NULL;

	if (num <= 0) return false;

	for (int cnt = num; cnt > 0; --cnt)
	{
		new_node = c_linked_list_create_node();
		new_node->next = c_pl->next;
		c_pl->next = new_node;
	}

	new_node = NULL;

	return true;
}

bool c_linked_list_tail_insert(c_plist const c_pl, int num)
{
	if (num <= 0) return false;

	node* tail_node = c_pl;

	/* Locate c_linked_list's tail node */
	while (tail_node->next != c_pl)
		tail_node = tail_node->next;

	for (int cnt = num; cnt > 0; --cnt)
	{
		tail_node->next = c_linked_list_create_node();
		tail_node = tail_node->next;
		tail_node->next = c_pl;
	}

	return true;
}

bool c_linked_list_destory(c_plist const c_pl)
{
	/* Destory Circle Linked List all node,contain head node. */

	node* cur_node = c_pl;
	node* next_node = c_pl->next;

	while (next_node != c_pl)
	{
		free(cur_node);
		cur_node = next_node;
		next_node = next_node->next;
	}
	
	free(cur_node);
	next_node = NULL;

	return true;
}
