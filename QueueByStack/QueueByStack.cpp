/*
��Ŀ����
������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
*/
#include <iostream>
#include <stack>

using namespace std;


stack<int> stack1;
stack<int> stack2;


void push(int node) {

	stack1.push(node);

}

int pop() {

	if (stack2.empty())
	{
		while(!stack1.empty())
		{
			int n = stack1.top();
			stack2.push(n);
			stack1.pop();
		}
	}
	int res = stack2.top();
	stack2.pop();

	return res;
}



