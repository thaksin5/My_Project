all:
	g++ -std=c++11 newGameSetting.cpp -o ./gameSetting -pthread

clean:
	rm -rf bin

valgrind:
	valgrind --leak-check=full --error-exitcode=2 --track-origins=yes ./gameSetting
