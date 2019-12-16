// Group.h
// 12/14/2019
// Version 0.1
// Header for Group objects; maintains the rows, columns, and boxes a sudoku puzzle has.

#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include <string>
#include "Cell.h"
using namespace std;

class Group
{
public:
	/*
	Purpose: Default Group constructor.
	Parameters: None.
	Output: Constructed Group object with empty cells.
	*/
	Group();
	/*
	Purpose: Checks if the Group has any duplicate cell values in it.
	Parameters: None.
	Output: False if a repeated value is found, true otherwise.
	*/
	bool isLegal();
	/*
	Purpose: Get a Cell based on the provided index
	Parameters: An int for the index of the Cell in the array
	Output: The selected cell of the index, otherwise a generated cell with a value of -1.
	*/
	Cell getCell(int index);
	/*
	Purpose: Add Cell to list.
	Parameters: The Cell to be added.
	Output: None.
	*/
	void addCell(Cell newCell);
	/*
	Purpose: Print Cells to cout.
	Parameters: Nope.
	Output: Cell values to cout.
	*/
	void displayCells();
private:
	// array of values in group
	Cell groupList[MAX];
	// current index of next empty cell
	int cell_index;
};

#endif
