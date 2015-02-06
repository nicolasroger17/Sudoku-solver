#ifndef __SOLVER_H__
#define __SOLVER_H__

#include "Position.h"

class Solver{
	// the grid
	int **grid;

public:
	Solver(int ** newGrid) :grid(newGrid){}
	~Solver();

	Position * next(Position * p);

	bool isInsertableInRow(Position * p, int number);
	bool isInsertableInCol(Position * p, int number);
	bool isInsertableInSquare(Position * p, int number);
	bool solve(Position * p);
	bool solve();
	void display();
	void rawDisplay();
};

#endif