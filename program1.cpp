#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream fileX(argv[1]);
	ifstream fileY(argv[2]);

	string X, Y;
	fileX >> X;
	fileY >> Y;
	
	cout << X << ", " << Y << endl;
	return 0;
}
