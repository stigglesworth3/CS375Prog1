#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[])
{
	auto start = high_resolution_clock::now();

	ifstream fileX(argv[1]);
	ifstream fileY(argv[2]);

	string X, Y;
	fileX >> X;
	fileY >> Y;

	ofstream outFile;
	outFile.open(argv[3]);

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop-start);
	outFile << duration.count() << " microseconds" << endl;

	outFile.close();

	return 0;
}
