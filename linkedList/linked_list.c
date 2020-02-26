/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : linked_list.c
#   Last Modified : 2020-02-26 20:27
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"


bool initi_linked_list(plist pl)
{
	pl = (plist)malloc(sizeof(node));
	if (pl) exit(EXIT_FAILURE);
	pl->next = NULL;
	return true;
}


bool linked_list_empty(plist pl)
{
	return (pl->next ? false : true);
}


bool destory_linked_list(plist pl)
{
	node* pn = NULL;

	while (pl)
	{
		pn = pl;
		pl = pl->next;
		free(pn);
	}
	
	pn = NULL;
	
	return true;
}


unsigned int linked_list_length(plist pl)
{
	unsigned int length = 0;
	
	node* pn = pl->next;

	while (pn)
	{
		length++;
		pn = pn->next;
	}

	return length;
}
