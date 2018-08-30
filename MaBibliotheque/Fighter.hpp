#pragma once
#include <string>
#include "Character.hpp"

class Fighter : public Character {

public:
	Fighter(int i);
	std::string get_lp();
	int getint_lp();
	void lp_increase(int a);
	void lp_decrease(int a);
	//int get_steps();
	//void steps_inc();
	//void steps_reset();

protected:
	int lp;
	//int steps;
};