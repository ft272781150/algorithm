/*
��Ŀ����
���7�й����ֵĸ���������7�ı��������а���7�����֣���17��27��37...70��71��72��73...���ĸ���
��������:
һ��������N��(N������30000)

�������:
������N����7�йص����ָ�������������20����7�йص����ְ���7,14,17.
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


string int2str(int n)
{
	stringstream ss;
	ss << n;
	return ss.str();
}

void find7(int n)
{
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 7 == 0 || int2str(i).find('7') != string::npos)
		{
			count++;
		}
	}
	cout << count << endl;
}


int main()
{
	int n;
	while (cin >> n)
	{
		find7(n);
	}
	return 0;
}
