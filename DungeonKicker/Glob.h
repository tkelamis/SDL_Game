#pragma once
#include "Character.h"

class Glob : public Character
{
public:
	Glob();
	~Glob();

	std::string getName();
	void makeDumpNoise();

};

