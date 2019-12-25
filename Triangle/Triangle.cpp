/*
			1

		 1  1  1

	  1  2  3  2  1

   1  3  6  7  6  3  1

1  4  10 16 19  16 10  4  1

���������ε����󣬵�һ��ֻ��һ����1������ÿ�е�ÿ��������ǡ������������������Ͻ��������Ͻǵ�����3����֮�ͣ����������ĳ��������Ϊ��������0����

���n�е�һ��ż�����ֵ�λ�á����û��ż���������-1����������3,�����2������4�����3��



����n(n <= 1000000000)

*/
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

int triangle(int n)
{
	if (n < 3)
		return -1;
	if (n % 2 != 0)
		return 2;
	vector<vector<int>> linklist;
	vector<int> v1, v2;
	v1.push_back(1);
	v2.push_back(1);
	v2.push_back(1);
	v2.push_back(1);
	linklist.push_back(v1);
	linklist.push_back(v2);
	for (int i = 2; i < n; i++)
	{
		int amount = 2 * (i + 1) - 1;
		vector<int> vi(amount);
		vi[0] = 1;
		vi[1] = linklist[i - 1][0] + linklist[i - 1][1];
		for (int j = 2; j < amount - 2; j++)
		{
			vi[j] = linklist[i - 1][j - 2] + linklist[i - 1][j - 1] + linklist[i - 1][j];

		}
		vi[amount - 2] = linklist[i - 1][amount - 4] + linklist[i - 1][amount - 3];
		vi[amount - 1] = linklist[i - 1][amount - 3];

		linklist.push_back(vi);
	}


	
	for (int i = 0; i < 2 * n - 1; i++)
	{
		if (linklist[n - 1][i] % 2 == 0)
			return i + 1;
	}
	return -1;

}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << triangle(n) << endl;
	}

	return 0;
}
