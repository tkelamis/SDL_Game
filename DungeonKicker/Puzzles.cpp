#include <iostream>
#include <string>
#include "Puzzles.h"

int puzzle1()
{
	std::cout << "Puzzle 1: What is 7+2 ? " << std::endl;
	int num;
	std::cin >> num;
	if (num == 9) {
		std::cout << "Hmmmm!!" << std::endl;
		return 0;
	}
	else {
		std::cout << "You fool!!" << std::endl;
		return 10;
	}
}

int puzzle2()
{
	std::string best_team = "AEK";
	std::cout << "Which is the best team in Greece my friend ??" << std::endl;
	std::string answer;
	std::cin >> answer;
	if (answer == best_team)
	{
		std::cout << "Nice answer!! You are clean!!" << std::endl;
		return 0;
	}
	else {
		std::cout << "LOL!! Not in a million years." << std::endl;
		return 10;
	}

}