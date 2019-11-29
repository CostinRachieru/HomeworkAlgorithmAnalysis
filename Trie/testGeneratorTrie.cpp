#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include <fstream>

int main(int argc, char *argv[]) {

	std::ofstream TestFile;
	std::string in = "./in/";
	in += argv[1];
	in += ".in";
	TestFile.open(in);

	std::tring out = "./out/";
	out += argv[1];
	out += ".out";
	std::ofstream RefFile;
	RefFile.open(out);

	if (argc != 2) {
		std::cout << "Nu este specificat numele testului.\n";
		return 0;
	}

	std::cout << "Numar de stringuri: ";
	int nr;
	std::cin >> nr;

	std::cout << "Numarul minim de caractere dintr-un string: ";
	int min;
	std::cin >> min;

	std::cout << "Numarul maxim de caractere dintr-un string: ";
	int max;
	std::cin >> max;

	std::vector<std::string> *array = new std::vector<std::string>();
	static const std::string alphabet = {"abcdefghijklmnopqrstuvwxyz"};
	std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> range_alphabet(0,25);
    std::uniform_int_distribution<std::mt19937::result_type> range(min,max);
	
	// Scrie in fisierul de in cate stringuri vor fi de inserat si de gasit.
    TestFile << nr << "\n";
	for (int i = 0; i < nr; ++i) {
		std::string str;
		// Construieste stringul random.
		unsigned int nr_char = range(rng);
		for (unsigned int j = 0; j < nr_char; ++j) {
			str += alphabet[range_alphabet(rng)];
		}
		// Scrie in fisierul de in si out.
		TestFile << str << "\n";
		array->push_back(str);
	}
	// Scrie in fisierul de in ce cuvinte sa caute si in cel de out ca
	// sunt gasite
	for (int i = nr - 1; i >= 0; --i) {
		RefFile << array->at(i) << "a fost gasit.\n";
		TestFile << array->at(i) << "\n";
	}

	TestFile.close();
	RefFile.close();
	delete array;
	return 0;
}