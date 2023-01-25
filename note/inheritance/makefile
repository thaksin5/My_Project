# create file : cat > filename
main: main.o teacher.o user.o
	g++ main.o teacher.o user.o -o main

main.o: main.cpp
	g++ -c main.cpp

teacher.o: teacher/teacher.cpp
	g++ -c teacher/teacher.cpp

user.o: user/user.cpp
	g++ -c user/user.cpp

clean:
	rm *.o main