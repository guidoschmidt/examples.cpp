name = friend
classes = Menu.cpp

all: bin
	g++ -std=c++11 $(name).cpp $(classes)  -o bin/$(name)

bin:
	mkdir bin

clang: bin
	clang++ -std=c++11 $(name).cpp $(classes) -o bin/$(name)

run:
	./bin/$(name)

clean:
	rm bin/*
	rm -r bin/
