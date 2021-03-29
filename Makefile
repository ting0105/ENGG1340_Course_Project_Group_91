combat.o: combat.cpp main.h
  g++ -c -pedantic-errors -std=c++11 combat.cpp

stat_gen.o: stat_gen.cpp main.h
	g++ -c -pedantic-errors -std=c++11 stat_gen.cpp

main.o: main.cpp main.h
	g++ -c -pedantic-errors -std=c++11 main.cpp

main: main.o combat.o stat_gen.o
	g++ main.o combat.o stat_gen.o -o main
