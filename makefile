postfix: postfix.o
	g++ postfix.o -o postfix

postfix.o: postfix.cpp linkedstack.h node.h
	g++ -c -std=c++11 postfix.cpp

clean:
	rm *.o postfix