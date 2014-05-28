main: main.o bgd.o
	g++ -o main main.o bgd.o
main.o: main.cc	
	g++ -o main.o -c main.cc
bgd.o: batch_gradient_descent.cc batch_gradient_descent.h
	g++ -o bgd.o -c batch_gradient_descent.cc

clean:
	rm *.o
