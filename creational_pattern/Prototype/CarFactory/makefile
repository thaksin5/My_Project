all:
	g++ main.cpp -o a.out

clean:
	rm ./a.out

valgrind:
	valgrind --leak-check=full --error-exitcode=2 --track-origins=yes ./a.out