#include "Flottenkampf.h"
#include "Hunter.h"
#include "Destroyer.h"
#include "Cruiser.h"
#include <iostream>
#include <random>
#include <Windows.h>

void Flottenkampf::Start()
{
	srand(time(nullptr));
	StartCharacterSelect(fleet1);
	StartCharacterSelect(fleet2);
	StartCombat();
}

void Flottenkampf::StartCharacterSelect(Fleet& fleet)
{
	char input;
	for (int i = 0; i < MAX_FLEET_SIZE; i++)
	{
		do {
			system("cls");
			std::cout << "Choose your ship no. " << i + 1 << '\n';
			std::cout << "(H)unter, (D)estroyer, (C)ruiser: ";
			std::cin >> input;
		} while (!IsValidInput(input));
		
		switch (input)
		{
		case 'H':
		case 'h':
			fleet.AddShip(std::make_shared<Hunter>());
			break;
		case 'D':
		case 'd':
			fleet.AddShip(std::make_shared<Destroyer>());
			break;
		case 'C':
		case 'c':
			fleet.AddShip(std::make_shared<Cruiser>());
			break;
		}
	}
}

bool Flottenkampf::IsValidInput(char c) const
{
	return (c == 'H' || c == 'h' || c == 'D' || c == 'd' || c == 'C' || c == 'c');
}

void Flottenkampf::StartCombat()
{
	while (fleet1.IsAlive() && fleet2.IsAlive())
	{
		RenderCombatScreen();
		Attack(fleet1, fleet2);
		RenderCombatScreen();
		Attack(fleet2, fleet1);
	}
	system("cls");
	if (fleet1.IsAlive())
	{
		std::cout << "Fleet 1 Wins!";
	}
	else
	{
		std::cout << "Fleet 2 Wins!";
	}
}

void Flottenkampf::RenderCombatScreen()
{
	system("cls");
	for (int i = 0; i < MAX_FLEET_SIZE; i++)
	{
		std::cout << "(" << i + 1 << ") ";
		RenderShip(*(fleet1.GetShip(i)), fleet1.GetShip(i)->IsAlive());
		std::cout << "    ";
		RenderShip(*(fleet2.GetShip(i)), fleet2.GetShip(i)->IsAlive());
		std::cout << '\n' << '\n';
	}
}

void Flottenkampf::RenderShip(const Ship& ship, bool isActive)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!isActive)
		SetConsoleTextAttribute(hConsole, 8);

	switch (ship.GetShipType())
	{
	case ShipType::hunter:
		std::cout << "[H]  ";
		RenderLife(ship, isActive);
		break;
	case ShipType::destroyer:
		std::cout << "[D] ";
		RenderLife(ship, isActive);
		break;
	case ShipType::cruiser:
		std::cout << "[C] ";
		RenderLife(ship, isActive);
		break;
	}

	SetConsoleTextAttribute(hConsole, 15);
}

void Flottenkampf::RenderLife(const Ship& ship, bool isActive)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!isActive)
		SetConsoleTextAttribute(hConsole, 8);
	else
		SetConsoleTextAttribute(hConsole, 12);

	std::cout << ship.GetHull() << " ";

	SetConsoleTextAttribute(hConsole, 15);
}

void Flottenkampf::Attack(Fleet& fleet, Fleet& other)
{
	int input = 0, input2 = 0;
	do {
		std::cout << "Choose your ship you want to attack with: ";
		std::cin >> input;
	} while (input < 1 || input > 9);

	do {
		std::cout << "Choose the target: ";
		std::cin >> input2;
	} while (input2 < 1 || input2 > 9);

	fleet.Attack(input - 1, input2 - 1, other);
}
