#pragma once
#include "Fleet.h"

class Flottenkampf
{
public:
	void Start();


private:
	void StartCharacterSelect(Fleet& fleet);
	bool IsValidInput(char c) const;

	void StartCombat();
	void RenderCombatScreen();
	void RenderShip(const Ship& ship, bool isActive);
	void RenderLife(const Ship& ship, bool isActive);
	void Attack(Fleet& fleet, Fleet& other);

	Fleet fleet1;
	Fleet fleet2;
};

