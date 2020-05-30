/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : ring_queue_demo.c
#   Last Modified : 2020-05-30 09:01
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include <string.h>
#include "ring_queue.h"

int main(void)
{
	ring_queue rq;
	
	if (! ring_queue_initi(&rq))
	{
		printf("Ring Queue initi false!\n");
		return 1;
	}
	
	for (int i = 1; i <= 8; ++i)
		ring_queue_insert(&rq, &i);
	
	puts("Ring Queue Before:");
	ring_queue_see(&rq);
	printf("Before length : %u\n", ring_queue_length(&rq));

	putchar('\n');

	ElemType delete_e;

	for (int j = 1; j <= 3; ++j)
		ring_queue_delete(&rq, &delete_e);

	puts("Ring Queue After:");
	ring_queue_see(&rq);
	printf("After length : %u\n", ring_queue_length(&rq));

#if 0
	/* Again aAdd data to ring_queue */
	putchar('\n');

	for (int i = 1; i <= 4; ++i)
		ring_queue_insert(&rq, &i);

	ring_queue_see(&rq);
	printf("Before length : %u\n", ring_queue_length(&rq));

	putchar('\n');

	for (int j = 1; j <= 6; ++j)
		ring_queue_delete(&rq, &delete_e);

	ring_queue_see(&rq);
	printf("Before length : %u\n", ring_queue_length(&rq));

#endif

	return 0;
}
