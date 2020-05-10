/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : link_stack.h
#   Last Modified : 2020-05-10 21:31
#   Describe      :
#
# ====================================================*/


#ifndef __LINK_STACK_H__
#define __LINK_STACK_H__

/* Support "C++" */
#ifdef __cpluscplus
	extern "C" {
#endif

#include <stdbool.h>
#include "elem_type.h"

typedef struct s_node
{
	ElemType data;
	struct s_node* next;
} stack_node;

typedef stack_node* link_stack;

/* All operator  */
bool link_stack_initi(link_stack s);

bool link_stack_empty(const link_stack s);

bool link_stack_clear(link_stack* ps);

unsigned int link_stack_length(const link_stack const s);

bool link_stack_push(link_stack* s, ElemType* e);

bool link_stack_pop(link_stack* ps, ElemType* e);

bool link_stack_destory(link_stack* ps);

/* Support "C++" */
#ifdef __cpluscplus
	}
#endif

#endif
