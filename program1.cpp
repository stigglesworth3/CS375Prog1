#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct boxy
{
	int len;
	string dir;
};
typedef struct boxy box;


int main(int argc, char *argv[])
{
	ifstream fileX(argv[1]);
	ifstream fileY(argv[2]);

	string X, Y;
	fileX >> X;
	fileY >> Y;
	
	box table[X.size()][Y.size()];
	box setX, setY;
	setX.len = 0;
	setX.dir = "NA";
	setY.len = 0;
	setY.dir = "NA";

	for (int i=0; i<X.size(); i++)
	{
		table[i][0] = setX;
	}
	for (int j=1; j<Y.size(); j++)
	{
		table[0][j] = setY;
	}
	
	for (int r=1; r<X.size(); r++)
	{
		for (int c=1; c<Y.size(); c++)
		{
			box added;
			if (X.at(r-1) == Y.at(c-1))
			{
				added.len = table[r-1][c-1] + 1;
				added.dir = "D";
				table[r][c] = added;
			}
			else
			{
				if (table[r-1][c] > table[r][c-1])
				{
					added.len = table[r-1][c];
					added.dir = "U";
					table[r][c] = added;
				}
				else
				{
					added.len = table[r][c-1];
					added.dir = "L";
					table[r][c] = added;
				}
			}
		}
	}
	//backtrack from here

	ofstream outFile;
	outFile.open(argv[3]);

	outFile << X << ", " << Y << endl;
	
	return 0;
}
