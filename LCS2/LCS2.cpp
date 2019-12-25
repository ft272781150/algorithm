/*
题目描述
题目标题：

计算两个字符串的最大公共字串的长度，字符不区分大小写

详细描述：

接口说明

原型：

int getCommonStrLength(char * pFirstStr, char * pSecondStr);

输入参数：

char * pFirstStr //第一个字符串

char * pSecondStr//第二个字符串


输入描述:
输入两个字符串

输出描述:
输出一个整数
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void preProcess(string &str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] < 'a')
		{
			str[i] += 32;
		}
	}
}

void LCS(string str1, string str2)
{
	preProcess(str1);
	preProcess(str2);

	int len1 = str1.size();
	int len2 = str2.size();

	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 1; i <= len1; i++)
	{
		dp[i][0] = 0;
	}

	for (int i = 1; i <= len2; i++)
	{
		dp[0][i] = 0;
	}

	int res = 0;
	int index = 0;

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
					index = i;
				}
			}
			else
			{
				dp[i][j] = 0;
			}
		}
	}

	cout << res << endl;
}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		LCS(str1, str2);
	}
}



