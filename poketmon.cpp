/************************************************************************************
** Program Filename: poketmon.cpp
** Author: Dong Hoon Yeo
** Date: 2016/05/20
** Description: main pokemon stream
** Required files:
**	
************************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include "poketmon.h"
#include "skill.h"

int sHp[20] = {80,80,80,65,70,65,70,70,80,75,65,65,75,70,65,65,85,80,80,150};
int sAttk[20] = {22,26,19,19,21,20,21,14,28,19,15,16,21,20,18,22,30,32,40,50};
int sDef[20] = {24,17,28,19,21,20,20,16,28,24,19,23,25,21,21,19,34,28,30,50};
int sSpeed[20] = {18,25,16,28,21,25,26,20,21,16,26,25,26,20,25,24,12,21,30,50};
int sSpecialAttk[20] = {29,23,22,30,22,23,25,21,13,26,30,21,24,23,25,10,10,30,35,50};
int sSpecialDef[20] = {18,20,26,16,22,18,20,29,19,20,18,21,21,26,24,18,28,25,30,50};

void Poketmon::Init(){
	int i;	
	i = aPoketmonNum;
	i--;
	
	aAttk = sAttk[i]*aLevel;
	aDef = sDef[i]*aLevel;
	aSpeed = sSpeed[i]*aLevel;
	aSpecialAttk = sSpecialAttk[i]*aLevel;
	aSpecialDef = sSpecialDef[i]*aLevel;	
}

void Poketmon::LevelUp(){
	aExp = aExp - (aLevel * 2);
	aLevel++;
	aHp = sHp[aPoketmonNum-1]*aLevel;
	Init();	
}

void Poketmon::LevelCandyUp(){
	aExp = 0;
	aLevel++;
	aHp = sHp[aPoketmonNum-1]*aLevel;
	Init();	
}

void Poketmon::HpUp(int Hp){
	aHp += Hp;
}
