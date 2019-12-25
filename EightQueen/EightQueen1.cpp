/*

*/

#include <iostream>
#include <vector>
#include <math.h>
#include "time.h"  

using namespace std;


#define n 12

int sum = 0;

bool isOK(vector<int> &c, int row)
{
	for (int i = 0; i < row; i++)
	{
		if (c[row] == c[i] || (row - i) == abs(c[row] - c[i]))
		{
			return false;
		}
	}
	return true;
}

void eightQueen(int row, vector<int> &c)
{
	if (row == n)
	{
		sum++;
		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			c[row] = i;
			if (isOK(c, row))
			{
				eightQueen(row + 1, c);
			}
		}
	}
}

//int main()
//{
//	vector<int> c(n, 0);
//	time_t tm;
//	tm = time(0);
//	eightQueen(0, c);
//	
//	cout << sum << " " << (int)(time(0) - tm) << endl;
//
//
//}