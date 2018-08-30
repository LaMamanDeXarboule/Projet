#include "Enemy.hpp"
#include "Fighter.hpp"


//Fonction qui donne un nombre al�atoire entre a et c
int rand_b_d(int a, int c) {
	return rand() % (c + 1 - a) + a;

}
//Cr�ation d'un personnage
Enemy::Enemy(int i) 
	: Fighter(i)
{
	lp = id - 2;
	loot = rand_b_d(0, 10);
}

int Enemy::get_loot() {
	return loot;
}