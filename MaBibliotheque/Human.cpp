#include "Human.hpp"
#include "Character.hpp"

//Création d'un personnage
Human::Human(int i) 
	:Character(i)
{
}

std::string Human::get_name() {
	return name;
}