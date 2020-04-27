/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : test_linked_list_find_elem.c
#   Last Modified : 2020-03-10 16:41
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include <string.h>
#include "linked_list.h"

/* ElemType specified_elem = {"2", "Java design", 34.67, "Java design book"}; */
ElemType specified_elem = {"3", "Go language", 12.45, "go language book"};
/* ElemType specified_elem = {"4", "Swift language", 46.56, "swift language book"}; */


status cmp_equale(ElemType* linked_list_elem, ElemType* specified_elem)
{
	return (! strncmp(linked_list_elem->id, specified_elem->id, 1) &&
			! strncmp(linked_list_elem->name, specified_elem->name, 5) &&
			linked_list_elem->price == specified_elem->price &&
			! strncmp(linked_list_elem->describe, specified_elem->describe, 10)) ? 1 : 0;
}


int main(void)
{

	plist pl = linked_list_initi();

	node* prev_node = pl;

	for (int i = 0; i < 5; ++i)
	{
		node* new_node = linked_list_new_node(prev_node);
		prev_node = new_node;
	}

#if 1
	node* now_node = pl->next;

	for (int i = 0; i < 5; ++i)
	{
		printf("%s%s%.2f\n%s",
				now_node->member.id,
				now_node->member.name,
				now_node->member.price,
				now_node->member.describe);
		printf("-------------\n");
		now_node = now_node->next;
	}

	int pos = linked_list_find_elem(pl, &specified_elem, &cmp_equale);

	printf("specified_elem pos : %d\n", pos);
	
#endif
	
	return 0;
}
