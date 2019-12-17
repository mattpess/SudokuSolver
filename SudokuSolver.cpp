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

	bool looping = true;
	int input, input2, input3;
	while (looping) 
	{
		
		printf("Type in the row you would like to input on, or 0 to exit: ");
		cin >> input;
		if (input > 0 && input <= MAX)
		{
			printf("Type in the column you would like to input on: ");
			cin >> input2;
			if (input2 > 0 && input2 <= MAX)
			{
				printf("Type in the value you would like to input: ");
				cin >> input3;
				if (input2 > 0 && input2 <= MAX)
				{
					input--;
					input2--;
					list[input][input2] = Cell(input2, input, (((input) / 3) * 3) + ((input2) / 3), input3);
					list[input][input2].setHint(true);
				}
			}
		}
		else
		{
			looping = false;
		}
	}

	// Random cell population loop

	// Outer loop handles column traversal
	for (int outer_loop = 0; outer_loop < MAX; outer_loop++)
	{
		printf("\n\n");
		// Inner loop handles row traversal 
		for (int inner_loop = 0; inner_loop < MAX; inner_loop++)
		{
			// Do not populate cell if it is a hint cell
			if (!list[outer_loop][inner_loop].isHint())
			{
				// Random value generated to populate cell
				int setVal = rand() % 30 + 1;
				// Roughly 2/3 chance of cell being blank
				if (setVal > MAX)
				{
					setVal = 0;
				}
				// Create cell with random value
				list[outer_loop][inner_loop] = Cell(inner_loop, outer_loop, (((outer_loop) / 3) * 3) + ((inner_loop) / 3), setVal);
				
			}
			// Link cell to its relevant groups
			row[inner_loop].addCell(list[outer_loop][inner_loop]);
			col[outer_loop].addCell(list[outer_loop][inner_loop]);
			box[(((outer_loop) / 3) * 3) + ((inner_loop) / 3)].addCell(list[outer_loop][inner_loop]);
			// Output cell
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

	looping = true;
	while (looping) {
		printf("Type 1 for a row, 2 for a column, 3 for a box, and 4 to exit: ");
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
		case 4:
			looping = false;
			break;
		}
	}
	


}

