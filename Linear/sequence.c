/* ====================================================
#   Copyright (C)2019 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : sequence.c
#   Last Modified : 2019-05-22 21:22
#   Describe      :
#
# ====================================================*/

#include "sequence.h"

bool InitialList(sequence *_list)
{
	if (_list != NULL)
	{
		_list->length = size;
		_list->cnt = 0;
	} else
	{
		printf("Initialize linear list fail.\n");
		return false;
	}

	return true;
}

unsigned int GetElemCnt(const sequence _list)
{
	return _list.cnt;
}

unsigned int GetLength(const sequence _list)
{
	return _list.length;
}

bool IsEmpty(const sequence _list)
{
	return _list.cnt == 0;
}

bool IsFull(const sequence _list)
{
	return _list.cnt == _list.length;
}

int InsertElem(sequence *_list, unsigned int pos, Item i)
{
	assert(_list != NULL);
	assert(pos > 0);
	assert(pos < GetLength(*_list));

	if (! IsFull(*_list))
	{
		for (unsigned int index = GetElemCnt(*_list) - 1;
				index >= pos; --index)
		{
			(*_list).list[index + 1] = (*_list).list[index];
		}
	}
	else
	{
		printf("Linear list is fulled.\n");
		return FULL;
	}

	(*_list).list[pos] = i;
	_list->cnt ++;
	
	return true;
}

bool GetElem(const sequence _list, unsigned int pos, Item *i)
{
	assert(i != NULL);
	assert(pos > 0);
	assert(pos < GetLength(_list));

	*i = _list.list[pos - 1];

	return true;
}

bool LocateElem(const sequence _list, Item i, unsigned int *pos)
{
	bool is_find = false;

	for (int index = 0; index < GetLength(_list); ++index)
	{
		if (_list.list[index] == i)
		{
			*pos = index;
			is_find = true;
			break;
		}
	}

	return (is_find ? true : false);
}

int DeleteElem(sequence *_list, unsigned int pos, Item *i)
{
	assert(_list != NULL);
	assert(pos > 0);
	assert(pos < GetLength(*_list));

	if (IsEmpty(*_list))
	{
		printf("Linear list is emptied.\n");
		return EMPTY;
	}

	*i = _list->list[pos];

	for (unsigned int index = pos;
			index < GetLength(*_list) - 1; ++index)
	{
		(*_list).list[index] = (*_list).list[index + 1];
	}

	_list->cnt --;

	return true;
}

bool CleanList(sequence *_list)
{
	assert(_list != NULL);

	_list->length = 0;
	_list->cnt = 0;

	printf("Linear list is cleaned!\n");

	return true;
}
