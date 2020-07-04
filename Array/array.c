/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : array.c
#   Last Modified : 2020-07-04 16:20
#   Describe      : 
#
# ====================================================*/

#include <stdio.h>


int main(void)
{
	int ar[] = {10, 20, 30};

	int arr[][2] = {
		{10,20},
		{20,40},
		{11,12}
	};

	printf("ar size:%zd\n", sizeof(ar));	// result:12bit
	printf("arr size:%zd\n", sizeof(arr));	// result:24bit

	return 0;
}
