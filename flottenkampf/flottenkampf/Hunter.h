#pragma once
#include "Ship.h"

class Hunter : public Ship
{
public:
	Hunter();

	bool Attack(Ship& other) override;
};

