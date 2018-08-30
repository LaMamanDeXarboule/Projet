#pragma once
#include <string>
#include "Character.hpp"

class Human : public Character {

public:
	Human(int i);
	std::string get_name();

private:
	std::string name;
};