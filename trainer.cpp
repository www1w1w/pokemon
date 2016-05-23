/************************************************************************************
** Program Filename: trainer.cpp
** Author: Dong Hoon Yeo
** Date: 2016/05/20
** Description: main pokemon stream
** Required files:
**	
************************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include "trainer.h"

Trainer::Trainer(){
	aPokemonCnt = 0;
	aBadges = 0;
	aMoney = 0;
}

void Trainer::GetBadge(){
	aBadges++;
}

void Trainer::GetMoney(int money){
	aMoney += money;
}

void Trainer::GetPokemon(Poketmon rPoketmon){
	aPokemonCnt++;
	aNowPokemons.push_back(rPoketmon);
}

void Trainer::UsingItem(int i){
	if(aItem.aCnt[i] > 0){	
		aItem.CntMinus(i);
	}
}

void Trainer::BuyItem(int i){
	if(aItem.aPrice[i] <= aMoney){
		aMoney -= aItem.aPrice[i];
		aItem.CntPlus(i);
	}
}

void Trainer::SellItem(int i){
	if(aItem.aCnt[i] > 0){
		aMoney += aItem.aPrice[i];
		aItem.CntMinus(i);
	}
}
