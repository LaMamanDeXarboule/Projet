#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "../MaBibliotheque/Puzzle.hpp"
#include "../MaBibliotheque/SFMLOrthogonalLayer.hpp"
#include "../MaBibliotheque/Player.hpp"
#include <tmxlite/Map.hpp>
#include <tmxlite/TileLayer.hpp>

//Fonction qui donne un nombre aléatoire entre a et c
int rand_a_c(int a, int c) {
	return rand() % (c + 1 - a) + a;

}

//Fonction qui donne un binaire à partir d'un décimal
std::string dec_to_bin(int dec)
{
	std::string bin;
	while (dec != 0) { bin = (dec % 2 == 0 ? "0" : "1") + bin; dec /= 2; }
	return bin;
}

//Fonction qui gère le dessin du tableau
void draw_board(Puzzle puzzle, sf::RenderWindow &window) {
	sf::RectangleShape line(sf::Vector2f(600, 5));
	line.setPosition(0, 100);
	line.setFillColor(sf::Color::White);
	for (int i = 0; i <= 4; i++) { //Dessin des lignes horizontales
		line.setPosition(0, float(i) * 150);
		window.draw(line);
	}
	line.rotate(90);
	for (int j = 0; j <= 4; j++) { //Dessin des lignes verticales
		line.setPosition(float(j) * 150, 0);
		window.draw(line);
	}
	int a;
	std::string s;
	sf::Font font;
	font.loadFromFile("arial.ttf");
	for (int i = 0; i <= 3; i++) { //On va dessiner le contenu du tableau
		for (int j = 0; j <= 3; j++) {
			a = puzzle.get_element(j, i);
			if (a != 0) {
				std::string s = dec_to_bin(a);
				sf::Text text(s, font);
				text.setCharacterSize(50);
				text.setStyle(sf::Text::Bold);
				text.setFillColor(sf::Color::White);
				text.setPosition(float(i) * 150 + 50 - a * 5, float(j) * 150 + 50);
				window.draw(text);
			}
		}
	}
}

//Fonction qui gère le puzzle 2048
void puzzle_game(Player *character)
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "2048");
	Puzzle puzzle;
	puzzle.add_element_random();
	draw_board(puzzle, window);
	window.display();
	while (window.isOpen())
	{
		sf::Event event;
		window.setKeyRepeatEnabled(false);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) { //On utilise les flèches du clavier
				Puzzle puzzle2 = puzzle;//Permet de vérifier que l'on a bien déplacé des tuiles
				if (event.key.code == sf::Keyboard::Left) {
					puzzle.swipe_left();
					if (puzzle.get_board() != puzzle2.get_board()) {
						puzzle.add_element_random();
					}
					else {
						character->lp_decrease(1);
					}
					window.clear();
					draw_board(puzzle, window);
				}
				if (event.key.code == sf::Keyboard::Right) {
					puzzle.swipe_right();
					if (puzzle.get_board() != puzzle2.get_board()) {
						puzzle.add_element_random();
					}
					else {
						character->lp_decrease(1);
					}
					window.clear();
					draw_board(puzzle, window);
				}
				if (event.key.code == sf::Keyboard::Up) {
					puzzle.swipe_top();
					if (puzzle.get_board() != puzzle2.get_board()) {
						puzzle.add_element_random();
					}
					else {
						character->lp_decrease(1);
					}
					window.clear();
					draw_board(puzzle, window);
				}
				if (event.key.code == sf::Keyboard::Down) {
					puzzle.swipe_low();
					if (puzzle.get_board() != puzzle2.get_board()) {
						puzzle.add_element_random();
					}
					else {
						character->lp_decrease(1);
					}
				}
				if (puzzle.puzzle_end() == false) { //Tableau non plein on redessine et on attend la prochaine touche
					window.clear();
					draw_board(puzzle, window);
					window.display();
				}
				if (puzzle.puzzle_end() == true) { //Tableau plein on ferme la fenêtre
					character->lp_decrease(5);
					window.close();
				}
				if (puzzle.puzzle_victory() == 1) { //On a obtenu un 1001, on ferme la fenêtre
					character->lp_increase(2);
					window.close();
				}
				if (character->getint_lp() == 0) {
					window.close();
				}
			}
		}
	}
}

/*
int collision(sf::FloatRect land, sf::Sprite sprite) {
	int result = 1;
	auto sprite_collision = sprite.getGlobalBounds();
	if (land.intersects(sprite_collision)) {
		result = 0;
	}
	return result;
}
*/

//Fonction qui gère l'apparition aléatoire de puzzles (1 chance sur 10)
void random_encounter(Player *character) {
	int random = rand_a_c(0,10);
	if (random == 10) {
		puzzle_game(character);
	}
}


//Fonction main qui gère la fenêter principale
int main()
{
	sf::Font font;
	font.loadFromFile("arial.ttf");
	Player *character = new Player();
	sf::RenderWindow window(sf::VideoMode(784, 784), "2048RPG");
	tmx::Map map;
	map.load("../assets/Map.tmx"); //On charge la carte du fichier Map.tmx
	MapLayer layerZero(map, 0);// On crée un MapLayer, objet utilisable et permettant de l'afficher avec SFML
	MapLayer layerOne(map, 1); // Les différentes couches correspondent aux couches crées dans Tiled Map Editor
	MapLayer layerTwo(map, 2);
	sf::Text lifepoints(character->get_lp(), font);
	sf::Text end;
	lifepoints.setCharacterSize(30);
	lifepoints.setStyle(sf::Text::Bold);
	lifepoints.setFillColor(sf::Color::Red);
	lifepoints.setPosition(600, 50);
	sf::Texture character_texture;
	if (!character_texture.loadFromFile("../assets/CharacterFront.png")) { //On récupère la sprite du personnage
		return -1;
	}
	sf::Sprite sprite;
	sprite.setTexture(character_texture);
	sprite.setPosition(160, 160);
	window.draw(sprite);
	window.draw(layerZero);
	window.draw(layerOne);
	window.draw(layerTwo);
	window.draw(sprite);
	window.draw(lifepoints);
	window.display();//On dessine les éléments et on les affiche
	while (window.isOpen())
	{
		sf::Event event;
		window.setKeyRepeatEnabled(false);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
				/*
				if (event.key.code == sf::Keyboard::F1) {
					puzzle_game(character);
				}*/
				if (event.key.code == sf::Keyboard::Left) { //On déplace le personnage sur la gauche
					sprite.move(-16, 0);
					random_encounter(character);
				}
				if (event.key.code == sf::Keyboard::Right) {
					sprite.move(16, 0);
					random_encounter(character);
				}
				if (event.key.code == sf::Keyboard::Up) {
					sprite.move(0, -16);
					random_encounter(character);
				}
				if (event.key.code == sf::Keyboard::Down) {
					sprite.move(0, 16);
					random_encounter(character);
				}
			}
		}
		window.clear(sf::Color::Black); //On clear la fenêtre afin d'effacer les mouvements précédents du personnage
		window.draw(layerZero);
		window.draw(layerOne);
		window.draw(layerTwo);
		window.draw(sprite);
		lifepoints.setString(character->get_lp());
		window.draw(lifepoints);
		if (sprite.getPosition().x == 640 && sprite.getPosition().y == 576) { //Position spécifique correspondant à la fin du jeu
			sf::Font font;
			font.loadFromFile("arial.ttf");
			sf::Text finish("Congrats!", font);
			finish.setCharacterSize(30);
			finish.setStyle(sf::Text::Bold);
			finish.setFillColor(sf::Color::Red);
			finish.setPosition(392, 392);
			window.draw(finish);
		}
		if (character->getint_lp() == 0) {
			sf::Font font;
			font.loadFromFile("arial.ttf");
			sf::Text dead("You're dead!", font);
			dead.setCharacterSize(30);
			dead.setStyle(sf::Text::Bold);
			dead.setFillColor(sf::Color::Red);
			dead.setPosition(392, 392);
			window.draw(dead);
		}
		window.display();
	}
	return 0;
}
