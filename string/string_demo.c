/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : string_demo.c
#   Last Modified : 2020-06-11 20:54
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include "string.h"


int main(void)
{
	string s;
	if (! string_initi(&s, "hello world! 0101 01010 0XabcdABCD"))
		printf("string \'s\' initi ERROR\n");

	/*
	 * printf("string length:%u\n", string_length(&s));
	 * printf("string: %s\n", s.ch);
	 */

#if 0
	string cs;
	string_copy(&cs, &s);
	printf("copy string:%s\n", cs.ch);
	printf("copy string length:%u\n", string_length(&cs));
#endif

#if 1
	// String matcher
	string m;
	string_initi(&m, "0X");

	int pos = string_matcher_BF(&s, 6, &m);

	if (pos==STRING_INDEX_OVER)
		printf("POS ERROR\n");
	else if (pos==0)
		printf("STRING NOT EXIST SUBSTRING\n");
	else
		printf("\"%s\" postion:%d in \"%s\"\n", m.ch, pos, s.ch);

	/*
	 * switch (pos)
	 * {
	 *     case STRING_INDEX_OVER:
	 *           printf("POS ERROR\n");
	 *           break;
	 *     case 0:
	 *           printf("STRING NOT EXIST SUBSTRING\n");
	 *           break;
	 *     defult:
	 *         printf("\"%s\" postion:%d in \"%s\"\n", m.ch, pos, s.ch);
	 * }
	 */
#endif

#if 0
	// Delete string
	if (string_delete(&s))
		printf("Delete string OK!\n");
	else
		printf("Delete string fail!\n");
#endif

	return 0;
}
