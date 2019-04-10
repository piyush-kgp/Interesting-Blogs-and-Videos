
output: student.o main.o
	g++ main.cpp student.cpp -o output

main.o: main.cpp
	g++ -c main.cpp

student.o: student.cpp student.h
	g++ -c student.cpp

clean:
	rm *.o output
