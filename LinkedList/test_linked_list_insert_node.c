/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : test_linked_list_insert_node.c
#   Last Modified : 2020-03-11 17:57
#   Describe      : 
#
# ====================================================*/


#include <stdio.h>
#include "linked_list.h"


int main(void)
{
	plist pl = linked_list_initi();

	node* pre_node = pl;
	node* _node = NULL;

	for (int i = 0; i < 2; ++i)
	{
		_node = linked_list_new_node(pre_node);
		pre_node = _node;
	}

	_node = NULL;

	unsigned int pl_len = linked_list_length(pl);
	printf("current linked_list length : %u\n", pl_len);
	printf("------------------\n");

	linked_list_visit(pl);

#if 1
	// insert node to linked_list
	if (linked_list_insert_node(pl, 2))
		printf("after insert node, linked_list length : %u\n",
				linked_list_length(pl));
	else
		return 0;

	printf("------------------\n");

	linked_list_visit(pl);

#endif

	return 0;
}
