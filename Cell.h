// Cell.h
// 12/14/2019
// Version 0.1
// Header for Cell objects; maintains the value and groups that a cell in a sudoku puzzle has.

#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>
using namespace std;
const static int MAX = 9;

class Cell
{
public:
	/*
	Purpose: Default constructor
	Parameters: None
	Output: Blank Cell.
	*/
	Cell();
	/*
	Purpose: Constructor for empty Cell.
	Parameters: The index for its row, column, and box.
	Output: Constructed Cell.
	*/
	Cell(int rowIndex, int colIndex, int boxIndex);
	/*
	Purpose: Constructor for non-hint Cell.
	Parameters: The index for its row, column, and box.
	Output: Constructed Cell that cannot be changed.
	*/
	Cell(int rowIndex, int colIndex, int boxIndex, int value);
	/*
	Purpose: Setter for value.
	Parameters: New setter value.
	Output: True if new value set, false otherwise.
	*/
	
	bool setValue(int newValue);
	/*
	Purpose: Getter for value.
	Parameters: None.
	Output: Value of cell, 0 if not set.
	*/
	int getValue();
	/*
	Purpose: Get group for row, column, or box.
	Parameters: Integer to distiguish which group the output should be.
	Output: Row index if 0, column index if 1, box index if 2.
	*/
	int getGroup(int whichGroup);
	/*
	Purpose: Check if cell is a hint value (provided at start, cannot be changed).
	Parameters: None.
	Output: True if hint value, false otherwise.
	*/
	bool isHint();
	/*
	Purpose: Set the hint status.
	Parameters: Bool to set the hint status to
	Output: None.
	*/
	void setHint(bool status);
	/*
	Purpose: Increment value of cell
	Parameters: None.
	Output: True if successful increment, false if value is already at max.
	*/
	bool increment();
private:
	// The value of the cell
	int value;
	// Index of row cell is in
	int rowIndex;
	// Index of column cell is in
	int colIndex;
	// Index of block cell is in
	int boxIndex;
	// Indicates if a cell is a provided hint cell
	bool hint;
};

#endif

