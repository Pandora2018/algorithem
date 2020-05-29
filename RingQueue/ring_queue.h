/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : ring_queue.h
#   Last Modified : 2020-05-29 20:42
#   Describe      :
#
# ====================================================*/


#ifndef __RING_QUEUE_H__
	#define __RING_QUEUE_H__

#ifdef __cpluscplus
	extern "C" {
#endif

#include <stdbool.h>
#include "elem_type.h"

#define FULL 1;
#define EMPTY 2;

#define MAX_SIZE 10

typedef struct r_queue
{
	int front, rear;
	ElemType* data;
}ring_queue;

/* Basic Operations */
bool ring_queue_initi(ring_queue* pr);

bool ring_queue_empty(ring_queue* pr);

bool ring_queue_full(ring_queue* pr);

bool ring_queue_insert(ring_queue* pr, ElemType* e);

bool ring_queue_delete(ring_queue* pr, ElemType* e);

unsigned int ring_queue_length(ring_queue* pr);

void ring_queue_see(ring_queue* pr);

#ifdef __cpluscplus
	}
#endif

#endif
