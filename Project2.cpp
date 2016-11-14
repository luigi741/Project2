//==================================================================================================
// Project2.cpp
// This program is used to solve/calculate the Equal Partitioning Problem
// By: Anthony Brancucci, Luis Castro, Brandon Toun
//==================================================================================================

#include <iostream>
#include <fstream>
#include <climits>
#include <math.h>
#include <stack>
using namespace std;

int main(int argc, char* argv[])
{
	// This part of the code will read in from input.txt
	int cases;
	ifstream inputFile;

	inputFile.open(argv[1]);

	if (!inputFile.is_open())
	{
		cout << "Error opening file. Aborting program." << endl;
		return -1;
	}

	ofstream output;
	output.open("output.txt");

	inputFile >> cases;

	for (int y = 0; y < cases; y++)
	{
		int n;
		int t;
		inputFile >> n;
		inputFile >> t;

		//cout << t << endl;

		int j = 0;

		int refString[n];

		while (j < n)
		{
			inputFile >> refString[j++];
		}

		//cout << "Input Array: ";

		/*for (int i = 0; i < n; i++)
		{
			cout << " " << refString[i] << " ";
		}*/

		stack<int> stack1;

		// Constant t value
		int T = t;

		// Size of our original arranty/string
		int arraySize = sizeof(refString)/sizeof(*refString);

		int dp[arraySize][arraySize];
		int min[arraySize];
		
		for(int i = 0; i< arraySize; i++)
		{
			min[i] = INT_MAX;
		}
		// Populate map with INT_MAX
		for (int i = 0; i < arraySize; i++)
		{
			for (int j = 0; j < arraySize; j++)
			{
				dp[i][j] = INT_MAX;
			}
		}

		for (int i = 0; i < arraySize; i++)
		{
			int sum = 0;

			for (int j = i; j < arraySize; j++)
			{
				// Sum up all values in row j
				sum += refString[j];

				if (sum <= T)
				{
					if (i != 0)
					{
						int score = (T-sum)*(T-sum) + min[i-1];
						dp[i][j] = score;
						
						if(min[j] > score)
						{
							min[j] = score;
						}
						
					
					}
					else
					{
						dp[i][j] = (T-sum)*(T-sum);
						if(min[j] > (T-sum)*(T-sum))
						{
							min[j] = (T-sum)*(T-sum);
						}
					}
					
				}
				else
				{
					dp[i][j] -= 1;
				}
			}
		}

		int trueMin = INT_MAX;

		for (int i = 0; i < arraySize; i++)
		{
			if (trueMin > dp[i][arraySize-1])
			{
				trueMin = dp[i][arraySize-1];
				//cout << "trueMin = " << trueMin << endl;
			}
		}

		// This variable holds column being observed
		int column = arraySize - 1;;
		int row = 0;
		int stackCount = 0;
		int stackMin = INT_MAX;

		while (column >= 0)
		{
			stackMin = INT_MAX;
			for (int i = 0; i < arraySize; i++)
			{
				if ((stackMin > dp[i][column]))
				{
					stackMin = dp[i][column];
					row = i;
				}
			}
			stack1.push(column-row+1);
			column = row - 1;
			stackCount++;
		}
		//cout << "stackCount = " << stackCount << endl;
		output << stackCount << " ";
		while (!stack1.empty())
		{
			output << stack1.top() << " ";
			stack1.pop();
		}
		output << endl;
		
		if(y == 0)
	{
		for(int i = 0; i< arraySize; i++)
		{
			cout << min[i] << " ";
		}
	}
	}
	cout << endl;

	inputFile.close();
	output.close();
	
	
	
	return 0;
}
