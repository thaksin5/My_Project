.PHONY: directories clean stat

all: directories bin/gameSetting

bin/gameSetting: gameSetting.cpp
	g++ -std=c++11 gameSetting.cpp -o bin/gameSetting -pthread

directories:
	mkdir -p bin

clean:
	rm -rf bin

valgrind:
	valgrind --leak-check=full --error-exitcode=2 --track-origins=yes ./bin/gameSetting

stat:
	wc src/* test/*	
