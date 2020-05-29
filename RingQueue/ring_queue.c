/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : ring_queue.c
#   Last Modified : 2020-05-29 19:13
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include <stdlib.h>
#include "ring_queue.h"

bool ring_queue_initi(ring_queue* const pr)
{
	pr->data = (ElemType*)malloc(MAX_SIZE * sizeof(ring_queue));
	if (! pr) return false;

	pr->front = pr->rear = 0;

	return true;
}

inline bool ring_queue_empty(const ring_queue* pr)
{
	/*
	 * If ring_queue is empty,return true;
	 * else return false;
	 */
	return (pr->front == pr->rear ? true : false);
}

inline bool ring_queue_full(const ring_queue* pr)
{
	 /*
	  * If ring_queue is full,return true;
	  * else return false;
	  */
	return ((pr->rear + 1) % MAX_SIZE == pr->front ? true : false);
}

bool ring_queue_insert(ring_queue* const pr, ElemType* e)
{
	if (ring_queue_full(pr))
		return FULL;

	pr->data[pr->rear] = *e;
	(pr->rear)++;

	return true;
}

bool ring_queue_delete(ring_queue* const pr, ElemType* e)
{
	if (ring_queue_empty(pr))
		return EMPTY;
	
	*e = pr->data[pr->front];
	(pr->front)++;

	return true;
}

inline unsigned int ring_queue_length(const ring_queue* pr)
{
	 return (pr->rear - pr->front + MAX_SIZE) % MAX_SIZE;
}

void ring_queue_see(const ring_queue* pr)
{
	int index = pr->front;

	while (index != pr->rear)
	{
		printf("%d ", pr->data[index]);
		index = (++index) % MAX_SIZE;
	}
	
	putchar('\n');

	return;
}
