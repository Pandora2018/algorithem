/* ====================================================
#   Copyright (C)2020 All rights reserved.
#
#   Author        : Pandora
#   Email         : pandora@github.com
#   File Name     : test_cross_of_list.cpp
#   Last Modified : 2020-02-24 18:09
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
		insertElemOfList(La, in, rand() % 10 + 1);

	for (int in = 1; in <= 18; in++)
		insertElemOfList(Lb, in, rand() % 10 + 1);

	cout << "1st seqList: ";
	visit(La);

	cout << "2st seqList: ";
	visit(Lb);

	cout <<"intersectionOfList: ";
	if (intersectionOfList(La, Lb, r) != NOTELEM)
		visit(r);

	cout << "insertElemOfList count: " << r->length <<endl;
	
	destoryList(La);
	destoryList(Lb);
	destoryList(r);

	return 0;
}