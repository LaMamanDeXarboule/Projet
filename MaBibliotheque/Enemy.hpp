#pragma once
#include <string>
#include "Fighter.hpp"

class Enemy : public Fighter {

public:
	Enemy(int i);
	int get_loot();

private:
	int loot;
};