/*

��Ŀ����
��Ŀ���⣺

�������������鰴������ϲ������ҹ��˵��ظ�����Ԫ��[ע: ��Ŀ�����ˡ����֮���л���]��������:
����˵����������˳�����룺
1 �����һ������ĸ���
2 �����һ���������ֵ
3 ����ڶ�������ĸ���
4 ����ڶ����������ֵ

�������:
����ϲ�֮�������
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



