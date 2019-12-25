/*
题目描述
矩阵乘法的运算量与矩阵乘法的顺序强相关。


例如：

A是一个50×10的矩阵，B是10×20的矩阵，C是20×5的矩阵



计算A*B*C有两种顺序：（（AB）C）或者（A（BC）），前者需要计算15000次乘法，后者只需要3500次。



编写程序计算不同的计算顺序需要进行的乘法次数









输入描述:
输入多行，先输入要计算乘法的矩阵个数n，每个矩阵的行数，列数，总共2n的数，最后输入要计算的法则

输出描述:
输出需要进行的乘法次数
*/
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
	int row;
	int column;
}Matrix;

int calculateCount(vector<Matrix> &vm, int front, int back)
{
	int res = vm[front].row * vm[front].column * vm[back].column;
	vm[front].column = vm[back].column;
	return res;
}

void MatrixMultiplyCount(vector<Matrix> &vm, string rule)
{
	stack<int> stackRule;
	int res = 0;
	int index = 0;
	for (int i = 0; i < rule.size(); i++)
	{
		if (rule[i] == '(')
			continue;
		else if(rule[i]!=')')
		{
			stackRule.push(index);
			index++;
		}
		else
		{
			if (stackRule.size() >= 2)
			{
				int back = stackRule.top();
				stackRule.pop();
				int front = stackRule.top();
				stackRule.pop();
				res += calculateCount(vm, front, back);
				stackRule.push(front);
			}
			else
			{
				break;
			}


		}
	}
	cout << res << endl;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<Matrix> vm(n);
		for (int i = 0; i < n; i++)
		{
			cin >> vm[i].row >> vm[i].column;
		}
		string rule;
		cin >> rule;

		MatrixMultiplyCount(vm, rule);
	}
}



