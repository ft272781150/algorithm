/*
��һ��N*N��������Ѱ�����кᣬ�������ϵ����£����ϵ����£����ַ����ֱ������D�����ֵĺ���������ֵ
��������:
ÿ�������������1��������������һ�а����������� N �� D :
3 <= N <= 100
1 <= D <= N
��������N�У�ÿ��N������d:
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


