all: hw5

Command.o: Command.h Command.cpp
	g++ -std=c++11 -Wall -g -c Command.cpp -o Command.o

BooleanExpression.o:BooleanExpression.h BooleanExpression.cpp
	g++ -std=c++11 -Wall -g -c BooleanExpression.cpp -o BooleanExpression.o

ArithmeticExpression.o:ArithmeticExpression.h ArithmeticExpression.cpp
	g++ -std=c++11 -Wall -g -c ArithmeticExpression.cpp -o ArithmeticExpression.o


hw5: hw5.cpp ArithmeticExpression.o BooleanExpression.o Command.o
	g++ -std=c++11 -Wall -g  ArithmeticExpression.cpp BooleanExpression.cpp Command.cpp hw5.cpp -o hw5
