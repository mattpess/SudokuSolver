// Group.cpp
// 12/14/2019
// Version 0.1
// Implementation for Group objects; maintains the rows, columns, and boxes a sudoku puzzle has.

#include "Group.h"

Group::Group()
{
	int i = 0;
	// Transfer contents of the array to the object variable
	while(i < MAX)
	{
		groupList[i] = Cell();
		i++;
	}
	cell_index = 0;
}

bool Group::isLegal()
{
	// Set all to false
	int wasSeen[MAX] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	// Loop through list tracking values
	for (Cell element : groupList)
	{
		// Decrement value so it maps to the right index
		int value = element.getValue() - 1;
		//printf("Value during isLegal(): %d\n", element.getValue());
		if (value >= 0 && wasSeen[value] == 1) 
		{
			return false;
		}
		else if(value > 0)
		{
			wasSeen[value] = 1;
		}
	}
	return true;
}

Cell Group::getCell(int index)
{
	if (index < MAX && index > -1)
	{
		return groupList[index];
	}
	else {
		return Cell();
	}
}

void Group::addCell(Cell& newCell)
{ 
	// If the group does not already have 9 members
	if (cell_index < MAX) 
	{
		groupList[cell_index] = newCell;
	}
	// Increment pointer to next available cell
	cell_index++;
}

void Group::displayCells()
{
	for (Cell element : groupList)
	{
		if (element.getValue() != 0)
		{
			printf("%d  ", element.getValue());
		}
		else
		{
			printf("   ");
		}
	}
	printf("\n");
}
