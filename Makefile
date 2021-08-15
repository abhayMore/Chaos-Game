all: sfml-app
	./sfml-app

sfml-app: main.o
	g++ -std=c++17 -o sfml-app main.o  -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

main.o : main.cpp
	g++ -std=c++17 -c main.cpp

clean:
	rm -rf *o sfml-app
