/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : sequence.h
#   Last Modified : 2019-05-22 21:22
#   Describe      :
#
# ====================================================*/

#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include <stdbool.h>
#include <stdio.h>

#if ! defined DEBUG
# 	include <assert.h>
#endif

// "size" is linear list maximun
#ifndef size
#	define size 30
#endif

// if linear list is empty, then error code is -1.
#if ! defined EMPTY
#	define EMPTY -1
#endif

// if linear list is full, then error code is -2.
#if ! defined FULL
#	define FULL -2
#endif

typedef double Item;

/* we use struct define linear list */
typedef struct
{
	Item list[size];
	unsigned int length;
	unsigned int cnt;
}sequence;

/* linear list base operator */
bool InitialList(sequence *_list);
unsigned int GetElemCnt(const sequence _list);
unsigned int GetLength(const sequence _list);
bool ListIsEmpty(const sequence _list);
bool ListIsFull(const sequence _list);
int InsertElem(sequence *_list, unsigned int pos, Item i);
bool GetElem(const sequence _list, unsigned int pos, Item *i);
bool LocateElem(const sequence _list, Item i);
int DeleteElem(sequence *_list, unsigned int pos, Item *i);
bool CleanList(sequence *_list);

#endif
