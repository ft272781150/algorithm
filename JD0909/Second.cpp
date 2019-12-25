/*
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;


bool bfs(int s, int n, vector<int> &color, vector<vector<int>> mp) {
	queue<int> q;
	q.push(s);
	color[s] = 1;
	while (!q.empty()) {
		int from = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (mp[from][i] && color[i] == -1) {
				q.push(i);
				color[i] = !color[from];
			}
			if (mp[from][i] && color[from] == color[i])
				return false;
		}
	}
	return true;
}

bool math(vector<vector<int>> mp)
{
	int len = mp.size();
	vector<int> color(len + 1, -1);
	bool flag = false;
	for (int i = 1; i <= len; i++)
	{
		if (color[i] == -1 && !bfs(i, len, color, mp))
		{
			flag = true;
			break;
		}
	}

	if (flag)
		return false;
	else
		return true;

}

void func(vector<vector<vector<int>>> vms)
{
	int len = vms.size();
	for (int i = 0; i < len; i++)
	{
		if (math(vms[i]))
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}
	
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<vector<vector<int>>> vms(n);
		for (int i = 0; i < n; i++)
		{
			int k, m;
			cin >> k >> m;
			vector<vector<int>> hs(k + 1, vector<int>(k + 1, 0));
			for (int j = 0; j < m; j++)
			{
				int outp, inp;
				cin >> outp >> inp;
				hs[outp][inp] = 1;
				hs[inp][outp] = 1;
			}
			vms[i] = hs;
		}
		func(vms);

	}

	return 0;
}

