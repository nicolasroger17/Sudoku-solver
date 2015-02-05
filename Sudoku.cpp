// Sudoku.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Solver.h"

using namespace std;

int main(){
	int grid[9][9] = {
		{ 1, 0, 0, 4, 0, 0, 3, 7, 0 },
		{ 2, 0, 0, 6, 0, 0, 0, 0, 9 },
		{ 0, 0, 0, 0, 8, 0, 0, 0, 0 },
		{ 0, 4, 0, 0, 9, 0, 0, 3, 0 },
		{ 0, 2, 1, 0, 0, 0, 5, 8, 0 },
		{ 0, 6, 0, 0, 5, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 4, 0, 0, 0, 0 },
		{ 6, 0, 0, 0, 0, 7, 0, 0, 5 },
		{ 0, 3, 9, 0, 0, 6, 0, 0, 8 }
	};

	Solver * s = new Solver(grid);
	
	s->display();

	cout << "solving . . . " << endl;

	s->solve();

	s->display();

	cout << "solved !" << endl;

	delete s;

	char f;
	cin >> f;

	return 0;
}