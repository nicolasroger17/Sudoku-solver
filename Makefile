CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = sudoku
OBJECTS = Position.o Solver.o Sudoku.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}