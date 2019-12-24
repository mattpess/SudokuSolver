// SudokuSolver.cpp
// 12/19/2019
// Version 1.0
// Main class of operation for the automated sudoku solving system.

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <sstream>
#include "Group.h"

int main()
{
	int input_choice;
	Cell list[MAX][MAX];
	Group row[MAX];
	Group col[MAX];
	Group box[MAX];
	int input, input2, input3;

	bool looping = true;
	int hints = 0;

	// decision between file input and text input
	do
	{
		printf("Input 1 for file input of hints or 2 for console input of hints: ");
		
		cin >> input_choice;
	}
	while (cin.fail());
	
	if (input_choice == 1)
	{


		// begin file handling
		string file_input;
		printf("Type the file name with extension containing hint inputs. Each line should be formatted 'row column value': ");
		cin >> file_input;
		ifstream infile(file_input);

		if (infile.fail())
		{
			printf("File does not exist.\n");
			exit(1);
		}

		// start hint input loop
		// references: https://stackoverflow.com/questions/7868936/read-file-line-by-line-using-ifstream-in-c

		string line;
		while (getline(infile, line))
		{
			istringstream iss(line);
			int input, input2, input3;
			if (!(iss >> input >> input2 >> input3))
			{
				printf("Invalid file input.\n");
			}
			if (input > 0 && input <= MAX && input2 > 0 && input2 <= MAX && input3 > 0 && input3 <= MAX)
			{
				input--;
				input2--;
				list[input][input2] = Cell(input2, input, (((input) / 3) * 3) + ((input2) / 3), input3);
				list[input][input2].setHint(true);
				hints++;
			}
		}
	}
	else
	{
		while (looping)
		{

			printf("Type in the row you would like to input on, or 0 to exit: ");
			cin >> input;
			// confirms that inputs are integers
			if (!cin.fail())
			{
				if (input > 0 && input <= MAX)
				{
					printf("Type in the column you would like to input on: ");
					cin >> input2;
					// confirms that inputs are integers
					if (!cin.fail())
					{
						if (input2 > 0 && input2 <= MAX)
						{
							printf("Type in the value you would like to input: ");
							cin >> input3;
							// confirms that inputs are integers
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
			// Cin input must be check for being valid int inputs or else they are dropped.
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
			}
		}
	}
	
	// if there are under 17 hints, there are multiple solutions to a puzzle
	if (hints < 17)
	{
		printf("\n\nYou only have supplied %d hints; your puzzle will have multiple solutions and the system will only provide one.\n\n", hints);
	}

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
		// check if cell is valid on all three groups 
		if (row[(list[index / MAX][index % MAX].getGroup(0))].isLegal(list) 
			&& col[(list[index / MAX][index % MAX].getGroup(1))].isLegal(list) 
			&& box[(list[index / MAX][index % MAX].getGroup(2))].isLegal(list))
		{
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
}

