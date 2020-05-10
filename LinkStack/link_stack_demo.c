/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : link_stack_demo.c
#   Last Modified : 2020-05-10 21:35
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include <string.h>
#include "link_stack.h"

int main(void)
{
	link_stack s;		// Link_stack top
	if (! link_stack_initi(s))
		printf("Linke_Stack Initi Fail\n");

	link_stack* ps = &s;	// Control link_stack top

#if 1
	ElemType e;

	/* Test link_stack push */
	for (int cnt = 1; cnt <= 6; ++cnt)
	{
		fgets(e.id, 10, stdin);
		fgets(e.book_name, 30, stdin);
		scanf("%f", &e.price);
		getchar();
		fgets(e.describe, 50, stdin);

		link_stack_push(ps, &e);
	}

	printf("Link_stack length after push : %u\n",
			link_stack_length(s));

#if 1
	/* Test link_stack pop */
	for (int cnt = 1; cnt <= 3; ++cnt)
	{
		if (link_stack_pop(ps, &e))
		{
			printf("%s", e.id);
			printf("%s", e.book_name);
			printf("%.2f\n", e.price);
			printf("%s", e.describe);
			printf("-----------------\n");
		}
	}

	printf("Link_stack length after pop : %u\n",
			link_stack_length(s));
#endif

#if 1
	if (link_stack_clear(ps))
		printf("\"Link_stack_clear finish!\"\n");

	printf("Link_stack length after clear : %u\n",
			link_stack_length(s));
#endif

#if 0
	if (link_stack_destory(ps))
		printf("Link_stack is destory\n");
#endif

#endif

	return 0;
}
