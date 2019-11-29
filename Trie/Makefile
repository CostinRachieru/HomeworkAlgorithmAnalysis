CC = g++
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

build: trie_test.o

trie_test.o: trie_test.cpp
	g++ trie_test.cpp -o test $(CFLAGS)

.PHONY: clean
clean:
	rm -rf *.o test
