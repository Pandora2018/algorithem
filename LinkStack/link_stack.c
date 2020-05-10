/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : link_stack.c
#   Last Modified : 2020-05-10 21:30
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include <stdlib.h>
#include "link_stack.h"

inline bool link_stack_initi(link_stack s)
{
	/* Create a empty stack */
	s = NULL;
	return true;
}

inline bool link_stack_empty(const link_stack s)
{
	/*
	 * If link_stack is empty, return true,
	 * else return false.
	 */
	return (s == NULL ? true : false);
}

bool link_stack_clear(link_stack* ps)
{
	/* Clear stack all data, but don't delete stack. */

	if (link_stack_empty(*ps))
		return false;

	stack_node* p = NULL;

	while (*ps != NULL)
	{
		p = *ps;
		*ps = (*ps)->next;
		free(p);
	}

	p = NULL;

	return true;
}

unsigned int link_stack_length(const link_stack const s)
{
	unsigned int length = 0;
	stack_node* p = s;

	while (p != NULL)
	{
		length++;
		p = p->next;
	}

	return length;
}

bool link_stack_push(link_stack* ps, ElemType* e)
{
	stack_node* push_node = (stack_node*)malloc(sizeof(stack_node));

	push_node->data = *e;
	push_node->next = *ps;
	*ps = push_node;
	return true;
}

bool link_stack_pop(link_stack* ps, ElemType* e)
{
	if (link_stack_empty(*ps))
		return false;

	stack_node* p = *ps;
	*e = (*ps)->data;
	*ps = (*ps)->next;
	free(p);

	return true;
}

bool link_stack_destory(link_stack* ps)
{
	stack_node* p = *ps;
	while (p != NULL)
	{
		*ps = (*ps)->next;
		free(p);
		p = *ps;
	}

	return true;
}
