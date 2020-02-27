/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : test_init_list.c
#   Last Modified : 2020-02-27 12:23
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"


int main(void)
{
	plist pl;	// linked_list head point
	
	if (! linked_list_initi(pl))
		printf("linked_list initialization fail\n");

	/* linked_list_empty(pl); */
	/* printf("plist empty: %p\n", pl->next); */

	/* the first node */
	node* pn = (node*)malloc(sizeof(node));
	strcpy(pn->member.id, "1");
	strcpy(pn->member.name, "C Primer Plus");
	pn->member.price = 23.00f;
	strcpy(pn->member.describe, "this is C book");
	pn->next = NULL;
	pl->next = pn;

	/* the second node */
	node* pthree = (node*)malloc(sizeof(node));
	/*
	 * strcpy(pthree->member.id, "2");
	 * strcpy(pthree->member.name, "C++");
	 * pthree->member.price = 34.00f;
	 * strcpy(pthree->member.describe, "this is c++ book");
	 */
	pthree->next = NULL;
	pn->next = pthree;

	/* the third node */
	node* pnode = (node*)malloc(sizeof(node));
	pnode->next = NULL;
	pthree->next = pnode;

	printf("linked_list_length : %u\n", linked_list_length(pl));

	return 0;
}
