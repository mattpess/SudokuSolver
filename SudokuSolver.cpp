// SudokuSolver.cpp
// 12/14/2019
// Version 0.1
// Main class of operation for the automated sudoku solving system.

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Group.h"

int main()
{
	srand(time(NULL));
	Cell list[MAX][MAX];
	Group row[MAX];
	Group col[MAX];
	Group box[MAX];

	
	for (int outer_loop = 0; outer_loop < MAX; outer_loop++)
	{
		printf("\n\n");
		for (int inner_loop = 0; inner_loop < MAX; inner_loop++)
		{
			int setVal = rand() % 30 + 1;
				if (setVal > MAX)
				{
					setVal = 0;
				}
				list[outer_loop][inner_loop] = Cell(inner_loop, outer_loop, (((outer_loop) / 3) * 3) + ((inner_loop) / 3), setVal);
			row[inner_loop].addCell(list[outer_loop][inner_loop]);
			col[outer_loop].addCell(list[outer_loop][inner_loop]);
			box[(((outer_loop) / 3) * 3) + ((inner_loop) / 3)].addCell(list[outer_loop][inner_loop]);
			if (list[outer_loop][inner_loop].getValue() != 0)
			{
				printf("%d   ", list[outer_loop][inner_loop].getValue());
			}
			else
			{
				printf("    ");
			}
		}
	}
	printf("\n\n");
	int input;
	while (1) {
		printf("Type 1 for a row, 2 for a column, and 3 for a box: ");
		cin >> input;
		switch (input)
		{
		case 1:
			printf("Type the number of the row you would like to show: ");
			cin >> input;
			if (input <= MAX && input > 0) 
			{
				row[input - 1].displayCells();
				if (row[input - 1].isLegal()) 
				{
					printf("This group is also a legal group\n.");
				}
			}
			break;
		case 2:
			printf("Type the number of the column you would like to show: ");
			cin >> input;
			if (input <= MAX && input > 0) 
			{
				col[input - 1].displayCells();
				if (col[input - 1].isLegal())
				{
					printf("This group is also a legal group.\n");
				}
			}
			break;
		case 3:
			printf("Type the number of the box you would like to show: ");
			cin >> input;
			if (input <= MAX && input > 0) 
			{
				box[input - 1].displayCells();
				if (box[input - 1].isLegal())
				{
					printf("This group is also a legal group.\n");
				}
			}
			break;
		}
	}
	


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu

