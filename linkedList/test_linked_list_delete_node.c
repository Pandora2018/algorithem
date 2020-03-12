/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : test_linked_list_delete_node.c
#   Last Modified : 2020-03-12 16:54
#   Describe      : 
#
# ====================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


int main(void)
{
	plist pl = linked_list_initi();

	node* prev_node = pl;
	node* new_node = NULL;

	for (int i = 0; i < 6; ++i)
	{
		new_node = linked_list_new_node(prev_node);
		prev_node = new_node;
	}

	new_node = NULL;

	// delete linked_list node
	node save_node;
#if 0
	int del_pos;
	printf("delete postion : ");
	fscanf(stdin, "%d", &del_pos);
#endif

	if (! linked_list_delete_node(pl, 2, &save_node) &&
		printf("delete linked_list node fail\n"))
	{
		exit(-1);
	}
	
	printf("delete node infomation: \n");
	printf("%s%s%.2f\n%s", 
			save_node.member.id,
			save_node.member.name,
			save_node.member.price,
			save_node.member.describe);
	printf("-------------------\n");

	printf("delete node after linked_list length : %u\n",
			linked_list_length(pl));

	return 0;
}
