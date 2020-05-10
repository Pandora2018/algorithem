/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : elem_type.h
#   Last Modified : 2020-05-10 17:22
#   Describe      :
#
# ====================================================*/


#ifndef __ELEM_TYPE_H__
#define __ELEM_TYPE_H__

struct book_info
{
	char id[10];
	char book_name[30];
	float price;
	char describe[50];
};

typedef struct book_info ElemType;

#endif
