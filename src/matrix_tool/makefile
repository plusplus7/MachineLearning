main: main.o mat.o
	g++ -o main -Wall main.o mat.o
main.o: main.cc matrix_tool.h
	g++ -o main.o -Wall -c main.cc
mat.o: matrix_tool.cc matrix_tool.h
	g++ -o mat.o -c matrix_tool.cc -Wall
clean:
	rm *.o

