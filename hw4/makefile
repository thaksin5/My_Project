.PHONY: directories clean stat

all: directories bin/ut_all

bin/ut_all: test/ut_main.cpp
	g++ test/ut_main.cpp -o bin/ut_all -lgtest -pthread --coverage -fkeep-inline-functions -fno-inline -fno-inline-small-functions -fno-default-inline -g -O0

directories:
	mkdir -p bin

clean:
	rm -rf bin *.gcov *.gcda *.gcno *.html *.css

valgrind:
	valgrind --leak-check=full --error-exitcode=2 --track-origins=yes ./bin/ut_all

stat:
	wc src/* test/*