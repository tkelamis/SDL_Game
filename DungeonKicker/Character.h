#pragma once
#include <iostream>
#include <string>

class Character
{
protected:
	
	int hp, hpMax, _str, m_def, agi;
public:
	Character();
	~Character();

	void setupStats(int _hp, int _str, int _def, int _agi);
	void displayStats();

	inline int getHP() { return hp; }
	inline int getHPMax() { return hpMax; }
	inline int getAGI() { return agi; }
	inline int getDamage() { return _str; }
	virtual std::string getName(){ return "Character";}

	void takeDamage(int dmg);


};

