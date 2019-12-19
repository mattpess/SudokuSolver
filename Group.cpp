// Group.cpp
// 12/19/2019
// Version 1.0
// Implementation for Group objects; maintains the rows, columns, and boxes a sudoku puzzle has.

#include "Group.h"

Group::Group()
{
	
	cell_index = 0;

}

bool Group::isLegal(Cell list[MAX][MAX])
{
	// Set all to false
	int wasSeen[MAX] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	// Loop through list tracking values
	for (int element : groupList)
	{
		// Decrement value so it maps to the right index
		int value = list[element/MAX][element%MAX].getValue();
		//printf("Value during isLegal(): %d\n", element.getValue());
		if (value > 0 && wasSeen[value-1] == 1) 
		{
			return false;
		}
		else if(value > 0)
		{
			wasSeen[value-1] = 1;
		}
	}
	return true;
}

void Group::addCell(int newCell)
{ 
	// If the group does not already have 9 members
	if (cell_index < MAX) 
	{
		groupList[cell_index] = newCell;
	}
	// Increment pointer to next available cell
	cell_index++;
}

void Group::displayCells(Cell list[MAX][MAX])
{
	for (int element : groupList)
	{
		int value = list[element / MAX][element % MAX].getValue();
		if (value != 0)
		{
			printf("%d  ", value);
		}
		else
		{
			printf("-  ");
		}
	}
	printf("\n");
}
