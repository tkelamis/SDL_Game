#include <iostream> 
#include <string> 
#include <Windows.h> 
#include "Puzzles.h" 
#include "Character.h"
#include "Glob.h" 
#include "Hero.h" 
#include "Mimic.h" 
#include <SDL.h> 
#include <SDL_image.h>
#include <SDL_ttf.h> 
#include <SDL_mixer.h> 
#include "CharacterQuiz.h"
#include <synchapi.h>
#include "Puzzles.h"

using namespace std;

void Quiz() {
	cout << "Hello there..." << endl;
	cout << "What is your name?" << endl;
	string name;
	cin >> name;
	cout << "Welcome to the dungeon " << name << "!! muahahahha!!!" << endl;
	cout << "How old are you?" << endl;
	int age;
	cin >> age;
	cout << "So you are " << age << " years old" << endl;


	if (age > 66) {
		cout << "You are old!!" << endl;
	}
	else if (age > 3 && age < 10) {
		cout << "You are a kid!!";
	}
	else {
		cout << "You are not old!!";
	}

}

void Setup()
{
	int hp = 0, str = 0, def = 0, agi = 0;
	bool CharacterSetup = false;
	while (!CharacterSetup)
	{
		std::cout << "What type of character are you?" << std::endl;
		std::cout << "1 - Beserker" << std::endl;
		std::cout << "2 - Buff Nut" << std::endl;
		std::cout << "3 - Speedy Ninja" << std::endl;
		int choice;
		std::cin >> choice;
		if (choice == 1) {
			CharacterSetup = true;
			hp = 60; str = 10; def = 2; agi = 3;
			std::cout << "Congrats.. You are now a Beserker!!!" << std::endl;
		}
		else if (choice == 2) {
			CharacterSetup = true;
			hp = 100; str = 4; def = 5; agi = 1;
			std::cout << "Congrats.. You are now a Buff Nut!!!" << std::endl;
		}
		else if (choice == 3) {
			CharacterSetup = true;
			hp = 80; str = 3; def = 1; agi = 10;
			std::cout << "Congrats.. You are now a Speedy Ninja!!" << std::endl;
		}
		else {
			std::cout << "Invalid choice.. Try again!!" << std::endl;
			Sleep(1000);
			std::cout << "And this time...choose more wisely.." << std::endl;
			CharacterSetup = false;
		}
		Sleep(2000);
	}
	std::cout << "Stats:" << std::endl << "hp:" << hp << std::endl << "str:" << str << std::endl;
	std::cout << "def:" << def << std::endl << "agi:" << agi << std::endl;
	std::cout << "The first gate is opening, counting down..." << std::endl;
	std::cout << 10 << ",";
	for (int i = 9; i >= 1; i--) 
	{
		std::cout << i <<",";
		Sleep(200);
	}
	std::cout << 0 << std::endl;
	std::cout << "In the first room stands a tall slender figure in a cloak." << std::endl;
	std::cout << "Totally skull faced..He speaks: " << std::endl;
	std::cout << "I will ask you 2 questions with various punishments if you get them wrong..." << std::endl;

	int dmg1 = puzzle1();
	if (dmg1 == 0)
	{
		std::cout << "Good.Next question.. " << std::endl;
	}
	else if (dmg1 == 10) {

		hp = hp - dmg1;
		std::cout << "The answer is 9. So is the amount of damage i'll inflict you! Your HP now is "
			<< hp << ". Next question....." << std::endl;
	}
	int dmg2 = puzzle2();
	if (dmg2 == 10) {
		hp = hp - dmg2;
		std::cout << "The answer is PAO." << dmg2 << " damage is coming your way.Your HP now is " << hp << std::endl;
	}
	std::cout << "You are entering the dungeon with " << hp << " HP. Good luck!!" << std::endl;
}
