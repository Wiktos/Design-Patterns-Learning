#pragma once
#include <iostream>

class WitcherGame
{
public:
	virtual void installWitcher() = 0;
};

class WitcherOneGame : public WitcherGame
{
public:
	void installWitcher()
	{
		std::cout << "Installing Witcher One in process..." << std::endl;
	}
};

class WitcherThreeGame : public WitcherGame
{
public:
	void installWitcher()
	{
		std::cout << "Installing Witcher Three in process..." << std::endl;
	}
};

class Computer
{
protected:
	WitcherGame* game;
public:
	virtual void installWitcher() = 0;
	void changeGameInDrive(WitcherGame* newGame)
	{
		delete game;
		game = newGame;
	}
	virtual ~Computer()
	{
		delete game;
	}
};

class WeakComputer : public Computer
{
public:
	WeakComputer() 
	{
		game = new WitcherOneGame;
	}
	void installWitcher()
	{
		game->installWitcher();
		std::cout << "Instalation failed computer doesnt fullfill requirements" << std::endl;
	}
};

class SuperComputer : public Computer
{
public:
	SuperComputer()
	{
		game = new WitcherThreeGame;
	}
	void installWitcher()
	{
		game->installWitcher();
		std::cout << "Instalation complete. Enjoy the game !" << std::endl;
	}
};