/*
题目描述
题目标题：

判断短字符串中的所有字符是否在长字符串中全部出现

输入描述:
输入两个字符串。第一个为短字符，第二个为长字符。

输出描述:
返回值：
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


