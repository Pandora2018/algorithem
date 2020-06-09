/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : string_demo.c
#   Last Modified : 2020-06-09 20:33
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

#if 1
	string cs;
	string_copy(&cs, &s);
	printf("copy string:%s\n", cs.ch);
	printf("copy string length:%u\n", string_length(&cs));
#endif


	return 0;
}
