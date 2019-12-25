/*

*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;



void cal(int n, int k)
{
	int p = 0;
	int res = 0;
	vector<int> val;
	for (int i = 0; k > 0; i++)
	{
		int tmp = pow(n, i);
		val.push_back(tmp);
		if (--k <= 0) break;
		int len = val.size();
		for (int j = 0; j < len - 1; j++)
		{
			val.push_back(tmp + val[j]);
			if (--k <= 0) break;
		}

	}
	cout << val[val.size() - 1] << endl;
}

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		cal(n, k);
	}
	return 0;
}



