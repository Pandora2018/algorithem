/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : cirLinkedListDemo.c
#   Last Modified : 2020-04-12 17:09
#   Describe      :
#
# ====================================================*/

#include <stdio.h>
#include "cirLinkedList.h"


int main(void)
{
	cPlist pl = cirLinkedListIniti();
	printf("cirLinkedList pl length: %d\n", cirLinkedListLength(pl));

	return 0;
}
