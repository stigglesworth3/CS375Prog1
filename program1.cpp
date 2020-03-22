#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

struct boxy
{
	int len;
	string dir;
};
typedef struct boxy box;


int main(int argc, char *argv[])
{
	time_t start, end;
	time(&start);
	ios_base::sync_with_stdio(false);

	ifstream fileX(argv[1]);
	ifstream fileY(argv[2]);

	string X, Y;
	fileX >> X;
	fileY >> Y;
	
	int p = X.size();
	int q = Y.size();

	box table[p+1][q+1];
	box set0;
	set0.len = 0;
	set0.dir = "@";

	for (int i=0; i<p+1; i++)
	{
		table[i][0] = set0;
	}
	for (int j=1; j<q+1; j++)
	{
		table[0][j] = set0;
	}
	
	for (int r=1; r<p+1; r++)
	{
		for (int c=1; c<q+1; c++)
		{
			box added;
			if (X.at(r-1) == Y.at(c-1))
			{
				added.len = table[r-1][c-1].len + 1;
				added.dir = "D";
				table[r][c] = added;
			}
			else
			{
				if (table[r-1][c].len > table[r][c-1].len)
				{
					added.len = table[r-1][c].len;
					added.dir = "U";
					table[r][c] = added;
				}
				else
				{
					added.len = table[r][c-1].len;
					added.dir = "L";
					table[r][c] = added;
				}
			}
		}
	}
	

	ofstream outFile;
	outFile.open(argv[3]);

	if (p <= 10 || q <= 10)
	{
		for (int a=0; a<p+1; a++)
		{
			for (int b=0; b<q+1; b++)
			{	
				outFile << table[a][b].len << ", " << table[a][b].dir << "  ";
			}
			outFile << endl;
		}
		string answer;
		while (p != 0 && q != 0)
		{
			if (table[p][q].dir == "D")
			{
				string convert;
				convert += X.at(p-1);
				answer.insert(0, convert);
				p--;
				q--;
			}
			else if (table[p][q].dir == "U")
			{
				p--;
			}
			else
			{
				q--;
			}
		}
		outFile << answer << endl;
	}
	else
	{
		outFile << table[p][q].len << endl;
	}
	time(&end);
	double timeTaken = double(end-start);
	outFile << fixed << timeTaken << " seconds" << endl;
	
	return 0;
}
