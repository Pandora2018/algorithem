/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : test_init_list.c
#   Last Modified : 2020-02-26 20:27
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include "linked_list.h"


int main(void)
{
	plist pl;	// linked_list head point
	
	if (! initi_linked_list(pl))
		printf("linked_list initialization fail\n");

	printf("plist empty: %d\n", linked_list_empty(pl));

	return 0;
}
