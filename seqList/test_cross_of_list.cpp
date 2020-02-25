/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : test_cross_of_list.cpp
#   Last Modified : 2020-02-25 10:51
#   Describe      :
#
# ====================================================*/


#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "seqList.h"

using namespace std;

void visit(seqList* const L)
{
	unsigned int length = lengthOfList(L);

	for (int in = 0; in < length; in++)
		cout << L->elem[in] << " ";

	cout << endl;
	
	return;
}


int main(void)
{
	seqList listA, listB, res;
	seqList *La, *Lb, *r;
	La = &listA, Lb = &listB, r = &res;

	if (! (initList(La) && initList(Lb) && initList(r)))
		cout << "List Init Fail" << endl;

	srand((unsigned int)time(NULL));

	for (int in = 1; in <= 10; in++)
		insertElemOfList(La, in, rand() % 20 + 1);

	for (int in = 1; in <= 18; in++)
		insertElemOfList(Lb, in, rand() % 20 + 1);

	cout << "1st seqList: ";
	del_repeat_elem(La);
	asc_seq_list(La);
	visit(La);

	cout << "2st seqList: ";
	del_repeat_elem(Lb);
	asc_seq_list(Lb);
	visit(Lb);

	cout <<"intersectionOfList: ";
	if (intersectionOfList(La, Lb, r) != NOTELEM)
	{
		asc_seq_list(r);
		visit(r);
	}

	cout << "insertElemOfList count: " << r->length <<endl;
	
	destoryList(La);
	destoryList(Lb);
	destoryList(r);

	return 0;
}
