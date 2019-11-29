#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

	ofstream TestFile;
	string in = "./in/";
	in += argv[1];
	TestFile.open(in);

	string out = "./out/";
	out += argv[2];
	ofstream RefFile;
	RefFile.open(out);

	if (argc != 3) {
		cout << "Nu sunt specificate ambele fisiere pentru teste.\n";
		return 0;
	}

	cout << "Numar de stringuri: ";
	int nr;
	cin >> nr;

	cout << "Numarul minim de caractere dintr-un string: ";
	int min;
	cin >> min;

	cout << "Numarul maxim de caractere dintr-un string: ";
	int max;
	cin >> max;

	vector<string> *array = new vector<string>();
	static const string alphabet = {"abcdefghijklmnopqrstuvwxyz"};
	random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> range_alphabet(0,25);
    uniform_int_distribution<mt19937::result_type> range(min,max);
	
	// Scrie in fisierul de in cate stringuri vor fi de inserat si de gasit.
    TestFile << nr << "\n";
	for (int i = 0; i < nr; ++i) {
		string str;
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