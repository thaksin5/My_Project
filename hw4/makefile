SRC=directories 
EXE=bin/ut_all
COVR=-lgtest -pthread --coverage -fkeep-inline-functions -fno-inline -fno-inline-small-functions -fno-default-inline -g -O0
CLEAR= bin *.gcov *.gcda *.gcno *.html *.css
LEAKCHECK=--leak-check=full --error-exitcode=2 --track-origins=yes
all: $(SRC) $(EXE)

$(EXE): test/ut_main.cpp
	g++ test/ut_main.cpp -o $(EXE) $(COVR)

directories:
	mkdir -p bin

clean:
	rm -rf $(CLEAR)

valgrind:
	valgrind $(LEAKCHECK) $(EXE)

stat:
	wc src/* test/*