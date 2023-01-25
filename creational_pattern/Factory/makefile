all : directories bin/main

directories:
	mkdir -p bin

bin/main: main.cpp
	g++ main.cpp -o bin/main

clean:
	rm -rf bin

valgrind:
	valgrind --leak-check=full --error-exitcode=2 --track-origins=yes ./bin/main