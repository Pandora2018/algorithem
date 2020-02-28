/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : linked_list.c
#   Last Modified : 2020-02-28 15:46
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
	if (! pl) return false;
	pl->next = NULL;
	return pl;
}


bool linked_list_empty(plist pl)
{
	return (pl->next ? false : true);
}

node* linked_list_new_node(node* prev_node)
{
	node* n = (node*)malloc(sizeof(node));
	prev_node->next = n;
	n->next = NULL;
	return n;
}

unsigned int linked_list_length(plist pl)
{
	unsigned int length = 0;
	
	node* cur_node = pl->next;

	while (cur_node)
	{
		length++;
		cur_node = cur_node->next;
	}

	return length;
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
