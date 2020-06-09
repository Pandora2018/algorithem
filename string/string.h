/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : string.h
#   Last Modified : 2020-06-09 20:29
#   Describe      :
#
# ==================================================== */


#ifndef __STRING_H__
	#define __STRING_H__

// Support C++
#ifdef __cplusplus
	extern "C" {
#endif

#include <stdbool.h>

#define STRING_SIZE 100

#define STRING_EMPTY 0

typedef struct string
{
	char* ch;
	unsigned int length;
} string;

bool string_initi(string* T, char* c);

unsigned int string_length(const string* T);

bool string_copy(string* des, const string* src);



#ifdef __cplusplus
	}
#endif

#endif
