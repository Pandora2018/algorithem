/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : cirLinkedList.c
#   Last Modified : 2020-04-12 18:14
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cirLinkedList.h"


cPlist cirLinkedListIniti(void)
{
	cPlist pl = (cPlist)malloc(sizeof(node));
	if (! pl) return NULL;
	pl->next = pl;
	return pl;
}


inline bool cirLinkedListEmpty(cPlist pl)
{
	/*
	 * if cirLinkedList is empty, return true,
	 * not empty, return false.
	 */
	return (pl->next == pl ? true : false);
}

node* cirLinkedListNewNode(node* prev_node)
{
	node* n = (node*)malloc(sizeof(node));
	if(! n) exit(EXIT_FAILURE);

	fgets(n->data.id, 10, stdin);
	fgets(n->data.name, 30, stdin);
	scanf("%f", & n->data.price);
	getchar();
	fgets(n->data.describe, 60, stdin);

	prev_node->next = n;
	n->next = NULL;
	return n;
}

static node* cirLinkedListCreateNode(void)
{
	node* n = (node*)malloc(sizeof(node));
	if(! n) exit(EXIT_FAILURE);

	fgets(n->data.id, 10, stdin);
	fgets(n->data.name, 30, stdin);
	scanf("%f", & n->data.price);
	getchar();
	fgets(n->data.describe, 60, stdin);

	n->next = NULL;
	return n;
}

unsigned int cirLinkedListLength(cPlist pl)
{
	unsigned int length = 0;
	
	node* cur_node = pl;

	while (cur_node->next != pl)
	{
		length++;
		cur_node = cur_node->next;
	}

	return length;
}


void cirLinkedListvisit(cPlist pl)
{
	node* cur_node = pl->next;

	while (cur_node != pl)
	{
		printf("%s%s%.2f\n%s",
				cur_node->data.id,
				cur_node->data.name,
				cur_node->data.price,
				cur_node->data.describe);
		printf("---------------\n");

		cur_node = cur_node->next;
	}

	return;
}


bool cirLinkedListClear(cPlist pl)
{
	node* cur_node = pl->next;

	while (cur_node != pl)
	{
		node* next_node = cur_node->next;
		free(cur_node);
		cur_node = next_node;
	}

	return true;
}


bool cirLinkedListTakeElem(cPlist pl, int pos, ElemType* e)
{
	unsigned int cnt, len;
	cnt = 1;
	len = cirLinkedListLength(pl);
	node* cur_node = pl->next;

	if (cirLinkedListEmpty(pl) || pos < 0 || pos > len)
	{
		return false;
	}

	while (cnt++ != pos)
		cur_node = cur_node->next;

	*e = cur_node->data;

	return true;
}


int cirLinkedListFindElem(cPlist pl, ElemType* specified_elem,
		status (*compare)(ElemType* cirLinkedListElem, ElemType* specifiedElem))
{
	int pos = 1;
	node* current_node = pl->next;

	while (current_node &&
			! (*compare)(&(current_node->data), specified_elem))
	{
		current_node = current_node->next;
		pos++;
	}

	return (current_node ? pos : -1);
}


bool cirLinkedListInsertNode(cPlist pl, int pos)
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
	node* insert_node = cirLinkedListNewNode(cur_node);
	insert_node->next = tmp_node;

	return true;
}


bool cirLinkedListDelete_node(cPlist pl, int pos, node* no)
{
	node* cur_node = pl;
	unsigned int cur_pos = 0;

	// locate (pos - 1) node
	while (cur_node && cur_pos < pos - 1)
	{
		cur_node = cur_node->next;
		cur_pos++;
	}

	// if pos < 1 or pos > cirLinkedListlength, then return fasle
	if (! cur_node || cur_pos > pos - 1)
		return false;

	node* delete_node = cur_node->next;
	*no = *delete_node;
	cur_node->next = delete_node->next;
	free(delete_node);
	
	return true;
}

bool cirLinkedListHeadInsert(cPlist pl, int num)
{
	node* new_node = NULL;

	if (num <= 0) return false;

	for (int cnt = num; cnt > 0; --cnt)
	{
		new_node = cirLinkedListCreateNode();
		new_node->next = pl->next;
		pl->next = new_node;
	}

	new_node = NULL;

	return true;
}

bool cirLinkedListTailInsert(cPlist pl, int num)
{
	if (num <= 0) return false;

	node* tail_node = pl;

	// locate linked_list's tail node
	while (tail_node->next)
		tail_node = tail_node->next;

	for (int cnt = num; cnt > 0; --cnt)
	{
		tail_node->next = cirLinkedListCreateNode();
		tail_node = tail_node->next;
	}

	return true;
}

bool cirLinkedListDestory(cPlist pl)
{
	node* cur_node = pl;
	node* next_node = pl->next;

	while (next_node)
	{
		free(cur_node);
		cur_node = next_node;
		next_node = next_node->next;
	}
	
	free(cur_node);

	return true;
}
