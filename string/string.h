/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : string.h
#   Last Modified : 2020-06-11 20:55
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
#define STRING_EMPTY -1
#define STRING_INDEX_OVER -1

typedef struct string
{
	char* ch;
	unsigned int length;
} string;

bool string_initi(string* T, char* c);

unsigned int string_length(const string* T);

bool string_copy(string* des, const string* src);

bool string_delete(string* T);

int string_matcher_BF(const string* T, unsigned int pos, const string* P);



#ifdef __cplusplus
	}
#endif

#endif
