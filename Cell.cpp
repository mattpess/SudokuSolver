// Cell.cpp
// 12/14/2019
// Version 0.1
// Implementation for Cell objects; maintains the value and groups that a cell in a sudoku puzzle has.

#include "Cell.h"


// This constructor is necessary to avoid an error with objects that use a list of this object, but should never be used with this object.
Cell::Cell()
{
	// Used mainly for error-checking that an empty constructor has not appeared in an actual puzzle.
	this->value = 0;
	// Index of row cell is in
	this->rowIndex = -1;
	// Index of column cell is in
	this->colIndex = -1;
	// Index of block cell is in
	this->boxIndex = -1;
	// Indicates if a cell is a provided hint cell
	this->hint = false;
}

Cell::Cell(int rowIndex, int colIndex, int boxIndex)
{
	// The value of the cell
	// Default value is zero for empty cell
	this->value = 0;
	// Index of row cell is in
	this->rowIndex = rowIndex;
	// Index of column cell is in
	this->colIndex = colIndex;
	// Index of block cell is in
	this->boxIndex = boxIndex;
	// Indicates if a cell is a provided hint cell
	this->hint = false;
}

Cell::Cell(int rowIndex, int colIndex, int boxIndex, int value)
{
	// The value of the cell
	this->value = value;
	// Index of row cell is in
	this->rowIndex = rowIndex;
	// Index of column cell is in
	this->colIndex = colIndex;
	// Index of block cell is in
	this->boxIndex = boxIndex;
	// Indicates if a cell is a provided hint cell
	this->hint = false;
}



bool Cell::setValue(int newValue)
{
	if (hint == false) 
	{
		value = newValue;
		return true;
	}
	return false;

}

int Cell::getValue() { return value; }

int Cell::getGroup(int whichGroup)
{
	if (whichGroup == 0) { return rowIndex; }
	if (whichGroup == 1) { return colIndex; }
	return boxIndex;
}

bool Cell::isHint() { return hint; }

void Cell::setHint(bool status)
{
	hint = status;
}

bool Cell::increment()
{
	// increment value if it is not MAX, otherwise revert back to empty value
	value = (value != MAX) ? value + 1 : 0;
	// return if increment was successful
	return (value != 0);
}
