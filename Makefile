printout.o:printout.cpp main.h
	g++ -c -pedantic-errors -std=c++11 printout.cpp

combat.o: combat.cpp main.h
	g++ -c -pedantic-errors -std=c++11 combat.cpp

stat_gen.o: stat_gen.cpp main.h
	g++ -c -pedantic-errors -std=c++11 stat_gen.cpp

main.o: main.cpp main.h
	g++ -c -pedantic-errors -std=c++11 main.cpp

main: main.o combat.o stat_gen.o printout.o
	g++ main.o combat.o stat_gen.o printout.o -o main

clean:
	rm -f main main.o stat_gen.o combat.o printout.o stats.txt

.PHONY:
	clean
