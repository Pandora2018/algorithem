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

/**
 * @Brief	InitialList linear list
 *
 * @Param	_pl
 *
 * @Return	if initialize success, return true, else return false.
 */
bool InitialList(sequence *_pl)
{
	if (_pl != NULL)
	{
		_pl->length = size;
		_pl->cnt = 0;
	} else
	{
		printf("Initialize linear list fail.\n");
		return false;
	}

	return true;
}

/**
 * @Brief	GetElemCnt 
 *
 * @Param	_pl is initialized
 *
 * @Return	linear list element count
 */
unsigned int GetElemCnt(const sequence _list)
{
	return _list.cnt;
}

/**
 * @Brief	GetLength 
 *
 * @Param	_list is initialized
 *
 * @Return	_list length
 */
unsigned int GetLength(const sequence _list)
{
	return _list.length;
}

/**
 * @Brief	IsEmpty 
 *
 * @Param	_list is initialized
 *
 * @Return	 if linear _list empty, return true, else return false.
 */
bool IsEmpty(const sequence _list)
{
	return _list.cnt == 0;
}

/**
 * @Brief	IsFull 
 *
 * @Param	_pl
 *
 * @Return	if _list full, return true, else return false.
 */
bool IsFull(const sequence _list)
{
	return _list.cnt == _list.length;
}

/**
 * @Brief	InsertElem 
 *
 * @Param	_pl is linear list
 * @Param	pos is insert postion
 * @Param	i is value
 *
 * @Return	Insert success, return true.
 */
int InsertElem(sequence *_pl, unsigned int pos, Item i)
{
	assert(_pl != NULL);
	assert(pos > 0);
	assert(pos < GetLength(*_pl));

	if (! IsFull(*_pl))
	{
		for (unsigned int index = GetElemCnt(*_pl) - 1;
				index >= pos; --index)
		{
			(*_pl).list[index + 1] = (*_pl).list[index];
		}
	}
	else
	{
		printf("Linear list is fulled.\n");
		return FULL;
	}

	(*_pl).list[pos] = i;
	_pl->cnt ++;
	
	return true;
}

/**
 * @Brief	GetElem 
 *
 * @Param	_list is initialized linear list
 * @Param	pos is element postion
 * @Param	i is point, it save get element value
 *
 * @Return	if get success, return true.
 */
bool GetElem(const sequence _list, unsigned int pos, Item *i)
{
	assert(i != NULL);
	assert(pos > 0);
	assert(pos < GetLength(_list));

	*i = _list.list[pos - 1];

	return true;
}

/**
 * @Brief	LocateElem 
 *
 * @Param	_pl
 * @Param	i
 * @Param	pos
 *
 * @Return	return element postion
 */
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

/**
 * @Brief	DeleteElem 
 *
 * @Param	_pl
 * @Param	pos
 * @Param	i
 *
 * @Return	if delete element success, return true, else return false.
 */
int DeleteElem(sequence *_pl, unsigned int pos, Item *i)
{
	assert(_pl != NULL);
	assert(pos > 0);
	assert(pos < GetLength(*_pl));

	if (IsEmpty(*_pl))
	{
		printf("Linear list is emptied.\n");
		return EMPTY;
	}

	*i = _pl->list[pos];

	for (unsigned int index = pos;
			index < GetLength(*_pl) - 1; ++index)
	{
		(*_pl).list[index] = (*_pl).list[index + 1];
	}

	_pl->cnt --;

	return true;
}

/**
 * @Brief	CleanList 
 *
 * @Param	_pl
 *
 * @Return	clean initialized linear list, if success, return true.
 */
bool CleanList(sequence *_pl)
{
	assert(_pl != NULL);

	_pl->length = 0;
	_pl->cnt = 0;

	printf("Linear list is cleaned!\n");

	return true;
}
