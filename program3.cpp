//this file runs the third case of programming assignment 1 (top down with memmoization)
//this file contains the main function that starts excution and a recursive function, LCS, that does the real work of calculating the length of the LCS

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

const int largeNum = 100; //used to pass the table to functions

//calculates the length of the LCS using a top down recursive approach with memoization
//X is one of the input strings and Y is the other
//0<p<length of X -> -1 triggers base case
//0<q<length of Y -> -1 triggers base case
//table is the matrix which stores the previous LCS data that has been calculated
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

//main function that controls timing, input/output, and starts the recursive function
//argv holds the names of the input/output files in spots 1-3
int main(int argc, char *argv[])
{
	//the time when the program begins
	auto start = high_resolution_clock::now();

	ifstream fileX(argv[1]);
	ifstream fileY(argv[2]);

	//X is the string in fileX, Y is the string in fileY
	string X, Y;
	fileX >> X;
	fileY >> Y;

	//p is the length of the X string
	int p = X.size();
	//q is the length of the Y string
	int q = Y.size();

	//the matrix that is used to store values of the LCS for each point as to avoid unecessary recursion
	int table[p][largeNum];
	memset(table, -1, sizeof(table));

	//the output file being written to
	ofstream outFile;
	outFile.open(argv[3]);

	outFile << LCS(X, Y, p-1, q-1, table) << endl;

	//the time when the program stops running
	auto stop = high_resolution_clock::now();
	//the difference in time between when it started running and stopped running
	auto duration = duration_cast<microseconds>(stop - start);
	outFile << duration.count() << " microseconds" << endl;

	outFile.close();

	return 0;
}
