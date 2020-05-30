/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : linked_queue.c
#   Last Modified : 2020-05-30 19:20
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include <stdlib.h>
#include "linked_queue.h"

bool linked_queue_initi(linked_queue* const pl)
{
	queue_node* q_node = (queue_node*)malloc(sizeof(queue_node));
	
	if (! q_node) return false;

	pl->front = pl->rear = q_node;
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
	queue_node* insert_node = (queue_node*)malloc(sizeof(queue_node));

	if (! insert_node) return false;

	insert_node->data = *e;
	insert_node->next = NULL;

	pl->rear->next = insert_node;
	pl->rear = insert_node;
	++(pl->count);

	return true;
}

bool linked_queue_delete(linked_queue* const pl, ElemType* e)
{
	if (linked_queue_empty(pl)) return EMPTY;

	queue_node* del_node = pl->front->next;
	*e = del_node->data;
	pl->front->next = del_node->next;
	free(del_node);
	--(pl->count);

	return false;
}

inline unsigned int linked_queue_length(const linked_queue* pl)
{
	 return (pl->count);
}

void linked_queue_see(const linked_queue* pl)
{
	queue_node* current_node = pl->front->next;

	while (current_node)
	{
		printf("%d ", current_node->data);
		current_node = current_node->next;
	}

	putchar('\n');

	return;
}
