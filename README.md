# Sudoku-solver

## Introduction

This is a basic brute force sudoku solver

## Options

The program accepts 3 options:

d : to display the sudoku in a readable way,
	if not set returns it will output the grid solved with only numbers and carriage return.
i : to give a raw input
f : to give a file

## Usage

### Default file

Modify the content of grid.txt

### Special file

Use the option -f and the path to the file:

./sudoku -f path/to/file

### Raw input

Give an input string to the program:

./sudoku -i someInput

### Examples

#### Input file with easy reabable content

./sudoku -fd path/to/file

#### Raw input redirected to a file

./sudoku -i 1xx4xx37x2xx6xxxx9xxxx8xxxxx4xx9xx3xx21xxx58xx6xx5xx1xxxxx4xxxx6xxxx7xx5x39xx6xx8 > output.txt
