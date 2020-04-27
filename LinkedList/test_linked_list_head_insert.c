/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : test_linked_list_head_insert.c
#   Last Modified : 2020-03-13 11:10
#   Describe      : 
#
# ====================================================*/


#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


int main(void)
{
	plist pl = linked_list_initi();

	node* pre_node = pl;
	node* _node = NULL;

	for (int i = 0; i < 3; ++i)
	{
		_node = linked_list_new_node(pre_node);
		pre_node = _node;
	}

	_node = NULL;

#if 0
	unsigned int pl_len = linked_list_length(pl);
	printf("current linked_list length : %u\n", pl_len);
	printf("------------------\n");

	/* linked_list_visit(pl); */
#endif

#if 1
	// head insert to linked_list
	if (linked_list_head_insert(pl, 1))
	{
		printf("after insert node, linked_list length : %u\n",
				linked_list_length(pl));
		printf("------------------\n");
		linked_list_visit(pl);
	} else
	{
		printf("linked_list_head_insert postion not right\n");
	}
#endif

	return 0;
}
