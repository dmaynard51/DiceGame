output: main.o Die.o LoadedDie.o game.o 
	g++ main.o Die.o LoadedDie.o game.o -o lab3 

main.o: main.cpp 
	g++ -c main.cpp

Die.o: Die.cpp Die.hpp
	g++ -g -c -std=c++11 Die.cpp


LoadedDie.o: LoadedDie.cpp LoadedDie.hpp
	g++ -g -c -std=c++11 LoadedDie.cpp


game.o: game.cpp game.hpp
	g++ -g -c -std=c++11 game.cpp

clean:
	rm *.o lab3
