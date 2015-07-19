name = bitshifting

all: bin
	g++ -std=c++11 $(name).cpp -o bin/$(name)

bin:
	mkdir bin

clang: bin
	clang++ -std=c++11 $(name).cpp -o bin/$(name)

run:
	./bin/$(name)

clean:
	rm bin/*
