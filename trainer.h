#ifndef _TRAINER_H
#define _TRAINER_H

#include <vector>
#include <iostream>
#include <string>
#include "poketmon.h"
#include "item.h"
using namespace std;

class Trainer
{
public:
	char aName[20];
	int aPokemonCnt;
	int aBadges;
	int aMoney;
	Item aItem;
	vector<Poketmon> aNowPokemons;

	Trainer();
	void GetBadge();
	void GetMoney(int money);
	void GetPokemon(Poketmon rPoketmon);
	void UsingItem(int i);
	void BuyItem(int i);
	void SellItem(int i);
};

#endif
