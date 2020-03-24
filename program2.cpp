//this file run the second case of programming assignment 1 (top down without memoization)
//this file contains the main funciton that starts the excution and a recursive funciton called LCS that does the real work of calculating the length of the LCS

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

//calculates the length of the longest substring using a top down recusive approach 
//X is one input string and Y is the other
//0 < p < length of X -> -1 triggers base case
//0 < q < length of Y -> -1 triggers base case
int LCS(string X, string Y, int p, int q)
{
	if (p < 0 || q < 0)
	{
		return 0;
	}
	if (X.at(p) == Y.at(q))
	{
		return LCS(X, Y, p-1, q-1) + 1;
	}
	else
	{
		return max(LCS(X, Y, p-1, q), LCS(X, Y, p, q-1));
	}
}

//main function that controls input/output as well as starts the recursive function and times the total running time
//argv holds the name of the input/output files in spots 1-3
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

	//the output file to be written to
	ofstream outFile;
	outFile.open(argv[3]);

	outFile << LCS(X, Y, p-1, q-1) << endl;

	//the time when the program stops running
	auto stop = high_resolution_clock::now();
	//the differnce in time between when the program started and ended running
	auto duration = duration_cast<microseconds>(stop-start);
	outFile << duration.count() << " microseconds" << endl;

	outFile.close();

	return 0;
}
