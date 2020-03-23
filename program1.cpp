//this class runs the first case of programming assingment 1 (bottom up dynamic programming approach)
//this class contains a main function and a struct called "boxy"


#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct boxy //one spot in the matrix so both the length of the common substring and arrow direction can be stored together
{
	int len; //length of longest common substring so far
	string dir; //direction for arrow 
};
typedef struct boxy box;

//main funciton that does all the work
//argv holds the name of the files that will act as input and output files
//funciton starts by starting the timer and reading in the two strings to comapre
//then it creates the matrix and fills it in row by row according to the previous substring length to fill in the length and arrow direction
//then it works from the bottom rightmost location in the matrix based on the arrow direction to work finding the LCS and length of the substring until it reaches either row 0 or col 0
int main(int argc, char *argv[])
{
	//the time that the program starts running
	auto start = high_resolution_clock::now();

	ifstream fileX(argv[1]);
	ifstream fileY(argv[2]);

	string X, Y; //X is the x substring, Y is the y substring
	fileX >> X;
	fileY >> Y;
	
	int p = X.size(); //length of substring X
	int q = Y.size(); //length of substring Y

	box table[p+1][q+1]; //matrix where work is done
	box set0; //defult to intailize row 0 and col 0 
	set0.len = 0;
	set0.dir = "I";

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
			box added; //struct for the matrix location that is being calulated 
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
	

	ofstream outFile; //output file
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
		string answer; //LCS result
		while (p != 0 && q != 0)
		{
			if (table[p][q].dir == "D")
			{
				string convert; //the char of the strings that is to be added to the front of the LCS
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

	//the time that the program stops running
	auto stop = high_resolution_clock::now();
	//the difference between the starting time and ending time in microseconds
	auto duration = duration_cast<microseconds>(stop-start);
	outFile << duration.count() << " microseconds" << endl;
	
	outFile.close();

	return 0;
}
