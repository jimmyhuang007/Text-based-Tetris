CXX=g++
CXXFLAGS=-std=c++14 -Wall -Werror=vla -MMD
OBJECTS=main.o ABlock.o IBlock.o JBlock.o LBlock.o OBlock.o SBlock.o ZBlock.o TBlock.o KBlock.o EBlock.o Cell.o BG.o Grid.o Interpreter.o graphics.o window.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=quadris

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm *.o quadris
.PHONY: clean
