/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : string_demo.c
#   Last Modified : 2020-06-10 20:09
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include "string.h"


int main(void)
{
	string s;
	string_initi(&s, "hello world! 0101 0901828192");
	printf("string length:%u\n", string_length(&s));
	printf("string: %s\n", s.ch);

#if 0
	string cs;
	string_copy(&cs, &s);
	printf("copy string:%s\n", cs.ch);
	printf("copy string length:%u\n", string_length(&cs));
#endif

	// Delete string
	if (string_delete(&s))
		printf("Delete string OK!\n");
	else
		printf("Delete string fail!\n");

	return 0;
}
