/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : linked_queue_demo.c
#   Last Modified : 2020-05-30 19:29
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include "linked_queue.h"

int main(void)
{
	linked_queue ql;
	
	if (! linked_queue_initi(&ql))
	{
		printf("linked Queue initi false!\n");
		return 1;
	}
	
	for (int i = 1; i <= 20; ++i)
		linked_queue_insert(&ql, &i);
	
	puts("linked Queue Before:");
	linked_queue_see(&ql);
	printf("Before length : %u\n", linked_queue_length(&ql));

	putchar('\n');

	ElemType delete_e;

	for (int j = 1; j <= 7; ++j)
		linked_queue_delete(&ql, &delete_e);

	puts("linked Queue After:");
	linked_queue_see(&ql);
	printf("After length : %u\n", linked_queue_length(&ql));

#if 1
	/* Again aAdd data to linked_queue */
	putchar('\n');

	for (int i = 1; i <= 6; ++i)
		linked_queue_insert(&ql, &i);

	linked_queue_see(&ql);
	printf("Again add data queue length : %u\n", linked_queue_length(&ql));

	putchar('\n');

	for (int j = 1; j <= 18; ++j)
		linked_queue_delete(&ql, &delete_e);

	linked_queue_see(&ql);
	printf("Again delete data queue length : %u\n", linked_queue_length(&ql));

#endif

	return 0;
}
