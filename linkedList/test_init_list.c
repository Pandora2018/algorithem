/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : test_init_list.c
#   Last Modified : 2020-02-27 20:05
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "linked_list.h"


int main(void)
{
	plist pl;	// linked_list head point
	
	linked_list_initi(pl);
	
	/* the first node */
	node* first_node = (node*)malloc(sizeof(node));
	strcpy(first_node->member.id, "1");
	strcpy(first_node->member.name, "C Primer Plus");
	first_node->member.price = 23.00f;
	strcpy(first_node->member.describe, "this is C book");
	first_node->next = NULL;
	pl->next = first_node;

	/* the second node */
	#if 0
	node* second_node = (node*)malloc(sizeof(node));
	strcpy(second_node->member.id, "2");
	strcpy(second_node->member.name, "C++");
	second_node->member.price = 34.00f;
	strcpy(second_node->member.describe, "this is c++ book");
	second_node->next = NULL;
	first_node->next = second_node;
	#endif

	/* the third node */
#if 0
	node* third_node = (node*)malloc(sizeof(node));
	third_node->next = NULL;
	second_node->next = third_node;
#endif

	printf("linked_list_length : %u\n", linked_list_length(pl));

	return 0;
}
