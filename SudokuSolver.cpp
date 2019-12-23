// SudokuSolver.cpp
// 12/19/2019
// Version 1.0
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
	int input, input2, input3, hints = 0;

	// start hint input loop
	while (looping) 
	{
		
		printf("Type in the row you would like to input on, or 0 to exit: ");
		cin >> input;
		if (!cin.fail())
		{
			if (input > 0 && input <= MAX)
			{
				printf("Type in the column you would like to input on: ");
				cin >> input2;
				if (!cin.fail())
				{
					if (input2 > 0 && input2 <= MAX)
					{
						printf("Type in the value you would like to input: ");
						cin >> input3;
						if (!cin.fail())
						{
							if (input3 > 0 && input3 <= MAX)
							{
								printf("Placing value of %d at row %d and column %d.\n ", input3, input, input2);
								input--;
								input2--;
								list[input][input2] = Cell(input2, input, (((input) / 3) * 3) + ((input2) / 3), input3);
								list[input][input2].setHint(true);
								hints++;
							}
						}
					}
				}
			}
			else
			{
				looping = false;
			}
		}
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
		}
	}

	// if there are under 17 hints, there are multiple solutions to a puzzle
	if (hints < 17)
	{
		printf("\n\nYou only have supplied %d hints; your puzzle will have multiple solutions and the system will only provide one.\n\n", hints);
	}

	// Random cell population loop

	// Outer loop handles column traversal
	for (int outer_loop = 0; outer_loop < MAX; outer_loop++)
	{
		printf("\n\n");
		// Inner loop handles row traversal 
		for (int inner_loop = 0; inner_loop < MAX; inner_loop++)
		{
			// Do not populate cell if it is a hint cell already created
			if (!list[outer_loop][inner_loop].isHint())
			{

				// Create cell with empty value
				list[outer_loop][inner_loop] = Cell(inner_loop, outer_loop, (((outer_loop) / 3) * 3) + ((inner_loop) / 3), 0);
				
			}
			// Link cell to its relevant groups, even if hint cell
			row[inner_loop].addCell((inner_loop)+(outer_loop*MAX));
			col[outer_loop].addCell((inner_loop)+(outer_loop * MAX));
			box[(((outer_loop) / 3) * 3) + ((inner_loop) / 3)].addCell((inner_loop)+(outer_loop * MAX));
			// Output cell
			if (list[outer_loop][inner_loop].getValue() != 0)
			{
				printf("%d   ", list[outer_loop][inner_loop].getValue());
			}
			else
			{
				printf("-   ");
			}
		}
	}

	// Check if hints provided are already invalid in a group and will never be solvable.

	for (Group element : row)
	{
		if (!element.isLegal(list))
		{
			printf("\n\nYou have provided an invalid hint in a row.\n");
			exit(1);
		}
	}
	for (Group element : col)
	{
		if (!element.isLegal(list))
		{
			printf("\n\nYou have provided an invalid hint in a column.\n");
			exit(1);
		}
	}
	for (Group element : box)
	{
		if (!element.isLegal(list))
		{
			printf("\n\nYou have provided an invalid hint in a box.\n");
			exit(1);
		}
	}

	printf("\n\nBeginning to brute force solution.\n\n");
	
	int index = 0;
	while (index < MAX * MAX && index >= 0) {
		// increment if an empty cell
		if (list[index / MAX][index % MAX].getValue() == 0)
		{
			list[index / MAX][index % MAX].increment();

		}
		//printf("index: %d   value after increment: %d\n", index, list[index / MAX][index % MAX].getValue());
		// check if cell is valid on all three groups 
		if (row[(list[index / MAX][index % MAX].getGroup(0))].isLegal(list) 
			&& col[(list[index / MAX][index % MAX].getGroup(1))].isLegal(list) 
			&& box[(list[index / MAX][index % MAX].getGroup(2))].isLegal(list))
		{
			//printf("%d %d\n", index / MAX, index % MAX);
			//if so increment index until not hint
			do
			{
				index++;
			} while (list[index / MAX][index % MAX].isHint());

		}
		//else increment value
		else
		{
			while (list[index / MAX][index % MAX].increment() == false) {
				//if value goes beyond MAX, decrement index and increment value until it does not return false
				index--;
			}
		}

		
		

	}

	// print out finished puzzle
	for (int outer_loop = 0; outer_loop < MAX; outer_loop++) 
	{
		printf("\n\n");
		for (int inner_loop = 0; inner_loop < MAX; inner_loop++)
		{
			printf("%d   ", list[outer_loop][inner_loop].getValue());
		}
	}
	printf("\n\n");

	looping = true;
	while (looping) {
		printf("Type 1 for a row, 2 for a column, 3 for a box, and 4 to exit: ");
		cin >> input;
		if (!cin.fail())
		{
			switch (input)
			{
			case 1:
				printf("Type the number of the row you would like to show: ");
				cin >> input;
				if (!cin.fail())
				{
					if (input <= MAX && input > 0)
					{
						row[input - 1].displayCells(list);
						if (row[input - 1].isLegal(list))
						{
							printf("This group is also a legal group.\n");
						}
					}
				}
				break;
			case 2:
				printf("Type the number of the column you would like to show: ");
				cin >> input;
				if (!cin.fail())
				{
					if (input <= MAX && input > 0)
					{
						col[input - 1].displayCells(list);
						if (col[input - 1].isLegal(list))
						{
							printf("This group is also a legal group.\n");
						}
					}
				}
				break;
			case 3:
				printf("Type the number of the box you would like to show: ");
				cin >> input;
				if (!cin.fail())
				{
					if (input <= MAX && input > 0)
					{
						box[input - 1].displayCells(list);
						if (box[input - 1].isLegal(list))
						{
							printf("This group is also a legal group.\n");
						}
					}
				}
				break;
			case 4:
				looping = false;
				break;
			}
		}
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
	
	


}

