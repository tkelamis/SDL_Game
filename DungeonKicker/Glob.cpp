#include "Glob.h"


Glob::Glob()
{
	hp = 10; hpMax = 10; _str = 4;
	m_def = 2; agi = 5;
}
Glob::~Glob()
{

}

std::string Glob::getName()
{
	return "Glob";
}

void Glob::makeDumpNoise()
{
	std::cout << getName() << " goes Whaaaaammmmyyyy!!!!!" << std::endl;
}
