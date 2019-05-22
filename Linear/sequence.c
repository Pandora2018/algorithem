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
		return false;

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

bool ListIsEmpty(const sequence _list)
{
	return _list.cnt == 0;
}

bool ListIsFull(const sequence _list)
{
	return _list.cnt == _list.length;
}

int InsertElem(sequence *_list, unsigned int pos, Item i)
{
	assert(_list != NULL);
	assert(pos > 0 && pos < GetLength(*_list));

	if (ListIsFull(*_list))
	{
		printf("Linear list is fulled.\n");
		return FULL;
	}

	for (unsigned int index = GetLength(*_list) - 1;
			index >= pos; --index)
	{
		(*_list).list[index + 1] = (*_list).list[index];
	}

	(*_list).list[pos] = i;

	_list->cnt++;
	
	return true;
}

bool GetElem(const sequence _list, unsigned int pos, Item *i)
{
	assert(i != NULL);
	assert(pos > 0 && pos < GetLength(_list));

	*i = _list.list[pos - 1];

	return true;
}

bool LocateElem(const sequence _list, Item i)
{
	bool is_find = false;

	for (int index = 0; i < GetLength(_list); ++index)
	{
		if (_list.list[index] == i)
		{
			is_find = true;
			break;
		}
	}

	return (is_find ? true : false);
}

int DeleteElem(sequence *_list, unsigned int pos, Item *i)
{
	assert(_list != NULL);
	assert(pos > 0 && pos < GetLength(*_list));

	if (ListIsEmpty(*_list))
	{
		printf("Linear list is emptied.\n");
		return EMPTY;
	}

	*i = _list->list[pos];

	for (unsigned int index = pos;
			pos < GetLength(*_list) - 1; ++index)
	{
		(*_list).list[index] = (*_list).list[index + 1];
	}
	
	_list->cnt--;

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
