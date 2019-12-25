/*
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/
#include <iostream>
#include <stack>

using namespace std;

stack<int> A,B;

void push(int value) {
	A.push(value);
	if (B.empty())
	{
		B.push(value);
	}
	else
	{
		if (value <= B.top())
			B.push(value);
	}
}
void pop() {
	
	if (A.top() == B.top())
		B.pop();
	A.pop();
}
int top() {
	return A.top();
}
int min() {
	return B.top();
}

int main()
{

}


