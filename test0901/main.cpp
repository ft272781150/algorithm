/*

*/
#include<iostream>
#include <vector>
#include <stack>

using namespace std;

bool isOK(vector<int> inStack, vector<int> outStack)
{
	stack<int> a;
	int inlen = inStack.size();
	int j = 0;
	for (int i = 0; i<inlen; i++)
	{
		if (a.empty() || a.top() != outStack[j])
		{
			a.push(inStack[i]);
		}
		else if (a.top() == outStack[j])
		{
			a.pop();
			j++;
		}

	}

	while (a.size() > 0 && a.top() == outStack[j])
	{
		a.pop();
		j++;
	}

	if (a.size() > 0)
		return false;
	else
		return true;
}


int main()
{
	int n;
	while(cin>>n)
}


