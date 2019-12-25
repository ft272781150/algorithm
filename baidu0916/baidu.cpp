/*

4
2
2 3
1 1 3
7 7 1 20
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> res;


int dfs(vector<vector<int>> vv, int i, int j)
{
	if (i == vv.size() - 1)
	{
		return vv[i][j];
	}
	int tmp1 = 0, tmp2 = 0;
	tmp1 = vv[i][j] + dfs(vv, i + 1, j);
	tmp2 = vv[i][j] + dfs(vv, i + 1, j + 1);
	return max(tmp1, tmp2);



}


void print(vector<vector<int>> vv, int rel, int i, int j)
{
	if (i >= vv.size())
	{
		return;
	}
	res.push(vv[i][j]);
	rel -= vv[i][j];
	if (rel == 0 && vv.size() - 1 == i)
	{
		while (!res.empty())
		{
			cout << res.top() << " ";
			res.pop();
		}
		cout << endl;
		return;
	}
	else
	{
		print(vv, rel, i + 1, j);
		print(vv, rel, i + 1, j + 1);
		if(!res.empty())
			res.pop();
		
	}

}




void func(vector<vector<int>> vv)
{
	int sum = 0;
	sum = dfs(vv, 0, 0);
	print(vv, sum, 0, 0);
	cout << sum << endl;
}


int main()
{
	int n;
	while (cin >> n)
	{
		vector<vector<int>> vv(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cin >> vv[i][j];
			}
		}
		func(vv);
		
	}
	return 0;
}



