#include "Trie.h"
#include <string>
#include <iostream>
#include <vector>

int main() {
	Trie *trie = new Trie(ALPHABET_SIZE);
	int nr_strings;
	std::cin >> nr_strings;
	for (int i = 0; i < nr_strings; ++i) {
		std::string str;
		std::cin >> str;
		trie -> insert(str);
	}
	for (int i = 0; i < nr_strings; ++i) {
		std::string str;
		std::cin >> str;
		if (trie -> search(str)) {
			std::cout << str << "a fost gasit.\n";
		}
	}
	delete trie;
	return 0;
}
