#include "Player.hpp"
#include "Fighter.hpp"

//Création d'un personnage
Player::Player(int i)
	: Fighter(i)
{
	win = 0;
}


void Player::win_inc() {
	win++;
}