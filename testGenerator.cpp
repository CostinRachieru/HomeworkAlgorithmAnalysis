#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include <fstream>
#include "algo.h"


int main(int argc, char *argv[]) {

	std::ofstream TestFile;
	std::string in = "./in/";
	in += argv[1];
	TestFile.open(in);

	std::string out = "./out/";
	out += argv[2];
	std::ofstream RefFile;
	RefFile.open(out);

	if (argc != 3) {
		std::cout << "Nu sunt specificate ambele fisiere pentru teste.\n";
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

	static const std::string alphabet = {"abcdefghijklmnopqrstuvwxyz"};
	std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> range_alphabet(0,25);
    std::uniform_int_distribution<std::mt19937::result_type> range(min,max);
	
	// Scrie in fisierul de in cate stringuri vor fi de inserat si de gasit.
 //    string str;
	for (int i = 0; i < nr; ++i) {
		std::string str;
		// Construieste stringul random.
		unsigned int nr_char = range(rng);
		for (unsigned int j = 0; j < nr_char; ++j) {
			str += alphabet[range_alphabet(rng)];
		}
		// Scrie in fisierul de in si out.
		TestFile << str << "\n";
		if (i == 0) {
			TestFile << nr << "\n";
			nr++;
		}
	}

	TestFile.close();
    std::ifstream InFile;
    InFile.open(in);

    std::string myString;
	InFile >> myString;
	int n;
	InFile >> n;
	
	std::vector<std::string> *lev_array = new std::vector<std::string>();
	std::vector<std::string> *lcs_array = new std::vector<std::string>();
	int minLevDist = 100;
	int maxLCSDist = 0;
	for (int i = 0; i < n; ++i) {
		std::string str;
		InFile >> str;
		int levDist = levenshteinDistance(myString, str);
		int LCSDist = LCSDistance(myString, str);
		if (levDist < minLevDist) {
			lev_array->clear();
			lev_array->push_back(str);
			minLevDist = levDist;
		} else {
			if (levDist == minLevDist) {
				lev_array->push_back(str);
			}
		}
		if (LCSDist > maxLCSDist) {
			lcs_array->clear();
			lcs_array->push_back(str);
			maxLCSDist = LCSDist;
		} else {
			if (LCSDist == maxLCSDist) {
				lcs_array->push_back(str);
			}
		}
	}

	RefFile << "Distanta minima Levenshtein este: " << minLevDist << "\n";
	for (unsigned int i = 0; i < lev_array->size(); ++i) {
		RefFile << lev_array->at(i) << "\n";
	}
	RefFile << "Cea mai lunga subsecventa: " << maxLCSDist << "\n";
	for (unsigned int i = 0; i < lcs_array->size(); ++i) {
		RefFile << lcs_array->at(i) << "\n";
	}
	delete lev_array;
	delete lcs_array;

	InFile.close();
	RefFile.close();
	return 0;
}