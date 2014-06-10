main: main.o lr.o
	g++ -o main main.o lr.o
main.o: main.cc logistic_regression.h
	g++ -o main.o -c main.cc
lr.o: logistic_regression.cc logistic_regression.h
	g++ -o lr.o -c logistic_regression.cc
clean:
	rm *.o
