#include "Hero.h"

Hero::Hero()
{
}

Hero::~Hero()
{
}

void Hero::SetHP(int hp)
{
	this->hp = hp;
}

void Hero::setName(std::string hero_name)
{
	name = hero_name;
}

//std::string Hero::getName()
//{
//	return name;
//}

void Hero::heal(int amount)
{
	hp += amount;
	if (hp > hpMax) { hp = hpMax; }
}

void Hero::atkBoost(int amount)
{
	_str += amount;
}

void Hero::defBoost(int amount)
{
	m_def += amount;
}

