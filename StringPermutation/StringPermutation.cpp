/*
题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,
则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<string> Permutation(string str) {

	vector<string> res;
	res.clear();
	
	if (str != "")
	{
		sort(str.begin(), str.end());
		do
		{
			res.push_back(str);

		} while (next_permutation(str.begin(), str.end()));
	}


	return res;
}

bool isSwap(string str, int begin, int end)
{
	for (int i = begin; i < end; i++)
	{
		if (str[i] == str[end])
			return false;
	}
	return true;
}

void permutation(vector<string> &res, string &str, int n)
{
	if (n == str.size() - 1)
		res.push_back(str);
	//set<char> s;
	for (int i = n; i < str.size(); i++)
	{
		if (isSwap(str, n, i))
		{
			//s.insert(str[i]);
			swap(str[i], str[n]);
			permutation(res, str, n + 1);
			swap(str[i], str[n]);
		}

		
			

	}
}

vector<string> Permutation2(string str)
{
	vector<string> res;
	permutation(res, str, 0);
	sort(res.begin(), res.end());
	return res;
}


bool nextPermutation(string &str)
{
	if (str.size() < 2)
		return false;
	int size = str.size();
	for (int i = size - 1, j = i - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (str[j] < str[i])
		{
			int k = size - 1;
			while (str[k] <= str[j])
				k--;
			swap(str[j], str[k]);

			reverse(str.begin() + j + 1, str.end());
			return true;
		}
	}
	reverse(str.begin(), str.end());
	return false;
}


vector<string> Permutation3(string str)
{
	vector<string> res;
	res.clear();

	if (str != "")
	{
		sort(str.begin(), str.end());
		do
		{
			res.push_back(str);

		} while (nextPermutation(str));
	}


	return res;
}

int main()
{
	string str = "abc";
	vector<string> res = Permutation3(str);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
	return 0;
}



