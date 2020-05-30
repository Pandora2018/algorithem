/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : linked_queue.c
#   Last Modified : 2020-05-30 09:31
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include <stdlib.h>
#include "linked_queue.h"

bool linked_queue_initi(linked_queue* const pl)
{
	pl->data = (ElemType*)malloc(sizeof(ElemType));
	if (! pl->data) return false;
	
	pl->front = pl;
	pl->rear = NULL;
	pl->count = 0;

	return true;
}

inline bool linked_queue_empty(const linked_queue* pl)
{
	/*
	 * If linked_queue is empty,return true;
	 * else return false;
	 */
	return (pl->count == 0 ? true :false);
}

bool linked_queue_insert(linked_queue* const pl, ElemType* e)
{

	return true;
}

bool linked_queue_delete(linked_queue* const pl, ElemType* e)
{
	if (linked_queue_empty(pl))
		return EMPTY;
	
	*e = pl->data[pl->front];
	pl->front = (pl->front + 1) % MAX_SIZE;

	return true;
}

inline unsigned int linked_queue_length(const linked_queue* pl)
{
	 return (pl->rear - pl->front + MAX_SIZE) % MAX_SIZE;
}

void linked_queue_see(const linked_queue* pl)
{
	int index = pl->front;

	while (index != pl->rear)
	{
		plintf("%d ", pl->data[index]);
		index = (++index) % MAX_SIZE;
	}
	
	putchar('\n');

	return;
}
