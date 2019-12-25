/*
��Ŀ����
��֤��Ƴ�˹���������κ�һ������m������������д��m����������֮�͡�

���磺

1^3=1

2^3=3+5

3^3=7+9+11

4^3=13+15+17+19

��������:
����һ��int����

�������:
����ֽ���string
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string intToString(int n)
{
	stringstream ss;
	ss << n;
	return ss.str();
}

void Nichols(int n)
{
	int k = 1, index = 1;
	int before = (1 + (n - 1)) * (n - 1) / 2;
	while (index <= before)
	{
		if (k % 2 != 0)
		{
			index++;
		}
		k++;
	}
	k++;
	string res = "";
	for (int i = 0; i < n - 1; i++)
	{
		
		res = res + intToString(k) + "+";
		k += 2;
	}
	res = res + intToString(k);
	cout << res << endl;

	
}


int main()
{
	int n;
	while (cin >> n)
	{
		Nichols(n);
	}
	return 0;
}


