combat.o: combat.cpp main.h
  g++ -c -pedantic-errors -std=c++11 combat.cpp

stat_gen.o: stat_gen.cpp main.h
	g++ -c -pedantic-errors -std=c++11 stat_gen.cpp

main.o: main.cpp main.h
	g++ -c -pedantic-errors -std=c++11 main.cpp
	
save_load.o: save_load.cpp main.h
	g++ -c -pedantic-errors -std=c++11 save_load.cpp

main: main.o combat.o stat_gen.o
	g++ main.o combat.o stat_gen.o save_load.o -o main
