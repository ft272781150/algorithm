/*
��Ŀ����
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
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


