/*
题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


bool IsPopOrder(vector<int> pushV, vector<int> popV) {

	if (pushV.size() < 1)
		return false;
	stack<int> si;
	si.push(pushV[0]);
	for (int i = 0, j = 1; i < popV.size(); )
	{
		if (popV[i] != si.top())
		{
			if (j < pushV.size())
			{
				si.push(pushV[j++]);
			}
			else
			{
				break;
			}
			
		}
		else
		{
			si.pop();
			i++;
		}
	}

	if (si.size() > 0)
		return false;
	else
		return true;

}

int main()
{
	vector<int> a, b;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);

	b.push_back(4);
	b.push_back(5);
	b.push_back(3);
	b.push_back(2);
	b.push_back(1);

	cout << IsPopOrder(a, b) << endl;

}



