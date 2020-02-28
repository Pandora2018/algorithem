/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : test_init_list.c
#   Last Modified : 2020-02-28 15:47
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
	plist pl = linked_list_initi();	// linked_list head point

	/* the first node */
	node* first_node = (node*)malloc(sizeof(node));
	strcpy(first_node->member.id, "1");
	strcpy(first_node->member.name, "C Primer Plus");
	first_node->member.price = 23.00f;
	strcpy(first_node->member.describe, "this is C book");
	first_node->next = NULL;
	pl->next = first_node;

	/* the second node */
	#if 1
	node* second_node = (node*)malloc(sizeof(node));
	strcpy(second_node->member.id, "2");
	strcpy(second_node->member.name, "C++");
	second_node->member.price = 34.00f;
	strcpy(second_node->member.describe, "this is c++ book");
	second_node->next = NULL;
	first_node->next = second_node;
	#endif

	/* the third node */
#if 1
	node* third_node = (node*)malloc(sizeof(node));
	third_node->next = NULL;
	second_node->next = third_node;
#endif

	// create new node
	node* fourth_node = linked_list_new_node(third_node);

	node* fivth_node = linked_list_new_node(fourth_node);

	node* sixth_node = linked_list_new_node(fivth_node);

	node* seventh_node = linked_list_new_node(sixth_node);

	node* eig_node = linked_list_new_node(seventh_node);

	// count node
	printf("linked_list_length : %u\n", linked_list_length(pl));

	//get node data
	ElemType res;
	linked_list_take_elem(pl, 2, &res);

	printf("book.id : %s\n", res.id);
	printf("book.name : %s\n", res.name);
	printf("book.price : %.2f\n", res.price);
	printf("bool describe : %s\n", res.describe);
	
	return 0;
}
