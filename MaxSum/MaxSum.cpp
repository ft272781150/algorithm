/*
在一个N*N的数组中寻找所有横，竖，左上到右下，右上到左下，四种方向的直线连续D个数字的和里面最大的值
输入描述:
每个测试输入包含1个测试用例，第一行包括两个整数 N 和 D :
3 <= N <= 100
1 <= D <= N
接下来有N行，每行N个数字d:
0 <= d <= 100
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



void MaxSum(vector<vector<int>> vv, int n, int d)
{
	int Amax = 0, Bmax = 0, Cmax = 0, Dmax = 0;
	
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		int k = 0;
		for (int j = 0; j < n; )
		{
			
			if (k < d)
			{	
				sum += vv[i][j];
				k++;
				j++;
			}
			else
			{
				if (Amax < sum)
				{
					Amax = sum;
				}
				k -= 1;
				sum -= vv[i][j - d];
			}
			
		}
	}

	for (int j = 0; j < n; j++)
	{
		int sum = 0;
		int k = 0;
		for (int i = 0; i < n; )
		{

			if (k < d)
			{
				sum += vv[i][j];
				k++;
				i++;
			}
			else
			{
				if (Bmax < sum)
				{
					Bmax = sum;
				}
				k -= 1;
				sum -= vv[i - d][j];
			}

		}
	}

	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		int k = 0;
		for (int j = 0; j <= i; )
		{
			if (k < d)
			{
				sum += vv[i][j];
				k++;
				i++;
			}
			else
			{
				if (Cmax < sum)
				{
					Cmax = sum;
				}
				k -= 1;
				sum -= vv[i + d][j - d];
			}

		}
	}

	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		int k = 0;
		for (int j = 0; j <= i; )
		{
			if (k < d)
			{
				sum += vv[i][j];
				k++;
				i++;
			}
			else
			{
				if (Cmax < sum)
				{
					Cmax = sum;
				}
				k -= 1;
				sum -= vv[i + d][j - d];
			}

		}
	}





	cout << max(max(max(Amax, Bmax), Cmax), Dmax) << endl;
	

}

int main()
{
	int n, d;
	while (cin >> n >> d)
	{
		vector<vector<int>> vv(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> vv[i][j];
			}
		}

		MaxSum(vv, n, d);
	}
	return 0;
}


