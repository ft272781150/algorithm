/*

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct val
{
	long a;
	long b;
	long c;
};

bool compare(const val &m, const val &n)
{
	if (m.a < n.a) 
		return true;
	else if (m.a == n.a && m.b < n.b) 
		return true;
	else if (m.a == n.a && m.b == n.b && m.c <= n.c) 
		return true;
	else 
		return false;
}


void func(vector<val> &vv)
{
	int len = vv.size();
	int sum = 0;
	if (len < 2)
	{
		cout << "0" << endl;
		return;
	}

	sort(vv.begin(), vv.end(), compare);

	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (vv[j].a > vv[i].a && vv[j].b > vv[i].b && vv[j].c > vv[i].c)
			{
				sum++;
				break;
			}
		}
	}
	cout << sum << endl;
}

//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<val> vv(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> vv[i].a >> vv[i].b >> vv[i].c;
//		}
//
//		func(vv);
//	}
//
//	return 0;
//}



