#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

const int largeNum = 1000;

int LCS(string X, string Y, int p, int q, int table[][largeNum])
{
	if (p < 0 || q < 0)
	{
		return 0;
	}
	if (table[p][q] != -1)
	{
		return table[p][q];
	}
	if (X.at(p) == Y.at(q))
	{
		table[p][q] = LCS(X, Y, p-1, q-1, table);
		return table[p][q] + 1;
	}
	else
	{
		table[p][q] = max(LCS(X, Y, p-1, q, table), LCS(X, Y, p, q-1, table));
		return table[p][q];
	}
}

int main(int argc, char *argv[])
{
	auto start = high_resolution_clock::now();

	ifstream fileX(argv[1]);
	ifstream fileY(argv[2]);

	string X, Y;
	fileX >> X;
	fileY >> Y;

	int p = X.size();
	int q = Y.size();

	int table[p][largeNum];
	memset(table, -1, sizeof(table));

	ofstream outFile;
	outFile.open(argv[3]);

	outFile << LCS(X, Y, p-1, q-1, table) << endl;

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	outFile << duration.count() << " microseconds" << endl;

	outFile.close();

	return 0;
}
