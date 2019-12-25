/*
��Ŀ����
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ�
��������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
��ע�⣺���������еĳ�������ȵģ�
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



