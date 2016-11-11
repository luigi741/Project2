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
	cout << "Hello World!" << endl;

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
	output.close();

	inputFile >> cases;

	for (int i = 0; i < cases; i++)
	{
		int n;
		int k;
		int t;
		int j = 0;

		int array[n];

		while (j < n)
		{
			inputFile >> array[j++];
		}

		cout << "\nInput Array: ";
		for (int i = 0; i < n; i++)
		{
			cout << " " << array[i] << " ";
		}
		cout << endl;
	}
	inputFile.close();

	int refString[] = {5, 2, 3, 4, 10};
	int count = 0;



	stack<int> stack1;

	// Constant t value
	static const int T = 10;

	// Size of our original array/string
	static const int arraySize = sizeof(refString) / 4;

	for (int i = 0; i < 5; i++)
	{
		cout << refString[i] << endl;
	}
	cout << count << endl;
	cout << T << endl;
	cout << arraySize << endl;

	int dp[arraySize][arraySize];

	// Populate map with INT_MAX
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			dp[i][j] = INT_MAX;
		}
	}

	cout << endl;

	for (int i = 0; i < arraySize; i++)
	{
		int sum = 0;

		for (int j = i; j < arraySize; j++)
		{
			// Sum up all values in row j
			sum += refString[j];

			if (sum <= T)
			{
				int minimum = INT_MAX;
				if (i != 0)
				{
					for (int x = 0; x < arraySize; x++)
					{
						if (minimum > dp[x][i-1])
						{
							cout << "dp[" << x << "]" << "[" << j << "]" << dp[x][j] << endl;
							minimum = dp[x][i-1];
						}
					}
				}
				else
				{
					minimum = 0;
				}
				dp[i][j] = pow(T-sum, 2) + minimum;
			}
			else
			{
				dp[i][j] -= 1;
			}
		}
	}

	cout << endl;

	int trueMin = INT_MAX;

	for (int i = 0; i < arraySize; i++)
	{
		if (trueMin > dp[i][arraySize-1])
		{
			trueMin = dp[i][arraySize-1];
			cout << "trueMin = " << trueMin << endl;
		}
	}

	cout << "\nFinal Print of Map" << endl;

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			cout << "dp[" << i << "]" << "[" << j << "] = " << dp[i][j] << endl;
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
	cout << "stackCount = " << stackCount << endl;
	while (!stack1.empty())
	{
		cout << stack1.top() << endl;
		stack1.pop();
	}

	return 0;
}