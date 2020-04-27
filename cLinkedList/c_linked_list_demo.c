/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : c_linked_list_demo.c
#   Last Modified : 2020-04-27 18:57
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include "c_linked_list.h"


int main(void)
{
	c_plist demo_cpl = c_linked_list_initi();

	if (c_linked_list_empty(demo_cpl))
	{
		for (int i = 1; i <= 6; ++i)
			c_linked_list_insert_node(demo_cpl, i);
	}
	
	printf("Circle Linked List: \"demo_cpl\" length: %u\n", 
			c_linked_list_length(demo_cpl));

	puts("---------------------");
	c_linked_list_visit(demo_cpl);

#if 0
	/* Delete node from the Circle Linked List */
	node no;
	c_linked_list_delete_node(demo_cpl, 1, &no);

	printf("Circle Linked List: \"demo_cpl\" length: %u\n", 
			c_linked_list_length(demo_cpl));
#endif

#if 0
	/* Head insert node in the Circle Linked List */
	c_linked_list_head_insert(demo_cpl, 2);
#endif

#if 0
	/* Tail insert node in the Circle Linked List */
	c_linked_list_tail_insert(demo_cpl, 2);
#endif

	/*
	 * puts("---------------------");
	 * c_linked_list_visit(demo_cpl);
	 */

	if (c_linked_list_destory(demo_cpl))
		printf("demo_cpl was destoried,see you again.\n");

	return 0;
}
