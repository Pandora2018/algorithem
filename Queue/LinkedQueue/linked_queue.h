/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : linked_queue.h
#   Last Modified : 2020-05-30 19:20
#   Describe      :
#
# ====================================================*/


#ifndef __LINKED_QUEUE_H__
	#define __LINKED_QUEUE_H__

#ifdef __cpluscplus
	extern "C" {
#endif

#include <stdbool.h>
#include "elem_type.h"

#define EMPTY 2;

/* Define node of linked_queue */
typedef struct queue_node
{
	ElemType data;
	struct queue_node* next;
} queue_node;

/* Define linked_queue */
typedef struct linked_queue
{
	queue_node *front, *rear;
	unsigned int count;
} linked_queue;

/* Basic Operations */
bool linked_queue_initi(linked_queue* const pl);

bool linked_queue_empty(const linked_queue* pl);

bool linked_queue_insert(linked_queue* const pl, ElemType* e);

bool linked_queue_delete(linked_queue* const pl, ElemType* e);

unsigned int linked_queue_length(const linked_queue* pl);

void linked_queue_see(const linked_queue* pl);

#ifdef __cpluscplus
	}
#endif

#endif
