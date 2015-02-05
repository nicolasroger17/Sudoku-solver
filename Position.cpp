#include <iostream>
#include "Position.h"

/**
* return the next position
* check if not end of line or end of grid
**/
Position * Position::next(){

	Position * next = new Position(row, col);

	if (col != 8)
		next->col = col + 1;
	else if (col == 8) {
		next->row = row + 1;
		next->col = 0;
	}
	return next;
}

int Position::getRow(){
	return row;
}

int Position::getCol(){
	return col;
}