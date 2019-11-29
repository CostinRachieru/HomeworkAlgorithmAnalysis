#include <iostream>

int levenshteinDistance(std::string str1,std::string str2)
{
	int m = str1.length();
	int n = str2.length();

	// Sterge primele elemente la fel din cele doua stringuri.
	while (str1[0] == str2[0]) {
		m--;
		n--;
		str1.erase(str1.begin());
		str2.erase(str2.begin());
	}
	// Sterge ultimele elemente la fel din cele doua stringuri.
	while (str1[m-1] == str2[n-1]) {
		m--;
		n--;
		str1.erase(str1.end()-1);
		str2.erase(str2.end()-1);		
	}

	int distance[m + 1][n + 1] = { 0 };
	for (int j = 1; j <= n; ++j) {
		distance[0][j] = j;
	}
	for (int i = 1; i <= m; ++i) {
		distance[i][0] = i;
	}
	int cost;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (str1[i - 1] == str2[j - 1]) {
				cost = 0;				
			} else {
				cost = 1;
			}

			distance[i][j] = std::min(std::min(distance[i - 1][j] + 1,
				distance[i][j - 1] + 1),
				distance[i - 1][j - 1] + cost);
		}
	}

	return distance[m][n];
}

int LCSDistance(std::string str2,std::string str1)
{
	int m = str1.length();
	int n = str2.length();

	int toAdd = 0;
	// Sterge primele elemente la fel din cele doua stringuri.
	while (str1[0] == str2[0]) {
		toAdd++;
		m--;
		n--;
		str1.erase(str1.begin());
		str2.erase(str2.begin());
	}
	// Sterge ultimele elemente la fel din cele doua stringuri.
	while (str1[m-1] == str2[n-1]) {
		toAdd++;
		m--;
		n--;
		str1.erase(str1.end()-1);
		str2.erase(str2.end()-1);		
	}

	int distance[m + 1][n + 1] = { 0 };
	for (int j = 1; j <= n; ++j) {
		distance[0][j] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		distance[i][0] = 0;
	}

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (str1[i-1] == str2[j-1]) {
				distance[i][j] = distance[i-1][j-1] + 1;
			} else {
				distance[i][j] = std::max(distance[i][j-1] , distance[i-1][j]);
			}
		}
	}

	// for (int i = 0; i <= m; ++i) {
	// 	for (int j = 1; j <= n; ++j) {
	// 		if (i == 0 || j == 0) {
	// 			distance[i][j] = 0;
	// 		} else {
	// 			if (str1[i - 1] == str2[j - 1]) {
	// 				distance[i][j] = distance[i-1][j-1] + 1;
	// 			} else {
	// 				distance[i][j] = std::max(distance[i-1][j], distance[i][j-1]);
	// 			}
	// 		}
	// 	}
	// }
	int lcs = distance[m][n];
	// return m - lcs + n - lcs;
	return toAdd + lcs;
}