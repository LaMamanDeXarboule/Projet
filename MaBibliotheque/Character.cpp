#include "Character.hpp"

//Cr�ation d'un personnage
Character::Character(int i) {
	id = i;
}

int Character::get_id() {
	return id;
}