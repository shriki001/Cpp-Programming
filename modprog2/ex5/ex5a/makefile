main: main.o points.o rectangle.o util.o compare.o
	g++ main.o points.o rectangle.o util.o compare.o -o ex5a
	echo "A new ex5a was created"
main.o: main.cc points.h rectangle.h util.h compare.h
	g++ -Wall -c main.cc 
points.o: points.cc points.h
	g++ -Wall -c points.cc
rectangle.o: rectangle.cc rectangle.h points.h
	g++ -Wall -c rectangle.cc
util.o: rectangle.h util.cc util.h compare.h
	g++ -Wall -c util.cc
compare.o: rectangle.h compare.h compare.cc
	g++ -Wall -c compare.cc
