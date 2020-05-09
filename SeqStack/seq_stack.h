/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : seq_stack.h
#   Last Modified : 2020-05-09 13:57
#   Describe      :
#
# ====================================================*/


#ifndef __SEQ_STACK_H__
#define __SEQ_STACK_H__

#include <stdbool.h>
#include "elem_type.h"

/* Support "C++" */
#ifdef __cpluscplus
	extern "C" {
#endif
	
#define MAXSIZE 20

typedef struct 
{
	ElemType* stack;
	int bottom;
	int top;
} seq_stack;

/* Stack all operator */
bool seq_stack_initi(seq_stack* s);

bool seq_stack_empty(const seq_stack* s);

bool seq_stack_full(const seq_stack* s);

unsigned int seq_stack_length(const seq_stack* s);

void seq_stack_clear(seq_stack* const s);

bool seq_stack_push(seq_stack* const s, ElemType e);

bool seq_stack_pop(seq_stack* const s, ElemType* e);

bool seq_stack_destory(seq_stack* const s);

/* Support "C++" */
#ifdef __cpluscplus
	}
#endif

#endif
