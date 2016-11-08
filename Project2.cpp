//==================================================================================================
// Project2.cpp
// This program is used to solve/calculate the Equal Partitioning Problem
// By: Anthony Brancucci, Luis Castro, Brandon Toun
//==================================================================================================

#include <iostream>
#include <fstream>
#include <climits>
#include <math.h>
using namespace std;

int main()
{
	cout << "Hello World!" << endl;

	int refString[] = {5, 2, 3, 4, 10};
	int count = 0;

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
			//cout << "dp[" << i << "]" << "[" << j << "] = " << dp[i][j] << endl;
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

	cout << "\n\nFinal Print of Map" << endl;

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			cout << "dp[" << i << "]" << "[" << j << "] = " << dp[i][j] << endl;
		}
	}

	return 0;
}