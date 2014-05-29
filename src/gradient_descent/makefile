main: main.o sgd.o
	g++ -o main main.o sgd.o
main.o: main.cc	
	g++ -o main.o -c main.cc
sgd.o: stochastic_gradient_descent.cc stochastic_gradient_descent.h
	g++ -o sgd.o -c stochastic_gradient_descent.cc

clean:
	rm *.o
