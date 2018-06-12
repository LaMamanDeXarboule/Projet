#pragma once
#include <vector>

class Puzzle
{
public:
	Puzzle();
	std::vector< std::vector<int> > get_board();
	int get_element(int j, int i);
	void swipe_left();
	void swipe_right();
	void swipe_top();
	void swipe_low();
	int addition(int ax, int ay, int bx, int by);
	void add_element_random();
	void add_element(int j, int i);
	int count_element();
	bool puzzle_end();
	int puzzle_victory();

private:
	int board[4][4];


};