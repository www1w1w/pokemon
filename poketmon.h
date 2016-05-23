#ifndef _POKETMON_H
#define _POKETMON_H

#include <vector>
#include <iostream>
#include <string>
#include "skill.h"

class Poketmon
{
public:
	char aName[20];
	int aPoketmonNum;
	int aLevel;
	int aExp;
	int aHp;
	int aAttribute;
	int aAttk;
	int aDef;
	int aSpeed;
	int aSpecialAttk;
	int aSpecialDef;
	int aSkillCnt;
	vector<Skill> aSkills;
	 
	void Init();
	void LevelUp();
	void LevelCandyUp();
	void HpUp(int Hp);
};

#endif
