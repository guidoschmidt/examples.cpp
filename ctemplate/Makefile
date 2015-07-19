name = ctemplate
libs = ctemplate

all: bin
	g++ -std=c++11 $(name).cpp -l$(libs) -o bin/$(name)

bin:
	mkdir bin

clang: bin
	clang++ -std=c++11 $(name).cpp -l$(libs) -o bin/$(name)

run:
	./bin/$(name)

clean:
	rm bin/*
	rm -r bin/
