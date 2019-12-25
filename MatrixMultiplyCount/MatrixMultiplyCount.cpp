/*
��Ŀ����
����˷��������������˷���˳��ǿ��ء�


���磺

A��һ��50��10�ľ���B��10��20�ľ���C��20��5�ľ���



����A*B*C������˳�򣺣���AB��C�����ߣ�A��BC������ǰ����Ҫ����15000�γ˷�������ֻ��Ҫ3500�Ρ�



��д������㲻ͬ�ļ���˳����Ҫ���еĳ˷�����









��������:
������У�������Ҫ����˷��ľ������n��ÿ��������������������ܹ�2n�������������Ҫ����ķ���

�������:
�����Ҫ���еĳ˷�����
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



