/*
��Ŀ����
����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,
���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
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



