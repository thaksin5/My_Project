.PHONY: directories clean stat

all: directories bin/ut_all_gcovr

bin/ut_all_gcovr: test/ut_main.cpp
	g++ test/ut_main.cpp src/drink.cpp -o bin/ut_all_gcovr -lgtest -pthread --coverage -fkeep-inline-functions -fno-inline -fno-inline-small-functions -fno-default-inline -g -O0


directories: 
	mkdir bin

clean:
	rm -rf bin *.gcov *.gcda *.gcno *.html *.css

valgrind:
	valgrind --leak-check=full --error-exitcode=2 --track-origins=yes ./bin/ut_all_gcovr

stat:
	wc src/* test/*