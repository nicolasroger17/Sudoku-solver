// Sudoku.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>	
#include "Solver.h"

using namespace std;

void fileReader(int ** grid, const char * path);
void inputReader(int ** grid, char * input);

int main(int argc, char *argv[]){
	bool output = true;

	int **grid = new int*[9]; // dynamic array (size 10) of pointers to int

	for (int i = 0; i < 9; ++i) {
		grid[i] = new int[9];
	}

	if (argc == 2){
		inputReader(grid, argv[1]);
	}
	else if (argc == 3){
		if (static_cast<string>(argv[1]) == "-f"){
			fileReader(grid, argv[2]);
			output = false;
		}
		else
			exit(2);
	}
	else{
		fileReader(grid, "grid.txt\0");
	}

	Solver * s = new Solver(grid);

	if (output){
		s->display();
		cout << "solving . . . " << endl;
	}

	s->solve();

	if (output){
		s->display();
		cout << "solved !" << endl;
		char f;
		cin >> f;
	}
	else
		s->rawDisplay();

	delete s;

	return 0;
}

void fileReader(int ** grid, const char * path){
	char c;
	ifstream myfile(path);
	if (myfile.is_open()){
		for (int i = 0; i < 9; ++i) {   // for each row
			for (int j = 0; j < 9; ++j) { // for each column
				myfile.get(c);
				if ((c - '0') > 9)
					grid[i][j] = 0;
				else if ((c - '0') >= 0)
					grid[i][j] = c - '0';
				else
					j--;
			}
		}
		myfile.close();
	}
	else
		exit(3);
}

void inputReader(int ** grid, char * input){
	int counter = 0;
	char c;
	for (int i = 0; i < 9; ++i) {   // for each row
		for (int j = 0; j < 9; ++j) { // for each column
			c = input[counter];
			if ((c - '0') > 9)
				grid[i][j] = 0;
			else if ((c - '0') >= 0)
				grid[i][j] = c - '0';
			counter++;
		}
	}
}