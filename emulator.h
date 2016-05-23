#ifndef _EMULATOR_H
#define _EMULATOR_H

#include <vector>
#include <iostream>
#include <string>
#include "trainer.h"

#define NORMAL		0
#define ELECTRIC	1
#define GRASS		2
#define FIRE		3
#define WATER		4
#define LEGEND		5
#define SPEED		6
#define POWERUP		7
#define POWERDOWN	8

using namespace std;

class Emulator
{
public:
	Trainer aCharactor;

	void Run();
	int Start();
	void NewGame();
	void LoadFile();
	void InGame();
	void Information();
	void SaveFile();
	void Hunt();
	void Heal();
	void Shop();
	void Vs();
	void Gym();
	void Exit();
	void fighting(int i, int input, bool b);
};


#endif
