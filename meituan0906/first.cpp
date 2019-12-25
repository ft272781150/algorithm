/*

*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


void func(vector<int> vi, int n, int k, int t)
{
	if (n < k - 1 && t > 1)
	{
		cout << "0" << endl;
		return;
	}
	int begin, end;
	int sum = 0;
	map<int, int> mp;
	for (begin = 0, end = begin + k - 1; end < n; begin++, end++)
	{		
		mp.clear();
		map<int, int>::iterator it;
		for (int j = begin; j <= end; j++)
		{
			mp[vi[j]]++;
			if (mp[vi[j]] == t)
			{
				sum++;
				break;
			}
		}


		//for (it = mp.begin(); it != mp.end(); it++)
		//{
		//	if (it->second == t)
		//	{
		//		sum++;
		//		break;
		//	}
		//}
	}

	cout << sum << endl;
}

int main()
{
	int n, k, t;
	while (cin >> n >> k >> t)
	{
		vector<int> vi(n);
		for (int i = 0; i < n; i++)
		{
			cin >> vi[i];
		}

		func(vi, n, k, t);
	}
	return 0;
}



