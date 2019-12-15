// SudokuSolver.cpp
// 12/14/2019
// Version 0.1
// Main class of operation for the automated sudoku solving system.

#include <iostream>
#include "Group.h"

int main()
{
	Cell list[MAX][MAX];
	
	for (int outer_loop = 0; outer_loop < MAX; outer_loop++)
	{
		printf("\nCurrent row: %d\n\n", outer_loop);
		for (int inner_loop = 0; inner_loop < MAX; inner_loop++)
		{
			list[outer_loop][inner_loop] = Cell(inner_loop, outer_loop, (((outer_loop) / 3) * 3) +((inner_loop) / 3), inner_loop + 1);
			printf("Value: %d\tIs hint: %d\tRow, column, box: %d %d %d\n", list[outer_loop][inner_loop].getValue(), list[outer_loop][inner_loop].isHint(), list[outer_loop][inner_loop].getGroup(0), list[outer_loop][inner_loop].getGroup(1), list[outer_loop][inner_loop].getGroup(2));
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu

