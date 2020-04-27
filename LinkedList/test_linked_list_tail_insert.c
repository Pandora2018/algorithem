/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : test_linked_list_tail_insert.c
#   Last Modified : 2020-03-13 18:32
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

	for (int i = 0; i < 1; ++i)
	{
		_node = linked_list_new_node(pre_node);
		pre_node = _node;
	}

	_node = NULL;

#if 1
	unsigned int pl_len = linked_list_length(pl);
	printf("Before tail insert linked_list length : %u\n", pl_len);
	printf("------------------\n");

	/* linked_list_visit(pl); */
#endif

#if 1
	// tail insert to linked_list
	if (linked_list_tail_insert(pl, 3))
	{
		printf("after insert node, linked_list length : %u\n",
				linked_list_length(pl));
		printf("------------------\n");
		linked_list_visit(pl);
	} else
	{
		printf("linked_list_tail_insert postion not right\n");
	}
#endif

	return 0;
}
