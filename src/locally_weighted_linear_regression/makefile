main: main.o lwlr.o
	g++ -o main main.o lwlr.o
main.o: main.cc
	g++ -o main.o -c main.cc
lwlr.o: locally_weighted_linear_regression.cc locally_weighted_linear_regression.h
	g++ -o lwlr.o -c locally_weighted_linear_regression.cc
clean:
	rm *.o main
