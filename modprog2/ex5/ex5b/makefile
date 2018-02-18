main: main.o point.o rectangle.o circle.o gen.o bst.o
	g++ main.o point.o rectangle.o circle.o gen.o bst.o -o ex5b
	echo "A new ex5a was created"
main.o: main.cc point.h rectangle.h circle.h gen.h bst.h
	g++ -Wall -c main.cc 
point.o: point.cc point.h
	g++ -Wall -c point.cc
rectangle.o: rectangle.cc rectangle.h point.h
	g++ -Wall -c rectangle.cc
circle.o: circle.cc circle.h
	g++ -Wall -c circle.cc
gen.o: gen.cc gen.h bst.h
	g++ -Wall -c gen.cc
bst.o: bst.h bst.cc
	g++ -Wall -c bst.cc
