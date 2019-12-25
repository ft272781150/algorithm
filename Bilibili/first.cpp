/*
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>


using namespace std;


void func(string str)
{
	stack<char> oper;
	int len = str.size();
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '<')
		{
			oper.push(str[i]);
		}
		while(str[i]!=)
	}
}

int main()
{
	string str;
	while (cin >> str)
	{
		func(str);
	}
}


