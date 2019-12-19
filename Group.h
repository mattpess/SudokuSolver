// Group.h
// 12/19/2019
// Version 1.0
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
	bool isLegal(Cell list[MAX][MAX]);
	/*
	Purpose: Add Cell to list.
	Parameters: The Cell to be added.
	Output: None.
	*/
	void addCell(int newCell);
	/*
	Purpose: Print Cells to cout.
	Parameters: Nope.
	Output: Cell values to cout.
	*/
	void displayCells(Cell list[MAX][MAX]);
private:
	// array of values in group
	int groupList[MAX] = { -1 };
	// current index of next empty cell
	int cell_index;
};

#endif
