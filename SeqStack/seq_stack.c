/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : seq_stack.c
#   Last Modified : 2020-05-09 13:57
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "seq_stack.h"

bool seq_stack_initi(seq_stack* s)
{
	s->stack = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
	if (! s->stack)
		return false;

	s->bottom = s->top = 0;

	return true;
}

inline bool seq_stack_empty(const seq_stack* s)
{
	/*
	 * If seq_stack is empty, return true,
	 * else return false.
	 */

	return (s->bottom == s->top ? true : false);
}

inline bool seq_stack_full(const seq_stack* s)
{
	/*
	 * If seq_stack is full, return true,
	 * else return fale;
	 */

	return (s->top - s->bottom == MAXSIZE) ? true : false;	
}

inline unsigned int seq_stack_length(const seq_stack* s)
{
	return (s->top - s->bottom);
}

inline void seq_stack_clear(seq_stack* const s)
{
	s->top = s->bottom;
	return;
}

bool seq_stack_push(seq_stack* const s, ElemType e)
{
	if (seq_stack_full(s))
		return false;

	s->stack[s->top] = e;
	(s->top)++;

	return true;
}

bool seq_stack_pop(seq_stack* const s, ElemType* e)
{
	if (seq_stack_empty(s))
		return false;

	--(s->top);
	*e = s->stack[s->top];

	return true;
}

bool seq_stack_destory(seq_stack* const s)
{
	if (seq_stack_empty(s)) 
		return false;

	free(s->stack);
	s->bottom = s->top = 0;

	return true;	
}
