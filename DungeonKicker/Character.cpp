#include "Character.h"


Character::Character()
{
}

Character::~Character()
{

}

void Character::setupStats(int _hp, int _str, int _def, int _agi)
{
	hp = _hp; hpMax = _hp; _str = _str; m_def = _def; agi = _agi;
}

void Character::displayStats()
{
	std::cout << "HP:" << hp << " || " << "str:" << _str << " || " << "def:" 
		<< m_def << " || " << "agi:" << agi << std::endl;
}



void Character::takeDamage(int dmg)
{
	int dmgAfterDef = dmg - m_def;
	if (dmgAfterDef < 1) { dmgAfterDef = 1;}
	hp -= dmgAfterDef;
}


