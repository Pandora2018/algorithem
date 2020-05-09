/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : seq_stack_demo.c
#   Last Modified : 2020-05-09 13:57
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include "seq_stack.h"


int main(void)
{
	seq_stack s;

	if (! seq_stack_initi(&s))
		printf("Seq_stack init fail\n");

#if 0
	printf("s.top = %d, s.bottom = %d\n", s.top,s.bottom);
	printf("s.stack = %p\n", s.stack);
#endif

#if 1
	for (int cnt = 1; cnt <= 20; ++cnt)
	{
		int push_e = 2 * cnt;
		seq_stack_push(&s, push_e);
	}

	printf("Seq_stack length after push: %u\n",
			seq_stack_length(&s));	// result "10"

#if 1
	int pop_e;
	for (int pop_cnt = 1; pop_cnt <= 20; ++pop_cnt)
	{
		seq_stack_pop(&s, &pop_e);
		printf("Pop_e[%02d] = %02d\n", pop_cnt, pop_e);
	}
#endif
	
	printf("Current seq_stack length: %u\n",
			seq_stack_length(&s));
#endif

#if 0
	if (seq_stack_destory(&s))
		printf("Seq_stack destory\n");
#endif

	return 0;
}
