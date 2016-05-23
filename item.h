#ifndef _ITEM_H
#define _ITEM_H

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Item
{
public:
	char aName[5][20];
	int aItemNum[5];
	int aPrice[5];
	int aCnt[5];

	void Init();
	void CntPlus(int i);
	void CntMinus(int i);
};

#endif
