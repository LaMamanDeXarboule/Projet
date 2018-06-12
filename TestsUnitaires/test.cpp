#include "pch.h"
#include "../MaBibliotheque/Puzzle.hpp"

TEST(TestPuzzle, TestCreation) {
	Puzzle test;
	EXPECT_EQ(test.count_element(), 0);
}

TEST(TestPuzzle, TestAddRandom) {
	Puzzle test;
	test.add_element_random();
	test.add_element_random();
	EXPECT_EQ(test.count_element(), 2);
}

TEST(TestPuzzle, TestAdd) {
	Puzzle test;
	test.add_element(1,1);
	test.add_element(2,3);
	EXPECT_EQ(test.get_element(1,1), 1);
	EXPECT_EQ(test.get_element(2, 3), 1);

}

TEST(TestPuzzle, TestSwipeLeft1) {
	Puzzle test;
	test.add_element(1, 1);
	test.add_element(2, 3);
	test.swipe_left();
	EXPECT_EQ(test.get_element(1, 1), 0);
	EXPECT_EQ(test.get_element(2, 3), 0);
	EXPECT_EQ(test.get_element(1, 0), 1);
	EXPECT_EQ(test.get_element(2, 0), 1);
}

TEST(TestPuzzle, TestSwipeLeft2) {
	Puzzle test;
	test.add_element(3, 2);
	test.add_element(0, 0);
	test.add_element(0, 1);
	test.swipe_left();
	EXPECT_EQ(test.get_element(0, 0), 2);
	EXPECT_EQ(test.get_element(3, 2), 0);
	EXPECT_EQ(test.get_element(0, 1), 0);
	EXPECT_EQ(test.get_element(3, 0), 1);
}

TEST(TestPuzzle, TestSwipeRight) {
	Puzzle test;
	test.add_element(3, 2);
	test.add_element(0, 0);
	test.add_element(0, 1);
	test.swipe_right();
	EXPECT_EQ(test.get_element(0, 3), 2);
	EXPECT_EQ(test.get_element(3, 2), 0);
	EXPECT_EQ(test.get_element(0, 0), 0);
	EXPECT_EQ(test.get_element(0, 1), 0);
	EXPECT_EQ(test.get_element(3, 3), 1);
}

TEST(TestPuzzle, TestSwipeRight2) {	
	Puzzle test;
	test.add_element(2, 1);
	test.add_element(2, 3);
	test.add_element(0, 2);
	test.add_element(0, 1);
	test.swipe_right();
	EXPECT_EQ(test.get_element(0, 3), 2);
	EXPECT_EQ(test.get_element(2, 3), 2);
	EXPECT_EQ(test.get_element(2, 1), 0);
	EXPECT_EQ(test.get_element(0, 2), 0);
	EXPECT_EQ(test.get_element(0, 1), 0);

}

TEST(TestPuzzle, TestSwipeTop) {
	Puzzle test;
	test.add_element(0, 0);
	test.add_element(1, 0);
	test.add_element(2, 1);
	test.swipe_top();
	EXPECT_EQ(test.get_element(0, 0), 2);
	EXPECT_EQ(test.get_element(1, 0), 0);
	EXPECT_EQ(test.get_element(0, 1), 1);
	EXPECT_EQ(test.get_element(1, 2), 0);
}

TEST(TestPuzzle, TestSwipeTop2) {
	Puzzle test;
	test.add_element(0, 0);
	test.add_element(1, 0);
	test.add_element(2, 1);
	test.add_element(3, 1);
	test.swipe_top();
	EXPECT_EQ(test.get_element(0, 0), 2);
	EXPECT_EQ(test.get_element(1, 0), 0);
	EXPECT_EQ(test.get_element(0, 1), 2);
	EXPECT_EQ(test.get_element(0, 2), 0);
	EXPECT_EQ(test.get_element(2, 1), 0);
	EXPECT_EQ(test.get_element(2, 2), 0);

}

TEST(TestPuzzle, TestSwipeLow) {
	Puzzle test;
	test.add_element(0, 0);
	test.add_element(1, 0);
	test.add_element(2, 1);
	test.swipe_low();
	EXPECT_EQ(test.get_element(3, 0), 2);
	EXPECT_EQ(test.get_element(1, 0), 0);
	EXPECT_EQ(test.get_element(3, 1), 1);
	EXPECT_EQ(test.get_element(1, 2), 0);
}

TEST(TestPuzzle, TestSwipeLow2) {
	Puzzle test;
	test.add_element(0, 0);
	test.add_element(1, 0);
	test.add_element(1, 2);
	test.add_element(2, 2);
	test.add_element(0, 2);
	test.swipe_low();
	EXPECT_EQ(test.get_element(3, 0), 2);
	EXPECT_EQ(test.get_element(1, 0), 0);
	EXPECT_EQ(test.get_element(3, 2), 2);
	EXPECT_EQ(test.get_element(1, 2), 0);
	EXPECT_EQ(test.get_element(2, 2), 1);
	EXPECT_EQ(test.get_element(2, 1), 0);
}

TEST(TestPuzzle, TestCountElement) {
	Puzzle test;
	test.add_element_random();
	test.add_element_random();
	test.add_element_random();
	EXPECT_EQ(test.count_element(), 3);
}

TEST(TestPuzzle, TestDefeat1) {
	Puzzle test;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			test.add_element(j, i);
		}
	}
	EXPECT_EQ(test.puzzle_end(), true);
}

TEST(TestPuzzle, TestDefeat2) {
	Puzzle test;
	test.add_element_random();
	test.add_element_random();
	EXPECT_EQ(test.puzzle_end(), false);
}
