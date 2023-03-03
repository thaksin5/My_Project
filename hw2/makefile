.PHONY: directories clean stat

all: directories bin/ut_all

bin/ut_all: test/ut_main.cpp
	g++ test/ut_main.cpp -o bin/ut_all -lgtest -pthread

directories:	
	mkdir bin

clean:
	rm -rf bin

valgrind:
	valgrind --leak-check=full --error-exitcode=2 --track-origins=yes bin/ut_all

stat:
	wc src/* test/*