/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : linked_list.c
#   Last Modified : 2020-02-27 12:23
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"


bool linked_list_initi(plist pl)
{
	pl = (plist)malloc(sizeof(node));
	if (! pl) return false;
	pl->next = NULL;
	return true;
}


bool linked_list_empty(plist pl)
{
	return (pl->next ? false : true);
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


bool linked_list_clear(plist pl)
{
	node* p_cur = pl->next;

	while (p_cur)
	{
		node* pnext = p_cur->next;
		free(p_cur);
		p_cur = pnext;
	}

	return true;
}


bool linked_list_take_elem(plist pl, int pos, ElemType* e)
{
	unsigned int cnt, len;
	cnt = 1;
	len = linked_list_length(pl);
	node* p_cur = pl->next;

	if (! linked_list_empty(pl) && (pos > 0 && pos < len + 1))
	{
		while (cnt++ != pos)
			p_cur = p_cur->next;

		*e = p_cur->member;

		return true;
	} else
	{
		printf("the linked list not element or postion error.\n");
		return false;
	}
}



bool linked_list_destory(plist pl)
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
