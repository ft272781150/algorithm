/*
给定一个字符串描述的算术表达式，计算出结果值。

输入字符串长度不超过100，合法的字符包括”+, -, *, /, (, )”，”0-9”，字符串内容的合法性及表达式语法的合法性由做题者检查。本题目只涉及整型计算。
*/
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

typedef pair<char, int> KV_Pair;
unordered_map<char, int> inside;
unordered_map<char, int> outside;

int cal(int a, int b, char op)
{
	int res = 0;
	switch (op)
	{
	case '+':
		res = a + b;
		break;
	case '-':
		res = a - b;
		break;
	case '*':
		res = a * b;
		break;
	case '/':
		res = a / b;
		break;
	default:
		cout << "error!" << endl;
		break;
	}
	return res;
}

int str2int(string str)
{
	stringstream stream(str);
	int res = 0;
	stream >> res;
	return res;
}

void preprocess(string &str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '-' && i == 0)
		{
			str.insert(0, 1, '0');
		}
		else if (str[i] == '-' && str[i - 1] == '(')
		{
			str.insert(i, 1, '0');
		}
	}
}

int calString(string str)
{
	str += '#';
	stack<char> op;
	stack<int> num;
	int len = str.size();
	op.push('#');
	string tmpNum = "";
	int i = 0;
	while (i < len)
	{
		
		if (str[i] >= '0' && str[i] <= '9')
		{
			tmpNum = "";
			while (str[i] >= '0' && str[i] <= '9')
			{
				tmpNum += str[i];
				i++;
			}
			num.push(str2int(tmpNum));
		}
		else
		{
			if (outside[str[i]] >= inside[op.top()] && str[i] == ')' && op.top() == '(')
			{
				op.pop();
				i++;
			}
			else if (str[i] == '#' && op.top() == '#')
			{
				break;
			}
			else if (outside[str[i]] > inside[op.top()])
			{
				op.push(str[i]);
				i++;
			}
			else
			{

				int second = num.top();
				num.pop();
				int first = num.top();
				num.pop();
				int res = cal(first, second, op.top());
				op.pop();
				num.push(res);


			}
		}
	}
	return num.top();
}



int main()
{
	string formula;
	
	inside.insert(KV_Pair('#', 0));
	inside.insert(KV_Pair('(', 1));
	inside.insert(KV_Pair('+', 3));
	inside.insert(KV_Pair('-', 3));
	inside.insert(KV_Pair('*', 5));
	inside.insert(KV_Pair('/', 5));

	outside.insert(KV_Pair('+', 2));
	outside.insert(KV_Pair('-', 2));
	outside.insert(KV_Pair('*', 4));
	outside.insert(KV_Pair('/', 4));
	outside.insert(KV_Pair('(', 7));
	outside.insert(KV_Pair(')', 1));
	outside.insert(KV_Pair('#', 0));

	while (cin >> formula)
	{
		preprocess(formula);
		cout << calString(formula) << endl;
	}
	return 0;
}


