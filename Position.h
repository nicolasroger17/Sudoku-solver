#ifndef __POSITION_H__
#define __POSITION_H__

class Position{
	int row, col;

public:
	Position(int row, int col) :row(row), col(col){}
	~Position(){}

	Position * next();

	int getRow();
	int getCol();
};

#endif