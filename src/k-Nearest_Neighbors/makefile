main: main.o knn.o
	g++ -o main main.o knn.o
knn.o: k_NN.h
	g++ -o knn.o -c k_NN.cc
main.o: k_NN.h
	g++ -o main.o -c main.cc
clean:
	rm *.o main
