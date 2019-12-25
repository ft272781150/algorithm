/*

题目描述
题目标题：

将两个整型数组按照升序合并，并且过滤掉重复数组元素[注: 题目更新了。输出之后有换行]输入描述:
输入说明，按下列顺序输入：
1 输入第一个数组的个数
2 输入第一个数组的数值
3 输入第二个数组的个数
4 输入第二个数组的数值

输出描述:
输出合并之后的数组
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Merge(vector<int> vm, vector<int> vn)
{
	sort(vm.begin(), vm.end());
	sort(vn.begin(), vn.end());
	int i = 0, j = 0;
	for (i = 0, j = 0; i < vm.size() && j < vn.size(); )
	{
		if (vm[i] < vn[j])
		{
			cout << vm[i];
			i++;
		}
		else if(vm[i] > vn[j])
		{
			cout << vn[j];
			j++;
		}
		else
		{
			cout << vm[i];
			i++;
			j++;
		}
	}

	while (i < vm.size())
	{
		cout << vm[i];
		i++;
	}

	while (j < vn.size())
	{
		cout << vn[j];
		j++;
	}

	cout << endl;
}


int main()
{
	int m, n;
	while (cin >> m)
	{
		vector<int> vm(m);
		for (int i = 0; i < m; i++)
		{
			cin >> vm[i];
		}
		cin >> n;
		vector<int> vn(n);
		for (int i = 0; i < n; i++)
		{
			cin >> vn[i];
		}

		Merge(vm, vn);
	}
	return 0;
}



