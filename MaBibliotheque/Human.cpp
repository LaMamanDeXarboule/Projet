#include "Human.hpp"
#include "Character.hpp"

//Cr�ation d'un personnage
Human::Human(int i) 
	:Character(i)
{
}

std::string Human::get_name() {
	return name;
}