CC = g++
LAB_OPTS = -I./src -I/usr/local/include -L/usr/lib src/discipline.cpp
C_OPTS = -g -fsanitize=address $(LAB_OPTS)

clean:
	rm -rf dist 

prep:
	mkdir dist

compile: main.bin

main.bin: src/main.cpp
	$(CC) $(C_OPTS) src/main.cpp -o dist/main.bin

test.bin: test/test.cpp
	$(CC) $(C_OPTS) test/test.cpp -o dist/test.bin -lgtest -lgtest_main -lpthread

run: clean prep compile
	./dist/main.bin

test: clean prep test.bin
	./dist/test.bin
