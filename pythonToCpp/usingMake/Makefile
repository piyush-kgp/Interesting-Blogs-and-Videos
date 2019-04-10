
output: abc.o def.o
	g++ abc.cpp def.cpp -o output

abc.o: abc.cpp
	g++ -c abc.cpp

def.o: def.cpp def.h
	g++ -c def.cpp

clean:
	rm *.o output
