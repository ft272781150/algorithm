/*
��Ŀ����
��Ŀ���⣺

�ж϶��ַ����е������ַ��Ƿ��ڳ��ַ�����ȫ������

��������:
���������ַ�������һ��Ϊ���ַ����ڶ���Ϊ���ַ���

�������:
����ֵ��
*/
#include <iostream>
#include <string>
#include <set>

using namespace std;


void match(string shortStr, string longStr)
{
	set<char> sc;
	for (int i = 0; i < longStr.size(); i++)
	{
		sc.insert(longStr[i]);
	}
	int len1 = sc.size();

	for (int i = 0; i < shortStr.size(); i++)
	{
		sc.insert(shortStr[i]);
	}

	if (sc.size() > len1)
	{
		cout << "false" << endl;
	}
	else
	{
		cout << "true" << endl;
	}
}

int main()
{
	string shortStr, longStr;
	while (cin >> shortStr >> longStr)
	{
		match(shortStr, longStr);
	}

	return 0;
}


