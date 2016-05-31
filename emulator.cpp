/************************************************************************************
** Program Filename: emulator.cpp
** Author: Dong Hoon Yeo
** Date: 2016/05/22
** Description: main pokemon stream
** Required files:
**			
**		
************************************************************************************/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <vector>
#include <algorithm>
#include "emulator.h"
#include "trainer.h"
#include "poketmon.h"
#include "skill.h"
#include "item.h"

#define MODLUS 2147483647
#define MULT	630360016
#define MULT1       24112
#define MULT2       26143

using namespace std;
int read_input_start();
int read_input_game();
void init_pokemon(int i, int level);
int random(int low, int high);
int init_skill(int j);

Poketmon PoketMonster;
Skill NowSkill;
static long ran = 150493284;
char Name[20][20] = {{"Leesangheassi"},{"Pairi"},{"Ggobuugi"},{"Picachu"},{"Digda"},{"Naoong"},{"Gadi"},{"Gorapaduck"},
{"Altongmon"},{"Woochuidong"},{"Coill"},{"Arkustar"},{"Ponita"},{"Ddubuckcho"},{"Jjirrirrigong"},{"Ggoret"},{"Jammanbo"},{"Minyong"},{"Myu"},{"Hambang"}};
char VsName[12][20] = {{"DongHyun"},{"MinWoo"},{"WanHyeok"},{"SangHyun"},{"JaeHyun"},{"TaeHo"},{"JinSu"},{"DongHyeok"},{"GeonHo"},{"JaeYeol"},{"YoungDae"},{"DongHoon"}};
char GymName[9][20] = {{"Hambang_Sugar"},{"Hambang_AI"},{"Hambang_BlackJack"},{"Hambang_Factory"},{"Hambang_Simulation"},{"Hambang_3000"},{"Hambang_Pintos"},{"Hambang_Linux"},{"JINKYU_prof"}};
int Hp[20] = {80,80,80,65,70,65,70,70,80,75,65,65,75,70,65,65,85,80,80,150};
int Attribute[20] = {2,3,4,1,0,0,3,4,0,2,1,4,3,2,1,0,0,0,5,5};
int Attk[20] = {22,26,19,19,21,20,21,14,28,19,15,16,21,20,18,22,30,32,40,50};
int Def[20] = {24,17,28,19,21,20,20,16,28,24,19,23,25,21,21,19,34,28,30,50};
int Speed[20] = {18,25,16,28,21,25,26,20,21,16,26,25,26,20,25,24,12,21,30,50};
int SpecialAttk[20] = {29,23,22,30,22,23,25,21,13,26,30,21,24,23,25,10,10,30,35,50};
int SpecialDef[20] = {18,20,26,16,22,18,20,29,19,20,18,21,21,26,24,18,28,25,30,50};
char Skills[20][20] = {{"NormalPunch"},{"ElectricPunch"},{"GrassPunch"}, {"FirePunch"},{"WaterPunch"},{"QuickPunch"},{"Slam"},{"Thunder"},{"SolarBeam"},{"FireBlast"},{"WaterPump"},{"SpeedStar"},{"Fighting"},{"Harden"},{"Stress"},{"Fever"},{"Drain"},{"SelfBoom"},{"Homework"},{"ServerBoom"}};
int SkillPercent[20] = {30,30,30,30,30,20,100,100,100,100,100,80,30,30,30,30,10,150,300,300};
int SkillType[20] = {0,1,2,3,4,6,0,1,2,3,4,6,7,7,8,8,5,0,5,5};

int main(){
	Emulator e;
	e.Run();
}

void Emulator::Run(){
	int num = Start();

	if(num == 1)
		NewGame();
	else if(num == 2)
		LoadFile();
	else Exit();		
}

int Emulator::Start(){
	int a = 0;
	cout << "********************************************************************" << endl;
	cout << "*  @@@@@@@@       @@@@@@     @       @  @@@@@@@@@@@  @@@@@@@@@@@@@ *" << endl;
	cout << "*  @       @     @      @    @      @   @                  @       *" << endl;
	cout << "*  @        @   @        @   @     @    @                  @       *" << endl;
	cout << "*  @        @  @          @  @    @     @                  @       *" << endl;
	cout << "*  @       @   @          @  @   @      @                  @       *" << endl;
	cout << "*  @      @    @          @  @  @       @                  @       *" << endl;
	cout << "*  @@@@@@@     @          @  @ @        @                  @       *" << endl;
	cout << "*  @           @          @  @@         @@@@@@@@@@@        @       *" << endl;
	cout << "*  @           @          @  @ @        @                  @       *" << endl;
	cout << "*  @           @          @  @  @       @                  @       *" << endl;
	cout << "*  @           @          @  @   @      @                  @       *" << endl;
	cout << "*  @           @          @  @    @     @                  @       *" << endl;
	cout << "*  @            @        @   @     @    @                  @       *" << endl;
	cout << "*  @             @      @    @      @   @                  @       *" << endl;
	cout << "*  @              @@@@@@     @       @  @@@@@@@@@@@        @       *" << endl;
	cout << "*                                                                  *" << endl;
	cout << "*          @          @     @@@@@@     @             @             *" << endl;
	cout << "*          @@        @@    @      @    @@            @             *" << endl;
	cout << "*          @ @      @ @   @        @   @ @           @             *" << endl;
	cout << "*          @  @    @  @  @          @  @  @          @             *" << endl;
	cout << "*          @   @  @   @  @          @  @   @         @             *" << endl;
	cout << "*          @    @@    @  @          @  @    @        @             *" << endl;
	cout << "*          @          @  @          @  @     @       @             *" << endl;
	cout << "*          @          @  @          @  @      @      @             *" << endl;
	cout << "*          @          @  @          @  @       @     @             *" << endl;
	cout << "*          @          @  @          @  @        @    @             *" << endl;
	cout << "*          @          @  @          @  @         @   @             *" << endl;
	cout << "*          @          @  @          @  @          @  @             *" << endl;
	cout << "*          @          @   @        @   @           @ @             *" << endl;
	cout << "*          @          @    @      @    @            @@             *" << endl;
	cout << "*          @          @     @@@@@@     @             @             *" << endl;
	cout << "********************************************************************" << endl;
	cout << "*                                                                  *" << endl;
	cout << "*                                                                  *" << endl;
	cout << "*      1. new game                                                 *" << endl;
	cout << "*      2. load game                                                *" << endl;
	cout << "*      3. exit                                                     *" << endl;
	cout << "*                                                                  *" << endl;
	cout << "*                                                                  *" << endl;
	cout << "********************************************************************" << endl;
	cout << "input : ";
	while(a == 0)
		a = read_input_start();
	
	return a;
}

void Emulator::NewGame(){
	int k = 0;
	char a;
	system("clear");
	cout << "NewGame!!!!!!!!!!!!!!!!!!!!" << endl;
	
	cout << "Your Name?(under 20 charactors) ";
	cin >> aCharactor.aName;
	cout << "Your Name : " << aCharactor.aName << endl;
	cout << "Choose your first pokemon.\n1.Leesangheassi   2.Pairi   3.Ggobuugi\ninput : ";
	while(k == 0)
		k = read_input_start();
	if(k == 1)
		cout << "You choose Leesangheassi" << endl;
	else if(k == 2)
		cout << "You choose Pairi" << endl;
	else
		cout << "You choose Ggobuugi" << endl;

	strcpy(PoketMonster.aName, Name[k-1]);
	init_pokemon(k, 5);
	
	aCharactor.GetPokemon(PoketMonster);
	aCharactor.aItem.Init();

	cout << "\ninput any key to start!" << endl;
	
	cin >> a;	
	InGame();
}

void Emulator::LoadFile(){
	system("clear");
	char a;
	int i,j, skill;
	cout << "load File.................." << endl;
	FILE* rfp = fopen("./savefile.txt", "r");
	
	aCharactor.aItem.Init();
	fscanf(rfp, "%s", aCharactor.aName);
	fscanf(rfp, "%d", &aCharactor.aPokemonCnt);
	fscanf(rfp, "%d", &aCharactor.aBadges);
	fscanf(rfp, "%d", &aCharactor.aMoney);
	for(i = 0; i < aCharactor.aPokemonCnt; i++){
		fscanf(rfp, "%d", &PoketMonster.aPoketmonNum);
		fscanf(rfp, "%d", &PoketMonster.aLevel);
		fscanf(rfp, "%d", &PoketMonster.aExp);
		fscanf(rfp, "%d", &PoketMonster.aHp);
		fscanf(rfp, "%d", &PoketMonster.aAttribute);
		fscanf(rfp, "%d", &PoketMonster.aAttk);
		fscanf(rfp, "%d", &PoketMonster.aDef);
		fscanf(rfp, "%d", &PoketMonster.aSpeed);
		fscanf(rfp, "%d", &PoketMonster.aSpecialAttk);
		fscanf(rfp, "%d", &PoketMonster.aSpecialDef);
		fscanf(rfp, "%d", &PoketMonster.aSkillCnt);
		strcpy(PoketMonster.aName, Name[PoketMonster.aPoketmonNum-1]);
		PoketMonster.aSkills.erase(PoketMonster.aSkills.begin(), PoketMonster.aSkills.end());
		for(j = 0; j < PoketMonster.aSkillCnt; j++){
			fscanf(rfp, "%d", &skill);
			fscanf(rfp, "%d", &NowSkill.aCnt);
			NowSkill.aNumber = skill;
			NowSkill.aPercent = SkillPercent[skill];
			NowSkill.aType = SkillType[skill];
			PoketMonster.aSkills.push_back(NowSkill);
		}
		aCharactor.aNowPokemons.push_back(PoketMonster);
	}	
	for(i = 0; i < 5; i++){
		fscanf(rfp, "%d", &aCharactor.aItem.aCnt[i]);
	}
	fclose(rfp);
	cout << "\ninput any key to return the menu!" << endl;
	cin >> a;
	
	InGame();
	
}

void Emulator::InGame(){
	int a = 0, b = 0, i, j, k;
	while(1){
		system("clear");
		k = 0;
		a = 0;
		for(i = 1; i <= 20; i++){
			for(j = 0; j < aCharactor.aPokemonCnt; j++){
				if(aCharactor.aNowPokemons[j].aPoketmonNum == i)
					k++;
			}
		}
		if(k == 20){
			cout << "you catch all poketmonster!!    Congraturations!!!!!" << endl;
			break;
		}
		for(i = 0; i < aCharactor.aPokemonCnt; i++){
			if(aCharactor.aNowPokemons[i].aHp > 0)
				a++;
			aCharactor.aNowPokemons[i].Init();
		}
		if(a == 0){
			cout << "you lose half of your money!!" << endl;
			aCharactor.aMoney = aCharactor.aMoney / 2;
			b = 1;
			cout << "you should go to heal first!" << endl;
		}	
		a = 0;
		cout << "********************************************************************" << endl;
		cout << "*                                                                  *" << endl;
		cout << "*  1. Hunt                        2. Heal                          *" << endl;
		cout << "*  3. Vs                          4. Shop                          *" << endl;
		cout << "*  5. Gym                         6. Item                          *" << endl;
		cout << "*  7. Information                 8. Save                          *" << endl;
		cout << "*  9. Exit                                                         *" << endl;
		cout << "*                                                                  *" << endl;
		cout << "********************************************************************" << endl;
		cout << "input : ";
		while(a == 0)
			a = read_input_game();
		switch(a){
			case 1:{
				if(b == 0)
			   	 	Hunt();
			    break;
			}

			case 2:{
			    Heal();
				b = 0;
			    break;
			}

			case 3:{
				if(b == 0)
			  	  Vs();
			    break;
			}

			case 4:{
			    Shop();
			    break;
			}

			case 5:{
				if(b == 0)
			 	   Gym();
			    break;
			}

			case 6:{
			    Item();
			    break;
			}
	
			case 7:{
			    Information();
			    break;
			}

			case 8:{
			    SaveFile();
			    break;
			}

			case 9:{
			    Exit();
			    break;
			}
	  	}
		if(a == 9)
			break;
	}
}

void Emulator::Information(){
	system("clear");
	int cnt = aCharactor.aPokemonCnt;
	int i= 0, j = 0;
	char a;
	string s;

	cout << "Charactor name : " << aCharactor.aName << endl;
	cout << "PocketmonCnt : " << cnt << endl;
	cout << "Badges : " << aCharactor.aBadges << endl;
	cout << "Money : " << aCharactor.aMoney << endl;
	for(i = 0; i < cnt; i++){
		cout << "\nPokemon " << i+1 << endl;
		cout << "Name : " << aCharactor.aNowPokemons[i].aName << "\tNo : " << aCharactor.aNowPokemons[i].aPoketmonNum;
		cout << "\tLevel : " << aCharactor.aNowPokemons[i].aLevel << "\tExp : ";
		cout << aCharactor.aNowPokemons[i].aExp << "\tHp : " << aCharactor.aNowPokemons[i].aHp;
		j = aCharactor.aNowPokemons[i].aAttribute;
		if(j == NORMAL)	s = "NORMAL";
		else if(j == ELECTRIC) s = "ELECTRIC";
		else if(j == GRASS) s = "GRASS";
		else if(j == WATER) s = "WATER";
		else if(j == FIRE) s = "FIRE";
		else s = "LEGEND";
		cout << "\tAttribute : " << s << endl; 
		cout << "Attk : " << aCharactor.aNowPokemons[i].aAttk << "\tDef : " << aCharactor.aNowPokemons[i].aDef;
		cout << "\tSpeed : " << aCharactor.aNowPokemons[i].aSpeed;
		cout << "\tSpecial attk : " << aCharactor.aNowPokemons[i].aSpecialAttk;
		cout << "\tSpecial def : " << aCharactor.aNowPokemons[i].aSpecialDef << endl;
		for(j = 0 ; j < aCharactor.aNowPokemons[i].aSkills.size() ; j ++){
			cout << "Skill : " << Skills[aCharactor.aNowPokemons[i].aSkills[j].aNumber] << "\tSkill Cnt : " << aCharactor.aNowPokemons[i].aSkills[j].aCnt <<endl;
		}
	}
	cout << endl;
	for(i = 0; i < 5; i++){
		cout << "Item" << i+1 << " : " << aCharactor.aItem.aName[i] << "\tCnt : " << aCharactor.aItem.aCnt[i] << endl;
	}
	cout << "\ninput any key to return the menu!" << endl;
	cin >> a;	
	//InGame();
}

void Emulator::SaveFile(){
	system("clear");
	char a;
	int i,j;
	cout << "go to save!!!!!!!!!!!!!!!!!!!!!!" << endl;

	FILE* wfp = fopen("./savefile.txt", "w");

	fprintf(wfp, "%s\t", aCharactor.aName);
	fprintf(wfp, "%d\t", aCharactor.aPokemonCnt);
	fprintf(wfp, "%d\t", aCharactor.aBadges);
	fprintf(wfp, "%d\t", aCharactor.aMoney);
	for(i = 0; i < aCharactor.aPokemonCnt; i++){
		fprintf(wfp, "%d\t", aCharactor.aNowPokemons[i].aPoketmonNum);
		fprintf(wfp, "%d\t", aCharactor.aNowPokemons[i].aLevel);
		fprintf(wfp, "%d\t", aCharactor.aNowPokemons[i].aExp);
		fprintf(wfp, "%d\t", aCharactor.aNowPokemons[i].aHp);
		fprintf(wfp, "%d\t", aCharactor.aNowPokemons[i].aAttribute);
		fprintf(wfp, "%d\t", aCharactor.aNowPokemons[i].aAttk);
		fprintf(wfp, "%d\t", aCharactor.aNowPokemons[i].aDef);
		fprintf(wfp, "%d\t", aCharactor.aNowPokemons[i].aSpeed);
		fprintf(wfp, "%d\t", aCharactor.aNowPokemons[i].aSpecialAttk);
		fprintf(wfp, "%d\t", aCharactor.aNowPokemons[i].aSpecialDef);
		fprintf(wfp, "%d\t", aCharactor.aNowPokemons[i].aSkillCnt);
		for(j = 0; j < aCharactor.aNowPokemons[i].aSkillCnt; j++){
			fprintf(wfp, "%d\t", aCharactor.aNowPokemons[i].aSkills[j].aNumber);
			fprintf(wfp, "%d\t", aCharactor.aNowPokemons[i].aSkills[j].aCnt);
		}
	}		
	for(i = 0; i < 5 ; i++){
		fprintf(wfp, "%d\t", aCharactor.aItem.aCnt[i]);
	}
	fclose(wfp);
	cout << "\ninput any key to return the menu!" << endl;
	cin >> a;
	//InGame();
}

void Emulator::Hunt(){
	int level, huntpokenum, input = 0, input2 = 0, i = 0, j = 0, trash;
	
	level = random(1,4) + aCharactor.aBadges * 5;
	huntpokenum = random(1, (aCharactor.aBadges + 1) * 2 + 2);
	init_pokemon(huntpokenum, level);
	strcpy(PoketMonster.aName, Name[huntpokenum-1]);
	
	while(PoketMonster.aHp > 0){
		system("clear");
		if(aCharactor.aNowPokemons[i].aHp == 0){
			i++;
		}
		cout << "********************************************************************" << endl;
		cout << "                        " << Name[huntpokenum-1] << "   level : " << level << "    Hp : " << PoketMonster.aHp << endl; 
		cout << "\n\n" << aCharactor.aNowPokemons[i].aName << "   level : " << aCharactor.aNowPokemons[i].aLevel;
		cout << "    Hp : " << aCharactor.aNowPokemons[i].aHp << endl;
		cout << "********************************************************************" << endl;
		cout << " 1. skills	  2. item	3. change	4. run" << endl;
		cout << "********************************************************************" << endl;
		cin >> input;

		if(input == 1){		// skill
			cout << "skill list" << endl;
			for(j = 0; j < aCharactor.aNowPokemons[i].aSkills.size(); j++){
				cout << j+1 << ". " << Skills[aCharactor.aNowPokemons[i].aSkills[j].aNumber] << "\tcnt : ";
				cout << aCharactor.aNowPokemons[i].aSkills[j].aCnt << endl;
			}
			cin >> input2;
			system("clear");
			fighting(i, input2, 0);
			cout << "********************************************************************" << endl;
			cout << "                        " << Name[huntpokenum-1] << "   level : " << level << "    Hp : " << PoketMonster.aHp << endl; 
			cout << "\n\n" << aCharactor.aNowPokemons[i].aName << "   level : " << aCharactor.aNowPokemons[i].aLevel;
			cout << "    Hp : " << aCharactor.aNowPokemons[i].aHp << endl;
			cout << "********************************************************************" << endl;
			if(PoketMonster.aHp <= 0){
				cout << "You Win!!" << endl;
				aCharactor.aNowPokemons[i].aExp += level;
				trash = PoketMonster.aLevel*50;
				aCharactor.GetMoney(trash);
				cout << "Earn " << trash << endl;
				if(aCharactor.aNowPokemons[i].aExp > (aCharactor.aNowPokemons[i].aLevel*2)){
					aCharactor.aNowPokemons[i].LevelUp();
					cout << aCharactor.aNowPokemons[i].aName << "'s level up!!" << endl;
				}
				break;
			}
			else if(aCharactor.aNowPokemons[i].aHp <= 0){
				cout << "your " << aCharactor.aNowPokemons[i].aName << " is dead" << endl;
				cout << "push any button" << endl;
				cin >> trash;
				int a = 0;
				for(j = 0; j < aCharactor.aPokemonCnt; j++){
					if(aCharactor.aNowPokemons[j].aHp > 0)
						a++;
				}
				if(a == 0){
					cout << "your pokemons are all dead!!" << endl;
					break;
				}				
				else {
					cout << "Poketmon list" << endl;
					input2 = 0;
					while(input2 == 0){
						for(j = 0; j < aCharactor.aNowPokemons.size(); j++){
							cout << j+1 << ". " << aCharactor.aNowPokemons[j].aName << "\tLevel : ";
							cout << aCharactor.aNowPokemons[j].aLevel << "\tHp : ";
							cout << aCharactor.aNowPokemons[j].aHp << endl;
						}
						cin >> input2;
						if(input2 <= aCharactor.aNowPokemons.size()){
							if(aCharactor.aNowPokemons[input2-1].aHp > 0)
								i = input2-1;
							else 
								input2 = 0;
						}
						else	input2 = 0;
					}
				}
			}
			else{
				cout << "push any button" << endl;
				cin >> trash;
			}
			system("clear");
			fighting(i, input2, 1);
			cout << "********************************************************************" << endl;
			cout << "                        " << Name[huntpokenum-1] << "   level : " << level << "    Hp : " << PoketMonster.aHp << endl; 
			cout << "\n\n" << aCharactor.aNowPokemons[i].aName << "   level : " << aCharactor.aNowPokemons[i].aLevel;
			cout << "    Hp : " << aCharactor.aNowPokemons[i].aHp << endl;
			cout << "********************************************************************" << endl;
			if(PoketMonster.aHp <= 0){
				cout << "You Win!!" << endl;
				aCharactor.aNowPokemons[i].aExp += level;
				trash = PoketMonster.aLevel*50;
				aCharactor.GetMoney(trash);
				cout << "Earn " << trash << endl;
				if(aCharactor.aNowPokemons[i].aExp > (aCharactor.aNowPokemons[i].aLevel*2)){
					aCharactor.aNowPokemons[i].LevelUp();
					cout << aCharactor.aNowPokemons[i].aName << "'s level up!!" << endl;
				}
				break;
			}
			else if(aCharactor.aNowPokemons[i].aHp <= 0){
				cout << "your " << aCharactor.aNowPokemons[i].aName << " is dead" << endl;
				cout << "push any button" << endl;
				cin >> trash;
				int a = 0;
				for(j = 0; j < aCharactor.aPokemonCnt; j++){
					if(aCharactor.aNowPokemons[j].aHp > 0)
						a++;
				}
				if(a == 0){
					cout << "your pokemons are all dead!!" << endl;
					break;
				}				
				else {
					cout << "Poketmon list" << endl;
					input2 = 0;
					while(input2 == 0){
						for(j = 0; j < aCharactor.aNowPokemons.size(); j++){
							cout << j+1 << ". " << aCharactor.aNowPokemons[j].aName << "\tLevel : ";
							cout << aCharactor.aNowPokemons[j].aLevel << "\tHp : ";
							cout << aCharactor.aNowPokemons[j].aHp << endl;
						}
						cin >> input2;
						if(input2 <= aCharactor.aNowPokemons.size()){
							if(aCharactor.aNowPokemons[input2-1].aHp > 0)
								i = input2-1;
							else 
								input2 = 0;
						}
						else	input2 = 0;
					}
				}
			}
			else{
				cout << "push any button" << endl;
				cin >> trash;
			}
		}	
		else if(input == 2){			// item
			system("clear");
			cout << "********************************************************************" << endl;
			cout << "   1. PoketBall("<< aCharactor.aItem.aCnt[0] << ")" << endl;
			cout << "   2. LevelCandy("<< aCharactor.aItem.aCnt[1] << ")" << endl;
			cout << "   3. PotionLow("<< aCharactor.aItem.aCnt[2] << ")" << endl;
			cout << "   4. PotionMid("<< aCharactor.aItem.aCnt[3] << ")" << endl;
			cout << "   5. PotionHigh("<< aCharactor.aItem.aCnt[4] << ")" << endl;
			cout << "   6. Exit" << endl;
			cout << "********************************************************************" << endl;
			cin >> input2;
			if((input2 < 6) && (input2 > 0)){
				if(aCharactor.aItem.aCnt[input2-1] > 0){
					aCharactor.UsingItem(input2-1);
					switch(input2){
						case 1:{
							if(random(0, PoketMonster.aLevel * Hp[PoketMonster.aPoketmonNum-1]) > PoketMonster.aHp){
								aCharactor.GetPokemon(PoketMonster);
								cout << "Success to catch " << PoketMonster.aName << "!!" <<endl;
								PoketMonster.aHp = 0;
							}
							else{
								cout << "Fail to catch!!" << endl;
								cout << "push any button" << endl;
								cin >> trash;
							}
							break;
						}
						case 2:{
							aCharactor.aNowPokemons[i].LevelCandyUp();
							cout << aCharactor.aNowPokemons[i].aName << " level up!!" << endl;
							cout << "push any button" << endl;
							cin >> trash;
							break;
						}
						case 3:{
							aCharactor.aNowPokemons[i].HpUp(300);
							cout << aCharactor.aNowPokemons[i].aName << " charge 300 Hps!!" << endl; 
							cout << "push any button" << endl;
							cin >> trash;
							break;
						}
						case 4:{
							aCharactor.aNowPokemons[i].HpUp(600);
							cout << aCharactor.aNowPokemons[i].aName << " charge 600 Hps!!" << endl; 
							cout << "push any button" << endl;
							cin >> trash;
							break;
						}
						case 5:{
							aCharactor.aNowPokemons[i].HpUp(1300);
							cout << aCharactor.aNowPokemons[i].aName << " charge 1300 Hps!!" << endl; 
							cout << "push any button" << endl;
							cin >> trash;
							break;
						}				
					}
				}
			}
			else if(input2 == 6){
				input2 = 0;
				input = 0;
			}
		}
		else if(input == 3){	// poketmon change
			cout << "Poketmon list" << endl;
			for(j = 0; j < aCharactor.aNowPokemons.size(); j++){
				cout << j+1 << ". " << aCharactor.aNowPokemons[j].aName << "\tLevel : ";
				cout << aCharactor.aNowPokemons[j].aLevel << "\tHp : ";
				cout << aCharactor.aNowPokemons[j].aHp << endl;
			}////////////////////////////////////////////////////////////////////////
			cin >> input2;
			if(input2 <= aCharactor.aNowPokemons.size()){
				i = input2-1;
			}
		}
		else if(input == 4)
			break;
	}

	if(input != 4){
		cout << "\ninput any key to return the menu!" << endl;
		cin >> input;
	}
		
	//InGame();
}

void Emulator::Heal(){
	system("clear");
	char a;
	int i = 0, j = 0, cnt = aCharactor.aPokemonCnt;
	int pokenum = 0;
	cout << "Now, your poketmons have full hp" << endl;
	for(i = 0; i < cnt ; i++){
		pokenum = aCharactor.aNowPokemons[i].aPoketmonNum - 1;
		aCharactor.aNowPokemons[i].aHp = Hp[pokenum]*aCharactor.aNowPokemons[i].aLevel;
		for(j = 0; j < aCharactor.aNowPokemons[i].aSkills.size(); j++){
			aCharactor.aNowPokemons[i].aSkills[j].aCnt = init_skill(aCharactor.aNowPokemons[i].aSkills[j].aNumber);
		}
	}

	cout << "\ninput any key to return the menu!" << endl;
	cin >> a;
	//InGame();
}

void Emulator::Shop(){
	char a;
	int input = 0, input2 = 0;
	while(1){
		if(input == 1){
			system("clear");
			cout << "Current Money : " << aCharactor.aMoney << endl;
			cout << "********************************************************************" << endl;
			cout << "   1. PoketBall("<< aCharactor.aItem.aCnt[0] << ") : " << aCharactor.aItem.aPrice[0] << endl;
			cout << "   2. LevelCandy("<< aCharactor.aItem.aCnt[1] << ") : " << aCharactor.aItem.aPrice[1] << endl;
			cout << "   3. PotionLow("<< aCharactor.aItem.aCnt[2] << ") : " << aCharactor.aItem.aPrice[2] << endl;
			cout << "   4. PotionMid("<< aCharactor.aItem.aCnt[3] << ") : " << aCharactor.aItem.aPrice[3] << endl;
			cout << "   5. PotionHigh("<< aCharactor.aItem.aCnt[4] << ") : " << aCharactor.aItem.aPrice[4] << endl;
			cout << "   6. Exit" << endl;
			cout << "********************************************************************" << endl;
			cin >> input2;
			if((input2 < 6) && (input2 > 0)){
				aCharactor.BuyItem(input2-1);
			}
			else if(input2 == 6){
				input2 = 0;
				input = 0;
			}
		}
		else if(input == 2){
			system("clear");
			cout << "Current Money : " << aCharactor.aMoney << endl;
			cout << "********************************************************************" << endl;
			cout << "   1. PoketBall("<< aCharactor.aItem.aCnt[0] << ") : " << aCharactor.aItem.aPrice[0] << endl;
			cout << "   2. LevelCandy("<< aCharactor.aItem.aCnt[1] << ") : " << aCharactor.aItem.aPrice[1] << endl;
			cout << "   3. PotionLow("<< aCharactor.aItem.aCnt[2] << ") : " << aCharactor.aItem.aPrice[2] << endl;
			cout << "   4. PotionMid("<< aCharactor.aItem.aCnt[3] << ") : " << aCharactor.aItem.aPrice[3] << endl;
			cout << "   5. PotionHigh("<< aCharactor.aItem.aCnt[4] << ") : " << aCharactor.aItem.aPrice[4] << endl;
			cout << "   6. Exit" << endl;
			cout << "********************************************************************" << endl;
			cin >> input2;
			if((input2 < 6) && (input2 > 0)){
				aCharactor.SellItem(input2-1);
			}
			else if(input2 == 6){
				input2 = 0;
				input = 0;
			}
		}
		else if(input == 3){
			break;
		}
		else{
			system("clear");
			cout << "********************************************************************" << endl;
			cout << "	1. Buy			2. Sell			3. Exit" << endl;
			cout << "********************************************************************" << endl;
			cin >> input;
		}
	}

	cout << "\ninput any key to return the menu!" << endl;
	cin >> a;
	//InGame();
}

void Emulator::Item(){
	char a;
	int input = 0, input2 = 0, i = 0, trash;
	while(input == 0){
		system("clear");
		cout << "********************************************************************" << endl;
		cout << "   1. PoketBall("<< aCharactor.aItem.aCnt[0] << ")" << endl;
		cout << "   2. LevelCandy("<< aCharactor.aItem.aCnt[1] << ")" << endl;
		cout << "   3. PotionLow("<< aCharactor.aItem.aCnt[2] << ")" << endl;
		cout << "   4. PotionMid("<< aCharactor.aItem.aCnt[3] << ")" << endl;
		cout << "   5. PotionHigh("<< aCharactor.aItem.aCnt[4] << ")" << endl;
		cout << "   6. Exit" << endl;
		cout << "********************************************************************" << endl;
		cin >> input;
		if((input < 6) && (input > 1)){
			if(aCharactor.aItem.aCnt[input-1] > 0){
				aCharactor.UsingItem(input-1);
				switch(input){
					case 2:{
						system("clear");
						cout << "Use Level candy!!" << endl;
						for(i = 0; i < aCharactor.aNowPokemons.size(); i++){
							cout << i+1 << ". " << aCharactor.aNowPokemons[i].aName << "\tLevel : " << aCharactor.aNowPokemons[i].aLevel << endl;
						}
						cout << "Which poketmon??" << endl;
						cin >> input2;
						i = input2 - 1;
						if(i < aCharactor.aNowPokemons.size()){
							aCharactor.aNowPokemons[i].LevelCandyUp();
							cout << aCharactor.aNowPokemons[i].aName << " level up!!" << endl;
							cout << "push any button" << endl;
							cin >> trash;
						}
						else 
							aCharactor.aItem.aCnt[input-1]++;
						input = 0;
						break;
					}
					case 3:{
						system("clear");
						cout << "Use PotionLow!!" << endl;
						for(i = 0; i < aCharactor.aNowPokemons.size(); i++){
							cout << i+1 << ". " << aCharactor.aNowPokemons[i].aName << "\tLevel : " << aCharactor.aNowPokemons[i].aLevel << endl;
						}
						cout << "Which poketmon??" << endl;
						cin >> input2;
						i = input2 - 1;
						if(i < aCharactor.aNowPokemons.size()){
							aCharactor.aNowPokemons[i].HpUp(300);
							cout << aCharactor.aNowPokemons[i].aName << " charge 300 Hps!!" << endl; 
							cout << "push any button" << endl;
							cin >> trash;
						}
						else 
							aCharactor.aItem.aCnt[input-1]++;
						input = 0;
						break;
					}
					case 4:{
						system("clear");
						cout << "Use PotionMid!!" << endl;
						for(i = 0; i < aCharactor.aNowPokemons.size(); i++){
							cout << i+1 << ". " << aCharactor.aNowPokemons[i].aName << "\tLevel : " << aCharactor.aNowPokemons[i].aLevel << endl;
						}
						cout << "Which poketmon??" << endl;
						cin >> input2;
						i = input2 - 1;
						if(i < aCharactor.aNowPokemons.size()){
							aCharactor.aNowPokemons[i].HpUp(600);
							cout << aCharactor.aNowPokemons[i].aName << " charge 600 Hps!!" << endl; 
							cout << "push any button" << endl;
							cin >> trash;
						}
						else 
							aCharactor.aItem.aCnt[input-1]++;
						input = 0;
						break;
					}
					case 5:{
						system("clear");
						cout << "Use PotionHigh!!" << endl;
						for(i = 0; i < aCharactor.aNowPokemons.size(); i++){
							cout << i+1 << ". " << aCharactor.aNowPokemons[i].aName << "\tLevel : " << aCharactor.aNowPokemons[i].aLevel << endl;
						}
						cout << "Which poketmon??" << endl;
						cin >> input2;
						i = input2 - 1;
						if(i < aCharactor.aNowPokemons.size()){
							aCharactor.aNowPokemons[i].HpUp(1300);
							cout << aCharactor.aNowPokemons[i].aName << " charge 1300 Hps!!" << endl; 
							cout << "push any button" << endl;
							cin >> trash;
						}
						else 
							aCharactor.aItem.aCnt[input-1]++;
						input = 0;
						break;
					}				
				}
			}
			else{
				cout << "Lack of this item!!" << endl;
				input = 0;
			}
		}
		else if(input == 1){
			cout << "You can't use this Item now!!" << endl;
			input = 0;
		}
	}
	cout << "\ninput any key to return the menu!" << endl;
	cin >> a;
	//InGame();
}

void Emulator::Vs(){
	int cnt, level, huntpokenum, input = 0, input2 = 0, i = 0, j = 0, trash ,a;
	cnt = 0;
	system("clear");
	cout << "********************************************************************" << endl;
	cout << " Trainer Name : " << VsName[random(0, 12)] << "\t\tPokemon_cnt : " << (aCharactor.aBadges / 2) + 1 << endl;
	cout << "********************************************************************" << endl;
	cout << "push any button" << endl;
	cin >> trash;
	while(cnt++ < (aCharactor.aBadges / 2) + 1){
		
		level = random(1,4) + (aCharactor.aBadges + 1) * 5;
		huntpokenum = random(1, (aCharactor.aBadges + 1) * 2 + 2);
		init_pokemon(huntpokenum, level);
		strcpy(PoketMonster.aName, Name[huntpokenum-1]);
	
		while(PoketMonster.aHp > 0){
			system("clear");
			cout << "********************************************************************" << endl;
			cout << "                        " << Name[huntpokenum-1] << "   level : " << level << "    Hp : " << PoketMonster.aHp << endl; 
			cout << "\n\n" << aCharactor.aNowPokemons[i].aName << "   level : " << aCharactor.aNowPokemons[i].aLevel;
			cout << "    Hp : " << aCharactor.aNowPokemons[i].aHp << endl;
			cout << "********************************************************************" << endl;
			cout << " 1. skills	  2. item	3. change" << endl;
			cout << "********************************************************************" << endl;
			cin >> input;

			if(input == 1){		// skill
				cout << "skill list" << endl;
				for(j = 0; j < aCharactor.aNowPokemons[i].aSkills.size(); j++){
					cout << j+1 << ". " << Skills[aCharactor.aNowPokemons[i].aSkills[j].aNumber] << "\tcnt : ";
					cout << aCharactor.aNowPokemons[i].aSkills[j].aCnt << endl;
				}
				cin >> input2;
				system("clear");
				fighting(i, input2, 0);
				cout << "********************************************************************" << endl;
				cout << "                        " << Name[huntpokenum-1] << "   level : " << level << "    Hp : " << PoketMonster.aHp << endl; 
				cout << "\n\n" << aCharactor.aNowPokemons[i].aName << "   level : " << aCharactor.aNowPokemons[i].aLevel;
				cout << "    Hp : " << aCharactor.aNowPokemons[i].aHp << endl;
				cout << "********************************************************************" << endl;
				if(PoketMonster.aHp <= 0){
					cout << "You Win!!" << endl;
					aCharactor.aNowPokemons[i].aExp += level;
					
					if(aCharactor.aNowPokemons[i].aExp > (aCharactor.aNowPokemons[i].aLevel*2)){
						aCharactor.aNowPokemons[i].LevelUp();
						cout << aCharactor.aNowPokemons[i].aName << "'s level up!!" << endl;
					}
					break;
				}
				else if(aCharactor.aNowPokemons[i].aHp <= 0){
					cout << "your " << aCharactor.aNowPokemons[i].aName << " is dead" << endl;
					cout << "push any button" << endl;
					cin >> trash;
					a = 0;
					for(j = 0; j < aCharactor.aPokemonCnt; j++){
						if(aCharactor.aNowPokemons[j].aHp > 0)
							a++;
					}
					if(a == 0){
						cout << "your pokemons are all dead!!" << endl;
						break;
					}				
					else {
						cout << "Poketmon list" << endl;
						input2 = 0;
						while(input2 == 0){
							for(j = 0; j < aCharactor.aNowPokemons.size(); j++){
								cout << j+1 << ". " << aCharactor.aNowPokemons[j].aName << "\tLevel : ";
								cout << aCharactor.aNowPokemons[j].aLevel << "\tHp : ";
								cout << aCharactor.aNowPokemons[j].aHp << endl;
							}
							cin >> input2;
							if(input2 <= aCharactor.aNowPokemons.size()){
								if(aCharactor.aNowPokemons[input2-1].aHp > 0)
									i = input2-1;
								else 
									input2 = 0;
							}
							else	input2 = 0;
						}
					}
				}
				else{
					cout << "push any button" << endl;
					cin >> trash;
				}
				system("clear");
				fighting(i, input2, 1);
				cout << "********************************************************************" << endl;
				cout << "                        " << Name[huntpokenum-1] << "   level : " << level << "    Hp : " << PoketMonster.aHp << endl; 
				cout << "\n\n" << aCharactor.aNowPokemons[i].aName << "   level : " << aCharactor.aNowPokemons[i].aLevel;
				cout << "    Hp : " << aCharactor.aNowPokemons[i].aHp << endl;
				cout << "********************************************************************" << endl;
				if(PoketMonster.aHp <= 0){
					cout << "You Win!!" << endl;
					aCharactor.aNowPokemons[i].aExp += level;
					
					if(aCharactor.aNowPokemons[i].aExp > (aCharactor.aNowPokemons[i].aLevel*2)){
						aCharactor.aNowPokemons[i].LevelUp();
						cout << aCharactor.aNowPokemons[i].aName << "'s level up!!" << endl;
					}
					break;
				}
				else if(aCharactor.aNowPokemons[i].aHp <= 0){
					cout << "your " << aCharactor.aNowPokemons[i].aName << " is dead" << endl;
					cout << "push any button" << endl;
					cin >> trash;
					a = 0;
					for(j = 0; j < aCharactor.aPokemonCnt; j++){
						if(aCharactor.aNowPokemons[j].aHp > 0)
							a++;
					}
					if(a == 0){
						cout << "your pokemons are all dead!!" << endl;
						break;
					}				
					else {
						cout << "Poketmon list" << endl;
						input2 = 0;
						while(input2 == 0){
							for(j = 0; j < aCharactor.aNowPokemons.size(); j++){
								cout << j+1 << ". " << aCharactor.aNowPokemons[j].aName << "\tLevel : ";
								cout << aCharactor.aNowPokemons[j].aLevel << "\tHp : ";
								cout << aCharactor.aNowPokemons[j].aHp << endl;
							}
							cin >> input2;
							if(input2 <= aCharactor.aNowPokemons.size()){
								if(aCharactor.aNowPokemons[input2-1].aHp > 0)
									i = input2-1;
								else 
									input2 = 0;
							}
							else	input2 = 0;
						}
					}
				}
				else{
					cout << "push any button" << endl;
					cin >> trash;
				}
			}	
			else if(input == 2){			// item
				system("clear");
				cout << "********************************************************************" << endl;
				cout << "   1. PoketBall("<< aCharactor.aItem.aCnt[0] << ")" << endl;
				cout << "   2. LevelCandy("<< aCharactor.aItem.aCnt[1] << ")" << endl;
				cout << "   3. PotionLow("<< aCharactor.aItem.aCnt[2] << ")" << endl;
				cout << "   4. PotionMid("<< aCharactor.aItem.aCnt[3] << ")" << endl;
				cout << "   5. PotionHigh("<< aCharactor.aItem.aCnt[4] << ")" << endl;
				cout << "   6. Exit" << endl;
				cout << "********************************************************************" << endl;
				cin >> input2;
				if((input2 < 6) && (input2 > 0)){
					if(aCharactor.aItem.aCnt[input2-1] > 0){
						aCharactor.UsingItem(input2-1);
						switch(input2){
							case 1:{
								cout << "you can't catch this pokemon!!" << endl;
								cin >> trash;
								
								break;
							}
							case 2:{
								aCharactor.aNowPokemons[i].LevelCandyUp();
								cout << aCharactor.aNowPokemons[i].aName << " level up!!" << endl;
								cout << "push any button" << endl;
								cin >> trash;
								break;
							}
							case 3:{
								aCharactor.aNowPokemons[i].HpUp(300);
								cout << aCharactor.aNowPokemons[i].aName << " charge 300 Hps!!" << endl; 
								cout << "push any button" << endl;
								cin >> trash;
								break;
							}
							case 4:{
								aCharactor.aNowPokemons[i].HpUp(600);
								cout << aCharactor.aNowPokemons[i].aName << " charge 600 Hps!!" << endl; 
								cout << "push any button" << endl;
								cin >> trash;
								break;
							}
							case 5:{
								aCharactor.aNowPokemons[i].HpUp(1300);
								cout << aCharactor.aNowPokemons[i].aName << " charge 1300 Hps!!" << endl; 
								cout << "push any button" << endl;
								cin >> trash;
								break;
							}				
						}
					}
				}
				else if(input2 == 6){
					input2 = 0;
					input = 0;
				}
			}
			else if(input == 3){	// poketmon change
				cout << "Poketmon list" << endl;
				for(j = 0; j < aCharactor.aNowPokemons.size(); j++){
					cout << j+1 << ". " << aCharactor.aNowPokemons[j].aName << "\tLevel : ";
					cout << aCharactor.aNowPokemons[j].aLevel << "\tHp : ";
					cout << aCharactor.aNowPokemons[j].aHp << endl;
				}
				cin >> input2;
				if(input2 <= aCharactor.aNowPokemons.size()){
					i = input2-1;
				}
			}
		}
		a = 0;
		for(j = 0; j < aCharactor.aPokemonCnt; j++){
			if(aCharactor.aNowPokemons[j].aHp > 0)
				a++;
		}
		if(a == 0){
			cout << "you lose!!" << endl;
			break;
		}
		else{
			cout << "push any button" << endl;
			cin >> trash;
		}				
	}

	if(PoketMonster.aHp <= 0){
		trash = (aCharactor.aBadges + 1)*500;
		aCharactor.GetMoney(trash);
		cout << "Earn " << trash << endl;
	}
	cout << "\ninput any key to return the menu!" << endl;
	cin >> input;

	//InGame();
}

void Emulator::Gym(){
	int cnt, level, huntpokenum, input = 0, input2 = 0, i = 0, j = 0, trash, a;
	cnt = 0;
	system("clear");
	cout << "********************************************************************" << endl;
	cout << " Gym Name : " << GymName[aCharactor.aBadges] << "\t\tPokemon_cnt : " << (aCharactor.aBadges / 2) + 2 << endl;
	cout << "********************************************************************" << endl;
	cout << "push any button" << endl;
	cin >> trash;
	cnt = 0;
	while(cnt++ < (aCharactor.aBadges / 2) + 2){
		if(aCharactor.aBadges < 8){
			level = random(1,4) + (aCharactor.aBadges + 2) * 5;
			huntpokenum = random(1, (aCharactor.aBadges + 2) * 2 + 2);
			init_pokemon(huntpokenum, level);
			strcpy(PoketMonster.aName, Name[huntpokenum-1]);
		}
		else{
			level = 60;
			huntpokenum = 20;
			init_pokemon(huntpokenum, level);
			strcpy(PoketMonster.aName, Name[huntpokenum-1]);
		}
	
		while(PoketMonster.aHp > 0){
			system("clear");
			cout << "********************************************************************" << endl;
			cout << "                        " << Name[huntpokenum-1] << "   level : " << level << "    Hp : " << PoketMonster.aHp << endl; 
			cout << "\n\n" << aCharactor.aNowPokemons[i].aName << "   level : " << aCharactor.aNowPokemons[i].aLevel;
			cout << "    Hp : " << aCharactor.aNowPokemons[i].aHp << endl;
			cout << "********************************************************************" << endl;
			cout << " 1. skills	  2. item	3. change" << endl;
			cout << "********************************************************************" << endl;
			cin >> input;

			if(input == 1){		// skill
				cout << "skill list" << endl;
				for(j = 0; j < aCharactor.aNowPokemons[i].aSkills.size(); j++){
					cout << j+1 << ". " << Skills[aCharactor.aNowPokemons[i].aSkills[j].aNumber] << "\tcnt : ";
					cout << aCharactor.aNowPokemons[i].aSkills[j].aCnt << endl;
				}
				cin >> input2;
				system("clear");
				fighting(i, input2, 0);
				cout << "********************************************************************" << endl;
				cout << "                        " << Name[huntpokenum-1] << "   level : " << level << "    Hp : " << PoketMonster.aHp << endl; 
				cout << "\n\n" << aCharactor.aNowPokemons[i].aName << "   level : " << aCharactor.aNowPokemons[i].aLevel;
				cout << "    Hp : " << aCharactor.aNowPokemons[i].aHp << endl;
				cout << "********************************************************************" << endl;
				if(PoketMonster.aHp <= 0){
					cout << "You Win!!" << endl;
					aCharactor.aNowPokemons[i].aExp += level;
					
					if(aCharactor.aNowPokemons[i].aExp > (aCharactor.aNowPokemons[i].aLevel*2)){
						aCharactor.aNowPokemons[i].LevelUp();
						cout << aCharactor.aNowPokemons[i].aName << "'s level up!!" << endl;
					}
					break;
				}
				else if(aCharactor.aNowPokemons[i].aHp <= 0){
					cout << "your " << aCharactor.aNowPokemons[i].aName << " is dead" << endl;
					cout << "push any button" << endl;
					cin >> trash;
					a = 0;
					for(j = 0; j < aCharactor.aPokemonCnt; j++){
						if(aCharactor.aNowPokemons[j].aHp > 0)
							a++;
					}
					if(a == 0){
						cout << "your pokemons are all dead!!" << endl;
						break;
					}				
					else {
						cout << "Poketmon list" << endl;
						input2 = 0;
						while(input2 == 0){
							for(j = 0; j < aCharactor.aNowPokemons.size(); j++){
								cout << j+1 << ". " << aCharactor.aNowPokemons[j].aName << "\tLevel : ";
								cout << aCharactor.aNowPokemons[j].aLevel << "\tHp : ";
								cout << aCharactor.aNowPokemons[j].aHp << endl;
							}
							cin >> input2;
							if(input2 <= aCharactor.aNowPokemons.size()){
								if(aCharactor.aNowPokemons[input2-1].aHp > 0)
									i = input2-1;
								else 
									input2 = 0;
							}
							else	input2 = 0;
						}
					}
				}
				else{
					cout << "push any button" << endl;
					cin >> trash;
				}
				system("clear");
				fighting(i, input2, 1);
				cout << "********************************************************************" << endl;
				cout << "                        " << Name[huntpokenum-1] << "   level : " << level << "    Hp : " << PoketMonster.aHp << endl; 
				cout << "\n\n" << aCharactor.aNowPokemons[i].aName << "   level : " << aCharactor.aNowPokemons[i].aLevel;
				cout << "    Hp : " << aCharactor.aNowPokemons[i].aHp << endl;
				cout << "********************************************************************" << endl;
				if(PoketMonster.aHp <= 0){
					cout << "You Win!!" << endl;
					aCharactor.aNowPokemons[i].aExp += level;
					
					if(aCharactor.aNowPokemons[i].aExp > (aCharactor.aNowPokemons[i].aLevel*2)){
						aCharactor.aNowPokemons[i].LevelUp();
						cout << aCharactor.aNowPokemons[i].aName << "'s level up!!" << endl;
					}
					break;
				}
				else if(aCharactor.aNowPokemons[i].aHp <= 0){
					cout << "your " << aCharactor.aNowPokemons[i].aName << " is dead" << endl;
					cout << "push any button" << endl;
					cin >> trash;
					a = 0;
					for(j = 0; j < aCharactor.aPokemonCnt; j++){
						if(aCharactor.aNowPokemons[j].aHp > 0)
							a++;
					}
					if(a == 0){
						cout << "your pokemons are all dead!!" << endl;
						break;
					}				
					else {
						cout << "Poketmon list" << endl;
						input2 = 0;
						while(input2 == 0){
							for(j = 0; j < aCharactor.aNowPokemons.size(); j++){
								cout << j+1 << ". " << aCharactor.aNowPokemons[j].aName << "\tLevel : ";
								cout << aCharactor.aNowPokemons[j].aLevel << "\tHp : ";
								cout << aCharactor.aNowPokemons[j].aHp << endl;
							}
							cin >> input2;
							if(input2 <= aCharactor.aNowPokemons.size()){
								if(aCharactor.aNowPokemons[input2-1].aHp > 0)
									i = input2-1;
								else 
									input2 = 0;
							}
							else	input2 = 0;
						}
					}
				}
				else{
					cout << "push any button" << endl;
					cin >> trash;
				}
			}	
			else if(input == 2){			// item
				system("clear");
				cout << "********************************************************************" << endl;
				cout << "   1. PoketBall("<< aCharactor.aItem.aCnt[0] << ")" << endl;
				cout << "   2. LevelCandy("<< aCharactor.aItem.aCnt[1] << ")" << endl;
				cout << "   3. PotionLow("<< aCharactor.aItem.aCnt[2] << ")" << endl;
				cout << "   4. PotionMid("<< aCharactor.aItem.aCnt[3] << ")" << endl;
				cout << "   5. PotionHigh("<< aCharactor.aItem.aCnt[4] << ")" << endl;
				cout << "   6. Exit" << endl;
				cout << "********************************************************************" << endl;
				cin >> input2;
				if((input2 < 6) && (input2 > 0)){
					if(aCharactor.aItem.aCnt[input2-1] > 0){
						aCharactor.UsingItem(input2-1);
						switch(input2){
							case 1:{
								cout << "you can't catch this pokemon!!" << endl;
								cin >> trash;
								
								break;
							}
							case 2:{
								aCharactor.aNowPokemons[i].LevelCandyUp();
								cout << aCharactor.aNowPokemons[i].aName << " level up!!" << endl;
								cout << "push any button" << endl;
								cin >> trash;
								break;
							}
							case 3:{
								aCharactor.aNowPokemons[i].HpUp(300);
								cout << aCharactor.aNowPokemons[i].aName << " charge 300 Hps!!" << endl; 
								cout << "push any button" << endl;
								cin >> trash;
								break;
							}
							case 4:{
								aCharactor.aNowPokemons[i].HpUp(600);
								cout << aCharactor.aNowPokemons[i].aName << " charge 600 Hps!!" << endl; 
								cout << "push any button" << endl;
								cin >> trash;
								break;
							}
							case 5:{
								aCharactor.aNowPokemons[i].HpUp(1300);
								cout << aCharactor.aNowPokemons[i].aName << " charge 1300 Hps!!" << endl; 
								cout << "push any button" << endl;
								cin >> trash;
								break;
							}				
						}
					}
				}
				else if(input2 == 6){
					input2 = 0;
					input = 0;
				}
			}
			else if(input == 3){	// poketmon change
				cout << "Poketmon list" << endl;
				for(j = 0; j < aCharactor.aNowPokemons.size(); j++){
					cout << j+1 << ". " << aCharactor.aNowPokemons[j].aName << "\tLevel : ";
					cout << aCharactor.aNowPokemons[j].aLevel << "\tHp : ";
					cout << aCharactor.aNowPokemons[j].aHp << endl;
				}
				cin >> input2;
				if(input2 <= aCharactor.aNowPokemons.size()){
					i = input2-1;
				}
			}
		}
		a = 0;
		for(j = 0; j < aCharactor.aPokemonCnt; j++){
			if(aCharactor.aNowPokemons[j].aHp > 0)
				a++;
		}
		if(a == 0){
			cout << "you lose!!" << endl;
			break;
		}	
		else{
			cout << "push any button" << endl;
			cin >> trash;
		}			
	}
	if(PoketMonster.aHp <= 0){
		trash = (aCharactor.aBadges + 1)*1000;
		aCharactor.GetMoney(trash);
		if(aCharactor.aBadges < 8)
			aCharactor.GetBadge();
		cout << "Earn " << trash << endl;
	}
	cout << "\ninput any key to return the menu!" << endl;
	cin >> input;

	//InGame();
}

void Emulator::Exit(){
	system("clear");
	cout << "Exit!!!!!!!!!!!!!!!!!!!!!!!" << endl;
}


void Emulator::fighting(int i, int input2, bool b){
	int skillnum, skilltype, attack, enemy_rand;
	enemy_rand = random(0, PoketMonster.aSkills.size()-1);
	if(b){		// slower action(second action)
		if(aCharactor.aNowPokemons[i].aSpeed >= PoketMonster.aSpeed)
			b = 0;
	}
	else {		// speeder action(first action)
		if(aCharactor.aNowPokemons[i].aSpeed >= PoketMonster.aSpeed)
			b = 1;
	}

	if((b == 1) && (aCharactor.aNowPokemons[i].aSkills[input2-1].aCnt > 0)){
		skillnum = aCharactor.aNowPokemons[i].aSkills[input2-1].aNumber;
		aCharactor.aNowPokemons[i].aSkills[input2-1].aCnt--;
		skilltype = SkillType[skillnum];
		switch(skilltype){
			case NORMAL:{
				if(skillnum == 17){		// Self Bomb
					attack = aCharactor.aNowPokemons[i].aAttk * SkillPercent[skillnum] / 40;;
					cout << Skills[skillnum] << "\t";
					cout << "Self Bomb!!" << endl;
					attack -= (PoketMonster.aDef/5);
					if(attack <= 0)	attack = 1;
					PoketMonster.aHp -= attack;
					if(PoketMonster.aHp < 0) PoketMonster.aHp = 0;
					aCharactor.aNowPokemons[i].aHp = 0;
				}
				else{
					attack = aCharactor.aNowPokemons[i].aAttk * SkillPercent[skillnum] / 40;
					cout << Skills[skillnum] << "\t";
					if(PoketMonster.aAttribute == ELECTRIC){
						cout << "It was very powerful!!" << endl;
						attack = attack * 2;
					}
					else if(PoketMonster.aAttribute == LEGEND){
						cout << "It was weak!!" << endl;
						attack = attack / 2;
					}
					else{
						cout << "It was normal damage!!" << endl;
					}
					attack -= (PoketMonster.aDef/3);
					if(attack <= 0)	attack = 1;
					PoketMonster.aHp -= attack;
					if(PoketMonster.aHp < 0) PoketMonster.aHp = 0;
				}
				break;				
			}
			case ELECTRIC:{
				attack = aCharactor.aNowPokemons[i].aSpecialAttk * SkillPercent[skillnum] / 40;
				cout << Skills[skillnum] << "\t";
				if((PoketMonster.aAttribute == GRASS) || (PoketMonster.aAttribute == WATER) || (PoketMonster.aAttribute == FIRE)){
					cout << "It was powerful!!" << endl;
					attack = attack * 3 / 2;
				}
				else if((PoketMonster.aAttribute == NORMAL) || (PoketMonster.aAttribute == LEGEND)){
					cout << "It was weak!!" << endl;
					attack = attack / 2;
				}
				else{
					cout << "It was normal damage!!" << endl;
				}
				attack -= (PoketMonster.aSpecialDef/3);
				if(attack <= 0)	attack = 1;
				PoketMonster.aHp -= attack;
				if(PoketMonster.aHp < 0) PoketMonster.aHp = 0;
				break;	
			}
			case GRASS:{
				attack = aCharactor.aNowPokemons[i].aSpecialAttk * SkillPercent[skillnum] / 40;
				cout << Skills[skillnum] << "\t";
				if(PoketMonster.aAttribute == WATER){
					cout << "It was very powerful!!" << endl;
					attack = attack * 2;
				}
				else if((PoketMonster.aAttribute == FIRE) || (PoketMonster.aAttribute == LEGEND)){
					cout << "It was weak!!" << endl;
					attack = attack / 2;
				}
				else{
					cout << "It was normal damage!!" << endl;
				}
				attack -= (PoketMonster.aSpecialDef/3);
				if(attack <= 0)	attack = 1;
				PoketMonster.aHp -= attack;
				if(PoketMonster.aHp < 0) PoketMonster.aHp = 0;
				break;	
			}
			case FIRE:{
				attack = aCharactor.aNowPokemons[i].aSpecialAttk * SkillPercent[skillnum] / 40;
				cout << Skills[skillnum] << "\t";
				if(PoketMonster.aAttribute == GRASS){
					cout << "It was very powerful!!" << endl;
					attack = attack * 2;
				}
				else if((PoketMonster.aAttribute == WATER) || (PoketMonster.aAttribute == LEGEND)){
					cout << "It was weak!!" << endl;
					attack = attack / 2;
				}
				else{
					cout << "It was normal damage!!" << endl;
				}
				attack -= (PoketMonster.aSpecialDef/3);
				if(attack <= 0)	attack = 1;
				PoketMonster.aHp -= attack;
				if(PoketMonster.aHp < 0) PoketMonster.aHp = 0;
				break;	
			}
			case WATER:{
				attack = aCharactor.aNowPokemons[i].aSpecialAttk * SkillPercent[skillnum] / 40;
				cout << Skills[skillnum] << "\t";
				if(PoketMonster.aAttribute == FIRE){
					cout << "It was very powerful!!" << endl;
					attack = attack * 2;
				}
				else if((PoketMonster.aAttribute == GRASS) || (PoketMonster.aAttribute == LEGEND)){
					cout << "It was weak!!" << endl;
					attack = attack / 2;
				}
				else{
					cout << "It was normal damage!!" << endl;
				}
				attack -= (PoketMonster.aSpecialDef/3);
				if(attack <= 0)	attack = 1;
				PoketMonster.aHp -= attack;
				if(PoketMonster.aHp < 0) PoketMonster.aHp = 0;
				break;	
			}
			case LEGEND:{
				if(skillnum == 16){		// Drain
					attack = aCharactor.aNowPokemons[i].aAttk * 15 / 100;
					cout << Skills[skillnum] << "\t";
					cout << "Hp is absorbed!!" << endl;
					if(attack >= PoketMonster.aHp) attack = PoketMonster.aHp;
					PoketMonster.aHp -= attack;
					aCharactor.aNowPokemons[i].aHp += attack;
				}
				else if(skillnum == 18){
					attack = aCharactor.aNowPokemons[i].aAttk * SkillPercent[skillnum] / 40;
					cout << Skills[skillnum] << "\t";
					cout << "It was very very powerful!!" << endl;
					attack -= (PoketMonster.aDef/3);
					if(attack <= 0)	attack = 1;
					PoketMonster.aHp -= attack;
					if(PoketMonster.aHp < 0) PoketMonster.aHp = 0;
				}
				else{
					attack = aCharactor.aNowPokemons[i].aSpecialAttk * SkillPercent[skillnum] / 40;
					cout << Skills[skillnum] << "\t";
					cout << "It was very very powerful!!" << endl;
					attack -= (PoketMonster.aSpecialDef/3);
					if(attack <= 0)	attack = 1;
					PoketMonster.aHp -= attack;
					if(PoketMonster.aHp < 0) PoketMonster.aHp = 0;
				}
				break;

			}
			case SPEED:{
				attack = aCharactor.aNowPokemons[i].aSpeed * SkillPercent[skillnum] / 40;
				cout << Skills[skillnum] << "\t";
				cout << "It was normal damage!!" << endl;
				attack -= (PoketMonster.aDef/3);
				if(attack <= 0)	attack = 1;
				PoketMonster.aHp -= attack;
				if(PoketMonster.aHp < 0) PoketMonster.aHp = 0;
				break;			
			}
			case POWERUP:{
				if(skillnum == 12){
					cout << Skills[skillnum] << "\t";
					cout << aCharactor.aNowPokemons[i].aName << "'s power upgrade 10%!!" << endl;
					aCharactor.aNowPokemons[i].aAttk = aCharactor.aNowPokemons[i].aAttk * 11 / 10;
					aCharactor.aNowPokemons[i].aSpecialAttk = aCharactor.aNowPokemons[i].aSpecialAttk * 11 / 10;
				}
				else{
					cout << Skills[skillnum] << "\t";
					cout << aCharactor.aNowPokemons[i].aName << "'s defense upgrade 10%!!" << endl;
					aCharactor.aNowPokemons[i].aDef = aCharactor.aNowPokemons[i].aDef * 11 / 10;
					aCharactor.aNowPokemons[i].aSpecialDef = aCharactor.aNowPokemons[i].aSpecialDef * 11 / 10;
				}
				break;	
			}
			case POWERDOWN:{
				if(skillnum == 14){
					cout << Skills[skillnum] << "\t";
					cout << PoketMonster.aName << "'s power lower 10%!!" << endl;
					PoketMonster.aAttk = PoketMonster.aAttk * 9 / 10;
					PoketMonster.aSpecialAttk = PoketMonster.aSpecialAttk * 9 / 10;
				}
				else{
					cout << Skills[skillnum] << "\t";
					cout << PoketMonster.aName << "'s defense lower 10%!!" << endl;
					PoketMonster.aDef = PoketMonster.aDef * 9 / 10;
					PoketMonster.aSpecialDef = PoketMonster.aSpecialDef * 9 / 10;
				}
				break;
			}
		}
	}
	else if((b == 0) && (PoketMonster.aSkills[enemy_rand].aCnt > 0)){
		skillnum = PoketMonster.aSkills[enemy_rand].aNumber;
		PoketMonster.aSkills[enemy_rand].aCnt--;
		skilltype = SkillType[skillnum];
		
		switch(skilltype){
			case NORMAL:{
				if(skillnum == 17){		// Self Bomb
					attack = PoketMonster.aAttk * SkillPercent[skillnum] / 40;;
					cout << Skills[skillnum] << "\t";
					cout << "Self Bomb!!" << endl;
					attack -= (aCharactor.aNowPokemons[i].aDef/5);
					if(attack <= 0)	attack = 1;
					aCharactor.aNowPokemons[i].aHp -= attack;
					if(aCharactor.aNowPokemons[i].aHp < 0) aCharactor.aNowPokemons[i].aHp = 0;
					PoketMonster.aHp = 0;
				}
				else{
					attack = PoketMonster.aAttk * SkillPercent[skillnum] / 40;
					cout << Skills[skillnum] << "\t";
					if(aCharactor.aNowPokemons[i].aAttribute == ELECTRIC){
						cout << "It was very powerful!!" << endl;
						attack = attack * 2;
					}
					else if(aCharactor.aNowPokemons[i].aAttribute == LEGEND){
						cout << "It was weak!!" << endl;
						attack = attack / 2;
					}
					else{
						cout << "It was normal damage!!" << endl;
					}
					attack -= (aCharactor.aNowPokemons[i].aDef/3);
					if(attack <= 0)	attack = 1;
					aCharactor.aNowPokemons[i].aHp -= attack;
					if(aCharactor.aNowPokemons[i].aHp < 0) aCharactor.aNowPokemons[i].aHp = 0;
				}
				break;				
			}
			case ELECTRIC:{
				attack = PoketMonster.aSpecialAttk * SkillPercent[skillnum] / 40;
				cout << Skills[skillnum] << "\t";
				if((aCharactor.aNowPokemons[i].aAttribute == GRASS) || (aCharactor.aNowPokemons[i].aAttribute == WATER) || (aCharactor.aNowPokemons[i].aAttribute == FIRE)){
					cout << "It was powerful!!" << endl;
					attack = attack * 3 / 2;
				}
				else if((aCharactor.aNowPokemons[i].aAttribute == NORMAL) || (aCharactor.aNowPokemons[i].aAttribute == LEGEND)){
					cout << "It was weak!!" << endl;
					attack = attack / 2;
				}
				else{
					cout << "It was normal damage!!" << endl;
				}
				attack -= (aCharactor.aNowPokemons[i].aSpecialDef/3);
				if(attack <= 0)	attack = 1;
				aCharactor.aNowPokemons[i].aHp -= attack;
				if(aCharactor.aNowPokemons[i].aHp < 0) aCharactor.aNowPokemons[i].aHp = 0;
				break;	
			}
			case GRASS:{
				attack = PoketMonster.aSpecialAttk * SkillPercent[skillnum] / 40;
				cout << Skills[skillnum] << "\t";
				if(aCharactor.aNowPokemons[i].aAttribute == WATER){
					cout << "It was very powerful!!" << endl;
					attack = attack * 2;
				}
				else if((aCharactor.aNowPokemons[i].aAttribute == FIRE) || (aCharactor.aNowPokemons[i].aAttribute == LEGEND)){
					cout << "It was weak!!" << endl;
					attack = attack / 2;
				}
				else{
					cout << "It was normal damage!!" << endl;
				}
				attack -= (aCharactor.aNowPokemons[i].aSpecialDef/3);
				if(attack <= 0)	attack = 1;
				aCharactor.aNowPokemons[i].aHp -= attack;
				if(aCharactor.aNowPokemons[i].aHp < 0) aCharactor.aNowPokemons[i].aHp = 0;
				break;	
			}
			case FIRE:{
				attack = PoketMonster.aSpecialAttk * SkillPercent[skillnum] / 40;
				cout << Skills[skillnum] << "\t";
				if(aCharactor.aNowPokemons[i].aAttribute == GRASS){
					cout << "It was very powerful!!" << endl;
					attack = attack * 2;
				}
				else if((aCharactor.aNowPokemons[i].aAttribute == WATER) || (aCharactor.aNowPokemons[i].aAttribute == LEGEND)){
					cout << "It was weak!!" << endl;
					attack = attack / 2;
				}
				else{
					cout << "It was normal damage!!" << endl;
				}
				attack -= (aCharactor.aNowPokemons[i].aSpecialDef/3);
				if(attack <= 0)	attack = 1;
				aCharactor.aNowPokemons[i].aHp -= attack;
				if(aCharactor.aNowPokemons[i].aHp < 0) aCharactor.aNowPokemons[i].aHp = 0;
				break;	
			}
			case WATER:{
				attack = PoketMonster.aSpecialAttk * SkillPercent[skillnum] / 40;
				cout << Skills[skillnum] << "\t";
				if(aCharactor.aNowPokemons[i].aAttribute == FIRE){
					cout << "It was very powerful!!" << endl;
					attack = attack * 2;
				}
				else if((aCharactor.aNowPokemons[i].aAttribute == GRASS) || (aCharactor.aNowPokemons[i].aAttribute == LEGEND)){
					cout << "It was weak!!" << endl;
					attack = attack / 2;
				}
				else{
					cout << "It was normal damage!!" << endl;
				}
				attack -= (aCharactor.aNowPokemons[i].aSpecialDef/3);
				if(attack <= 0)	attack = 1;
				aCharactor.aNowPokemons[i].aHp -= attack;
				if(aCharactor.aNowPokemons[i].aHp < 0) aCharactor.aNowPokemons[i].aHp = 0;
				break;	
			}
			case LEGEND:{
				if(skillnum == 16){		// Drain
					attack = PoketMonster.aAttk * 15 / 100;
					cout << Skills[skillnum] << "\t";
					cout << "Hp is absorbed!!" << endl;
					if(attack >= aCharactor.aNowPokemons[i].aHp) attack = aCharactor.aNowPokemons[i].aHp;
					aCharactor.aNowPokemons[i].aHp -= attack;
					PoketMonster.aHp += attack;
				}
				else if(skillnum == 18){
					attack = PoketMonster.aAttk * SkillPercent[skillnum] / 40;
					cout << Skills[skillnum] << "\t";
					cout << "It was very very powerful!!" << endl;
					attack -= (aCharactor.aNowPokemons[i].aDef/3);
					if(attack <= 0)	attack = 1;
					aCharactor.aNowPokemons[i].aHp -= attack;
					if(aCharactor.aNowPokemons[i].aHp < 0) aCharactor.aNowPokemons[i].aHp = 0;
				}
				else{
					attack = PoketMonster.aSpecialAttk * SkillPercent[skillnum] / 40;
					cout << Skills[skillnum] << "\t";
					cout << "It was very very powerful!!" << endl;
					attack -= (aCharactor.aNowPokemons[i].aSpecialDef/3);
					if(attack <= 0)	attack = 1;
					aCharactor.aNowPokemons[i].aHp -= attack;
					if(aCharactor.aNowPokemons[i].aHp < 0) aCharactor.aNowPokemons[i].aHp = 0;
				}
				break;

			}
			case SPEED:{
				attack = PoketMonster.aSpeed * SkillPercent[skillnum] / 40;
				cout << Skills[skillnum] << "\t";
				cout << "It was normal damage!!" << endl;
				attack -= (aCharactor.aNowPokemons[i].aDef/3);
				if(attack <= 0)	attack = 1;
				aCharactor.aNowPokemons[i].aHp -= attack;
				if(aCharactor.aNowPokemons[i].aHp < 0) aCharactor.aNowPokemons[i].aHp = 0;
				break;			
			}
			case POWERUP:{
				if(skillnum == 12){
					cout << Skills[skillnum] << "\t";
					cout << PoketMonster.aName << "'s power upgrade 10%!!" << endl;
					PoketMonster.aAttk = PoketMonster.aAttk * 11 / 10;
					PoketMonster.aSpecialAttk = PoketMonster.aSpecialAttk * 11 / 10;
				}
				else{
					cout << Skills[skillnum] << "\t";
					cout << PoketMonster.aName << "'s defense upgrade 10%!!" << endl;
					PoketMonster.aDef = PoketMonster.aDef * 11 / 10;
					PoketMonster.aSpecialDef = PoketMonster.aSpecialDef * 11 / 10;
				}
				break;	
			}
			case POWERDOWN:{
				if(skillnum == 14){
					cout << Skills[skillnum] << "\t";
					cout << aCharactor.aNowPokemons[i].aName << "'s power lower 10%!!" << endl;
					aCharactor.aNowPokemons[i].aAttk = aCharactor.aNowPokemons[i].aAttk * 9 / 10;
					aCharactor.aNowPokemons[i].aSpecialAttk = aCharactor.aNowPokemons[i].aSpecialAttk * 9 / 10;
				}
				else{
					cout << Skills[skillnum] << "\t";
					cout << aCharactor.aNowPokemons[i].aName << "'s defense lower 10%!!" << endl;
					aCharactor.aNowPokemons[i].aDef = aCharactor.aNowPokemons[i].aDef * 9 / 10;
					aCharactor.aNowPokemons[i].aSpecialDef = aCharactor.aNowPokemons[i].aSpecialDef * 9 / 10;
				}
				break;
			}
		}
	}
}

int read_input_start(){
    switch(getchar()){
        case 49:{
            return 1;
            break;
        }

        case 50:{
            return 2;
            break;
        }

        case 51:{
            return 3;
            break;
        }
    }

    return 0;
}

int read_input_game(){
    switch(getchar()){
        case 49:{
            return 1;
            break;
        }

        case 50:{
            return 2;
            break;
        }

        case 51:{
            return 3;
            break;
        }

	case 52:{
            return 4;
            break;
        }

	case 53:{
            return 5;
            break;
        }

	case 54:{
            return 6;
            break;
        }
	
	case 55:{
            return 7;
            break;
        }

	case 56:{
            return 8;
            break;
        }

	case 57:{
            return 9;
            break;
        }
    }

    return 0;
}

void init_pokemon(int i, int level){
	PoketMonster.aPoketmonNum = i;
	i--;
	PoketMonster.aLevel = level;
	PoketMonster.aExp = 0;
	PoketMonster.aHp = Hp[i]*level;
	PoketMonster.aAttribute = Attribute[i];
	PoketMonster.aAttk = Attk[i]*level;
	PoketMonster.aDef = Def[i]*level;
	PoketMonster.aSpeed = Speed[i]*level;
	PoketMonster.aSpecialAttk = SpecialAttk[i]*level;
	PoketMonster.aSpecialDef = SpecialDef[i]*level;	
	PoketMonster.aSkillCnt = 0;
	PoketMonster.aSkills.erase(PoketMonster.aSkills.begin(), PoketMonster.aSkills.end());
	for(int j = 0 ; j < 20 ; j++){
		if((SkillType[j] == Attribute[i]) || (SkillType[j] > LEGEND)){
			NowSkill.aNumber = j;
			NowSkill.aPercent = SkillPercent[j];
			NowSkill.aType = SkillType[j];
			NowSkill.aCnt = init_skill(j);
			PoketMonster.aSkillCnt++;
			PoketMonster.aSkills.push_back(NowSkill);
		}
	}
}

int random(int low, int high){
	float temp;
	long zi, lowprd, hi31;
	zi = ran;
	lowprd = (zi & 65535) * MULT1;
	hi31   = (zi >> 16) * MULT1 + (lowprd >> 16);
	zi     = ((lowprd & 65535) - MODLUS) +
	     ((hi31 & 32767) << 16) + (hi31 >> 15);
	if (zi < 0) zi += MODLUS;
	lowprd = (zi & 65535) * MULT2;
	hi31   = (zi >> 16) * MULT2 + (lowprd >> 16);
	zi     = ((lowprd & 65535) - MODLUS) +
	     ((hi31 & 32767) << 16) + (hi31 >> 15);
	if (zi < 0) zi += MODLUS;
	ran = zi;
	temp = (zi >> 7 | 1) / 16777216.0;
	return (int)(low + (high - low + 1) * temp);
}

int init_skill(int j){
	if(SkillPercent[j] == 10)
		return 35;
	else if(SkillPercent[j] == 20)
		return 30;
	else if(SkillPercent[j] == 30)
		return 35;
	else if(SkillPercent[j] == 80) 
		return 10;
	else if(SkillPercent[j] == 100)
		return 5;
	else 
		return 15;
}

