/************************************************************************************
** Program Filename: item.cpp
** Author: Dong Hoon Yeo
** Date: 2016/05/20
** Description: main pokemon stream
** Required files:
**	
************************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include "item.h"

char sItem[5][20] = {{"PoketBall"},{"LevelCandy"},{"PotionLow"},{"PotionMid"},{"PotionHigh"}};
int sItemNum[5] = {0,1,2,3,4};
int sItemPrice[5] = {500, 3000, 400, 800, 1500};

void Item::Init(){
	int i;
	for(i = 0; i < 5; i++){
		strcpy(aName[i], sItem[i]);
		aItemNum[i] = sItemNum[i];
		aPrice[i] = sItemPrice[i];
		aCnt[i] = 0;
	}
}

void Item::CntPlus(int i){
	aCnt[i]++;
}

void Item::CntMinus(int i){
	aCnt[i]--;
}
