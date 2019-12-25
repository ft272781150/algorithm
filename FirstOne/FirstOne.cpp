/*
题目描述
找出字符串中第一个只出现一次的字符







输入描述:
输入一个非空字符串

输出描述:
输出第一个只出现一次的字符，如果不存在输出-1
*/
#include <iostream>
#include <string>
#include <map>


using namespace std;

void firstOne(string str)
{
	map<char, int> mm;
	map<char, int>::iterator it;
	bool flag = false;
	for (int i = 0; i < str.size(); i++)
	{

		mm[str[i]] ++;
		
	}

	for (int i = 0; i < str.size(); i++)
	{

		if (mm[str[i]] == 1)
		{
			cout << str[i] << endl;;
			flag = true;
			break;
		}

	}
	if (!flag)
	{
		cout << "-1" << endl;
	}
		
}


int main()
{
	string str;
	while (cin >> str)
	{
		firstOne(str);
	}
	return 0;
}


