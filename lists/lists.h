/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : lists.h
#   Last Modified : 2020-07-11 20:04
#   Describe      : 
#
# ====================================================*/

#ifndef  _LISTS_H
#define  _LISTS_H

/* Support C++ */
#ifdef __cplusplus
	extern "C" {
#endif

#include <stdbool.h>

typedef int AutoType;

typedef enum elem_type
{
	AUTOM,	// It's means auto node
	LIST,	// It's means subject node
} elem_type;

#if 1
typedef struct lists_node
{
	elem_type tag;
	union lists_node_ptr
	{
		AutoType autom;
		struct lists_node *head_ptr, *tail_ptr;
	} lists_node_ptr;
} lists_node;
#endif

#if 0
typedef struct lists_node
{
	elem_type tag;
	union lists_node_ptr
	{
		AutoType autom;
		struct lists_node *head_ptr;
	} lists_node_ptr;

	struct lists_node *tail_ptr;
} lists_node;
#endif

#ifdef __cplusplus
}
#endif

#endif // _LISTS_H
