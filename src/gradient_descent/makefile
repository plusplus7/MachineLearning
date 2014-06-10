main: main.o sgd.o bgd.o
	g++ -o main main.o sgd.o bgd.o
main.o: main.cc	
	g++ -o main.o -c main.cc
sgd.o: stochastic_gradient_descent.cc stochastic_gradient_descent.h
	g++ -o sgd.o -c stochastic_gradient_descent.cc
bgd.o: batch_gradient_descent.cc batch_gradient_descent.h 
	g++ -o bgd.o -c batch_gradient_descent.cc
clean:
	rm *.o
