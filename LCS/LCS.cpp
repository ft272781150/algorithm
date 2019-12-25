/*
题目描述
查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
输入描述:
输入两个字符串
输出描述:
返回重复出现的字符
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void LCS_LENGTH(string str1, string str2, int &res, int &index)
{
	int len1 = str1.size();
	int len2 = str2.size();

	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > res)
				{
					res = dp[i][j];
					index = i - 1;
				}
			}
			else
			{
				dp[i][j] = 0;
			}
		}
	}

}


void LCS(string str1, string str2)
{
	int res = 0;
	int index = 0;
	int len1 = str1.size();
	int len2 = str2.size();

	if (len1 > len2)
	{
		LCS_LENGTH(str2, str1, res, index);
		cout << str2.substr(index - res + 1, res) << endl;
	}
	else
	{
		LCS_LENGTH(str1, str2, res, index);
		cout << str1.substr(index - res + 1, res) << endl;
	}


	

}


int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		LCS(str1, str2);
	}
	return 0;
}


