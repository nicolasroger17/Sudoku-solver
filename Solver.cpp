#include <iostream>
#include "Solver.h"

using namespace std;

/**
* destructor
**/
Solver::~Solver(){
	for (int i = 0; i < 9; ++i)
		delete[] grid[i];
	delete [] grid;
}

/**
* take the position a the case and the number that we want to had
* and check if this number already exists in the row
**/
bool Solver::isInsertableInRow(Position * p, int number) {
	for (int i = 0; i != 9; i++) {
		if (grid[p->getRow()][i] == number) {
			return false;
		}
	}
	return true;
}

/**
* take the position a the case and the number that we want to had
* and check if this number already exists in the column
**/
bool Solver::isInsertableInCol(Position * p, int number) {
	for (int i = 0; i != 9; i++) {
		if (grid[i][p->getCol()] == number) {
			return false;
		}
	}
	return true;
}

/**
* take the position a the case and the number that we want to had
* and check if this number already exists in the square (3x3)
**/
bool Solver::isInsertableInSquare(Position * p, int number) {
	int startingRow = 0;
	int startingCol = 0;
	// We need to position ourselves at the beginning of the square (3x3) containing the case
	// so we need to make so check

	startingRow = p->getRow() - (p->getRow() % 3);
	startingCol = p->getCol() - (p->getCol() % 3);

	for (int j = startingRow; j != startingRow + 3; j++) {
		for (int i = startingCol; i != startingCol + 3; i++) {
			if (grid[j][i] == number) {
				return false;
			}
		}
	}
	return true;
}

/**
* solve from first position
**/
bool Solver::solve(){
	Position * p = new Position(0, 0);
	return solve(p);
}

/**
* solve the sudoku
**/
bool Solver::solve(Position * p) {

	if (p->getRow() == 9 && p->getCol() == 0)
		return true;
	else {
		// if the case is empty, we try to find the number
		if (grid[p->getRow()][p->getCol()] == 0) {
			// testing from 1 to 9
			for (int i = 1; i != 10; i++) {
				// we check if the number suits there
				if (isInsertableInRow(p, i) && isInsertableInCol(p, i) && isInsertableInSquare(p, i)) {
					// if it does insert it
					grid[p->getRow()][p->getCol()] = i;
					// on appelle la fonction sur la case suivante
					if (solve(p->next()))						
						return true;
				}
			}
			// if we're out of the loop, the number doesn't suit, so we reset it to 0
			grid[p->getRow()][p->getCol()] = 0;
			return false;
		}
		else {
			// if the case is not empty (0), we call the solver on the next case
			return solve(p->next());
		}
	}
}

/**
* basic display of the board
**/
void Solver::display() {

	cout << "+---+---+---+" << endl;

	for (int i = 0; i != 9; i++) {

		for (int j = 0; j != 9; j++) {

			if (j % 3 == 0) {

				cout << "|";

			}
			if (grid[i][j] > 0)
				cout << grid[i][j];
			else
				cout << " ";

		}

		cout << "|" << endl;

		if (i == 2 || i == 5 || i == 8) {

			cout << "+---+---+---+" << endl;

		}
	}
}

void Solver::rawDisplay(){
	for (int i = 0; i != 9; i++) {
		for (int j = 0; j != 9; j++)
			cout << grid[i][j];

		cout << endl;
	}
}