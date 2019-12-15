// Group.cpp
// 12/14/2019
// Version 0.1
// Implementation for Group objects; maintains the rows, columns, and boxes a sudoku puzzle has.

#include "Group.h"

Group::Group(Cell list[])
{
	int i = 0;
	// Transfer contents of the array to the object variable
	while(i < MAX)
	{
		groupList[i] = list[i];
		i++;
	}
}

bool Group::isLegal()
{
	// Set all to false
	bool wasSeen[MAX] = { 0 };

	// Loop through list tracking values
	for (Cell element : groupList)
	{
		// Decrement value so it maps to the right index
		int value = element.getValue() - 1;
		if (wasSeen[value]) 
		{
			return false;
		}
		else
		{
			wasSeen[value] = true;
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
