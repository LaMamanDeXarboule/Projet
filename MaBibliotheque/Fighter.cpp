#include "Fighter.hpp"
#include "Character.hpp"

//Création d'un personnage
Fighter::Fighter(int i) 
	: Character(i)
{
	lp = 10;
	//steps = 0;
}

//Retourne les PV du personnage
std::string Fighter::get_lp() {
	return std::to_string(lp);
}

//Retourne les PV du personnage
int Fighter::getint_lp() {
	return lp;
}

//On baisse les PV du personnage
void Fighter::lp_decrease(int a) {
	lp = lp - a;
}

//On augmente les PV du personnage
void Fighter::lp_increase(int a) {
	lp = lp + a;
}

/*
int Fighter::get_steps() {
return steps;
}

void Fighter::steps_inc() {
steps++;
}

void Fighter::steps_reset() {
steps = 0;
}*/