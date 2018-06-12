#pragma once
#include <string>

class Player {

public:
	Player();
	std::string get_lp();
	int getint_lp();
	void lp_increase(int a);
	void lp_decrease(int a);
	//int get_steps();
	//void steps_inc();
	//void steps_reset();

private:
	int lp;
	//int steps;
};