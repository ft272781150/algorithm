/*

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define mod 1000000007

void func(int alen, int anum, int blen, int bnum, int k)
{
	vector<vector<int>> dp(anum + bnum + 1, vector<int>(k + 1, 0));
	vector<int> len(anum + bnum + 1, 0);
	dp[0][0] = 1;
	for (int i = 1; i <= anum; i++)	len[i] = alen;
	for (int i = anum + 1; i < anum + bnum + 1; i++) len[i] = blen;
	for (int i = 1; i < anum + bnum + 1; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (j >= len[i])
				dp[i][j] = (dp[i - 1][j] % mod + dp[i - 1][j - len[i]] % mod) % mod;
			else
				dp[i][j] = dp[i - 1][j] % mod;
		}
	}

	cout << dp[anum + bnum][k] % mod << endl;
}

int main()
{
	int k;
	while (cin >> k)
	{
		int alen, anum, blen, bnum;
		cin >> alen >> anum >> blen >> bnum;

		func(alen, anum, blen, bnum, k);
	}
	return 0;
}


