#include "Player.hpp"

//Création d'un personnage
Player::Player() {
	lp = 10;
	//steps = 0;
}

//Retourne les PV du personnage
std::string Player::get_lp() {
	return std::to_string(lp);
}

//Retourne les PV du personnage
int Player::getint_lp() {
	return lp;
}

//On baisse les PV du personnage
void Player::lp_decrease(int a) {
	lp = lp - a;
}

//On augmente les PV du personnage
void Player::lp_increase(int a) {
	lp = lp + a;
}

/*
int Player::get_steps() {
	return steps;
}

void Player::steps_inc() {
	steps++;
}

void Player::steps_reset() {
	steps = 0;
}*/