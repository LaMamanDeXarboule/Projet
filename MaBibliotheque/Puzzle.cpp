#include <vector>
#include <random>
#include "Puzzle.hpp"

//fonction random d'un nombre entre a et b
int rand_a_b(int a, int b) {
	return rand() % (b + 1 - a) + a;

}

//Création d'un puzzle 2048 vide
Puzzle::Puzzle()
{
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			board[i][j] = 0;
		}
	}
}

std::vector< std::vector<int> > Puzzle::get_board() {
	std::vector< std::vector<int> > v(4, std::vector<int>(4));
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			v[j][i] = board[j][i];
		}
	}
	return v;
}

//Retourne l'élément à l'emplacement (j,i)
int Puzzle::get_element(int j, int i)
{
	return board[j][i];
}

//Ajoute un élément 1 à un emplacement aléatoire
void Puzzle::add_element_random()
{
	int c = rand_a_b(0, 3);
	int d = rand_a_b(0, 3);
	while (board[c][d] != 0)
	{
		c = rand_a_b(0, 3);
		d = rand_a_b(0, 3);
	}
	board[c][d] = 1;
}

//Ajoute un élément 1 à un emplacement donné
void Puzzle::add_element(int j, int i)
{
	if (board[j][i] == 0) {
		board[j][i] = 1;
	}
}

//Gestion lorsque 2 cases avec le même nombre
int Puzzle::addition(int ax, int ay, int bx, int by) //la case qui se déplace est b
{
	int result = 0;
	if (board[ax][ay] == board[bx][by])
	{
		board[ax][ay] = board[ax][ay] * 2; //La case voit son nombre multiplié par 2
		board[bx][by] = 0; //La case qui se déplace devient vide
		result = board[ax][ay];
	}
	if (board[ax][ay] == 8 && board[bx][by] == 1) {
		board[ax][ay] = 9;
		board[bx][by] = 0;
		result = board[ax][ay];
	}
	if (board[ax][ay] == 1 && board[bx][by] == 8) {
		board[ax][ay] = 9;
		board[bx][by] = 0;
		result = board[ax][ay];
	}
	return result;
}

//Fonction qui gère lorsque le joueur fait glisser vers la gauche
void Puzzle::swipe_left()
{
	for (int j = 0; j <=3 ; j++) {
		for (int i = 1; i <= 3; i++) { //On parcourt tout le tableau
			if (board[j][i] != 0) { 
				for (int k = i; k >= 1; k--) { //On va parcourir les cases sur la gauche de la case non vide
					if (board[j][k-1] == 0) //Cas où la case de gauche est vide, on déplace donc le nombre
					{
						board[j][k-1] = board[j][k]; 
						board[j][k] = 0;
					}
					else if (board[j][k-1] != 0) { //Cas où on peut avoir une addition
						addition(j, k-1, j, k);
					}
				}
			}
		}
	}
}

//Fonction qui gère lorsque le joueur fait glisser vers la droite
void Puzzle::swipe_right()
{
	for (int j = 0; j <= 3; j++) {
		for (int i = 2; i >= 0; i--) {
			board[j][i];
			if (board[j][i] != 0) {
				for (int k = i; k <= 2; k++) {
					if (board[j][k + 1] == 0)
					{
						board[j][k + 1] = board[j][k];
						board[j][k] = 0;
					}
					else if (board[j][k + 1] != 0) {
						addition(j, k + 1, j, k);
					}
				}
			}
		}
	}
}

//Fonction qui gère lorsque le joueur fait glisser vers le haut
void Puzzle::swipe_top()
{
	for (int i = 0; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			board[j][i];
			if (board[j][i] != 0) {
				for (int k = j; k >= 1; k--) {
					if (board[k-1][i] == 0)
					{
						board[k-1][i] = board[k][i];
						board[k][i] = 0;
					}
					else if (board[k-1][i] != 0) {
						addition(k-1, i, k, i);
					}
				}
			}
		}
	}
}

//Fonction qui gère lorsque le joueur fait glisser vers le bas
void Puzzle::swipe_low()
{
	for (int i = 0; i <= 3; i++) {
		for (int j = 2; j >= 0; j--) {
			board[j][i];
			if (board[j][i] != 0) {
				for (int k = j; k <= 2; k++) {
					if (board[k+1][i] == 0)
					{
						board[k+1][i] = board[k][i];
						board[k][i] = 0;
					}
					else if (board[k+1][i] != 0) {
						addition(k + 1, i, k, i);
					}
				}
			}
		}
	}
}

//Retourne le nombre d'éléments non vides du tableau
int Puzzle::count_element() {
	int count = 0;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if (board[i][j] > 0) {
				count++;
			}
		}
	}
	return count;
}

//Fonction qui renvoie true si le tableau est plein
bool Puzzle::puzzle_end() {
	int count = 0;
	bool b = false;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if (board[j][i] != 0) {
				count++;
			}
		}
	}
	if (count == 16) {
		b = true;
	}
	return b;
}

//retourne 1 si on a un 1001 dans le tableau
int Puzzle::puzzle_victory() {
	int result = 0;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if (board[j][i] == 9) {
				result++;
			}
		}
	}
	return result;
}
