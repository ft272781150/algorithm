/*

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void func(vector<int> vi)
{
	int n = vi.size();
	if (n == 0)
		return;
	vector<int> tmp(n);
	tmp[1] = vi[1];
	int len = 1;
	for (int i = 2; i <= n; i++)
	{
		if (vi[i] >= tmp[len]) tmp[++len] = vi[i];
		else
		{
			int j = upper_bound(tmp.begin() + 1, tmp.begin() + len + 1, vi[i]) - tmp.begin();
			tmp[j] = vi[i];
		}
	}
	cout << len << endl;
}


int main()
{

	int n, m;
	while (cin >> n >> m)
	{
		vector<int> vi(n * m + 1);
		for (int i = 1; i <= n; i++)
		{
			cin >> vi[i];
		}
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				vi[n*i + j] = vi[j];
			}
		}

		func(vi);
	}
	return 0;
}







