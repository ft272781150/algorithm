/*
求最大会问子串 以及 长度
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string preProcess(string str)
{
	string newS = "$#";
	for (int i = 0; i < str.size(); i++)
	{
		newS += str[i];
		newS += '#';
	}

	return newS;
}


/*
Manacher算法
*/
void Manacher(string str)
{
	string res;
	string news = preProcess(str);
	vector<int> p(news.size(), 0);
	int mx = 0, id = 0, maxLen = -1;
	for (int i = 1; i < news.size(); i++)
	{
		if (i < mx)
			p[i] = min(p[2 * id - i], mx - i);
		else
			p[i] = 1;

		while (news[i - p[i]] == news[i + p[i]])	p[i]++;

		if (mx < i + p[i])
		{
			id = i;
			mx = i + p[i];
		}

		maxLen = max(maxLen, p[i] - 1);
	}
	for (int i = id - p[id] + 1; i < id + p[id] - 1; i++)
	{
		if(news[i] != '#')
			res += news[i];
	}
		
	cout << res << endl;
	cout << maxLen << endl;

}

/*
动态规划解法
dp[i][j] 表示 string[i][j]中 i 和 j元素是否相等。
*/
void longestPalindrome(string str)
{
	int size = str.size();
	vector<vector<bool>> dp(size + 1, vector<bool>(size + 1, false));
	int maxLen = -1;
	for (int i = 0; i < size; i++)	dp[i][0] = true;
	for (int i = 0; i < size; i++)	dp[0][i] = true;
	for (int i = 1; i <= size; i++)
	{
		int j = i;
		while (j >= 1)
		{
			if (str[j - 1] == str[i - 1] && (i - j < 2 || dp[i - 1][j + 1]))
			{
				dp[i][j] = true;
				maxLen = max(maxLen, i - j + 1);
			}
			--j;
		}
	}

	cout << maxLen << endl;
}





int main()
{
	string str;
	while (cin >> str)
	{
		//Manacher(str);
		longestPalindrome(str);
	}
	return 0;
}



