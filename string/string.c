/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : string.c
#   Last Modified : 2020-06-10 20:09
#   Describe      :
#
# ====================================================*/


#include <stdio.h>
#include <stdlib.h>
#include "string.h"


bool string_initi(string* T, char* c)
{
	if (! T->length) return STRING_EMPTY;

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
	
	T->ch = NULL;
	T->length = 0;

	return true;
}
