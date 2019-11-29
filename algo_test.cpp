#include <iostream>
#include "algo.h"
#include <vector>

int main()
{
	std::string myString;
	std::cin >> myString;
	int n;
	std::cin >> n;
	
	std::vector<std::string> *lev_array = new std::vector<std::string>();
	std::vector<std::string> *lcs_array = new std::vector<std::string>();
	int minLevDist = 100;
	int maxLCSDist = 0;
	for (int i = 0; i < n; ++i) {
		std::string str;
		std::cin >> str;
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

	std::cout << "Distanta minima Levenshtein este: " << minLevDist << "\n";
	for (unsigned int i = 0; i < lev_array->size(); ++i) {
		std::cout << lev_array->at(i) << "\n";
	}
	std::cout << "Cea mai lunga subsecventa: " << maxLCSDist << "\n";
	for (unsigned int i = 0; i < lcs_array->size(); ++i) {
		std::cout << lcs_array->at(i) << "\n";
	}
	delete lev_array;
	delete lcs_array;
	return 0;
}