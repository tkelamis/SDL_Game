#include "Mimic.h"

Mimic::Mimic()
{
	hp = 25; hpMax = 25; _str = 6;
	m_def = 1; agi = 2;
}
Mimic::~Mimic()
{

}

std::string Mimic::getName()
{
	return "Mimic";
}