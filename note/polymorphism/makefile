main: main.o teacher.o user.o
	g++ main.o user.o teacher.o -o main

# -c mean execute
main.o: main.cpp
	g++ -c main.cpp

teacher.o: teacher/teacher.cpp
	g++ -c teacher/teacher.cpp

user.o: user/user.cpp
	g++ -c user/user.cpp

clean:
	rm *.o main
