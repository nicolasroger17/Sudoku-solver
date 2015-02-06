// Sudoku.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Solver.h"

using namespace std;

void fileReader(int ** grid, const char * path);
void inputReader(int ** grid, char * input);

int main(int argc, char *argv[]){
	bool output = false;
	char inputType = '\0';

	if (argc > 1){
		string param = static_cast<string>(argv[1]);
		if (param.find('d') != string::npos)
			output = true;

		if (param.find('f') != string::npos && argc > 2)
			inputType = 'f';
		else if (param.find('i') != string::npos && argc > 2)
			inputType = 'i';
	}

	int **grid = new int*[9]; // dynamic array (size 10) of pointers to int

	for (int i = 0; i < 9; ++i) {
		grid[i] = new int[9];
	}

	switch (inputType){
		case 'f':
			fileReader(grid, argv[2]);
			break;
		case 'i':
			inputReader(grid, argv[2]);
			break;
		default:
			fileReader(grid, "grid.txt\0");
			break;
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