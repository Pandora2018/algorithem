/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : string.c
#   Last Modified : 2020-06-11 20:54
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include <stdlib.h>
#include "string.h"


bool string_initi(string* T, char* c)
{
	T->ch = (char*)malloc(sizeof(char) * STRING_SIZE);
	if (! T->ch) return false;

	int i;
	for (i=0; c[i]; ++i)
		(T->ch)[i] = c[i];

	T->length = i;

	return true;
}

inline unsigned int string_length(const string* T)
{
	return (T->length);
}

bool string_copy(string* des, const string* src)
{
	if (! src->length)
		return STRING_EMPTY;
	
	des->ch = src->ch;
	des->length = src->length;

	return true;
}

bool string_delete(string* T)
{
	if (! T->length) return STRING_EMPTY;
	
	if (T->ch) free(T->ch);
	T->ch = NULL;
	T->length = 0;

	return true;
}

int string_matcher_BF(const string* T, unsigned int pos, const string* P)
{
	unsigned int T_len = string_length(T);
	unsigned int P_len = string_length(P);

	if (pos<0||pos>T_len) return STRING_INDEX_OVER;

	// i is string "T" pointer,j is string "P" pointrt.
	int i, j, slide;
	for (slide=0; slide<T_len-P_len; ++slide)
	{
		i = j = 0;
		while (j<P_len&&(T->ch)[pos+slide+i]==(P->ch)[j])
		{
			++i; ++j;
		}

		if (j==P_len) return (slide+1);
	}

	return 0;
}
