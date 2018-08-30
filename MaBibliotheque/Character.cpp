#include "Character.hpp"

//Création d'un personnage
Character::Character(int i) {
	id = i;
}

int Character::get_id() {
	return id;
}