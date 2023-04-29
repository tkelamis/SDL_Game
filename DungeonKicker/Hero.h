#pragma once
#include "Character.h"

class Hero:public Character
{
private:
	std::string name;
public:
	Hero();
	~Hero();

	void SetHP(int hp);
	void setName(std::string name);
	std::string getName() override { return ""; }
	void heal(int amount);
	void atkBoost(int amount);
	void defBoost(int amount);
};

