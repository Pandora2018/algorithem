/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : c_linked_list_demo.c
#   Last Modified : 2020-04-27 09:17
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
		for (int i = 1; i <= 5; ++i)
			c_linked_list_insert_node(demo_cpl, i);
	}
	
	printf("Circle Linked List: \"demo_cpl\" length: %u\n", 
			c_linked_list_length(demo_cpl));

	puts("---------------------");

	c_linked_list_visit(demo_cpl);


	/* Clear all element of circle linked list */
	c_linked_list_clear(demo_cpl);

	printf("Circle Linked List: \"demo_cpl\" length after clear: %u\n", 
			c_linked_list_length(demo_cpl));

	puts("---------------------");

	c_linked_list_visit(demo_cpl);


	return 0;
}
