/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : testInsertOfList.c
#   Last Modified : 2020-02-04 19:01
#   Describe      :
#
# ====================================================*/

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "sequence.h"

#define INSERT

int main(void)
{
	seqList testList;
	seqList *L = &testList;
	bool res = initList(L);

	assert(res == true);
	
	for (int in=1;in<=50;in++)
	// for (int in=0;in<100;in++)
		insertElemOfList(L, in, in * 2);

	unsigned int len = lengthOfList(L);

	for (int in=0;in<len;in++)
		printf("%d ", L->elem[in]);
		// printf("%c ", L->elem[in]);

	putchar('\n');

	printf("Before List Length: %u\n", lengthOfList(L));

	putchar('\n');

	#ifdef INSERT
	// insert a elem to list
	unsigned int pos;
	printf("insert postion : ");
	scanf("%u", &pos);
	
	getchar();

	int ins;
	// char ins;
	printf("insert elem : ");
	// scanf("%c", &ins);
	scanf("%d", &ins);

	bool isInsert = insertElemOfList(L, pos, ins);
	assert(isInsert == true);

	for (int in=0;in<lengthOfList(L);in++)
		printf("%d ", L->elem[in]);
		// printf("%c ", L->elem[in]);

	putchar('\n');
	printf("After List Length: %u\n", lengthOfList(L));
	
	#endif

	return 0;
}
