#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
