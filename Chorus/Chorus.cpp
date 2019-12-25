/*
题目描述
有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，要求相邻两个学生的位置编号的差不超过 d，
使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
输入描述:
每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，接下来的一行，
包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。
接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。
输出描述:
输出一行表示最大的乘积。
*/
#include <iostream>
#include <vector>

using namespace std;



/*
维护两个DP空间，最大乘积以及最小乘积 因为存在负负得正的情况
*/
void Chorus(int n, vector<int> able, int k, int d)
{
	vector<vector<int>> dpMax(n + 1, vector<int>(k + 1, 0));
	vector<vector<int>> dpMin(n + 1, vector<int>(k + 1, 0));
	
	int res = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			dp[i][j] = res * 
		}
	}
}


int main()
{
	int n, k, d;
	while (cin >> n)
	{
		vector<int> able(n);
		for (int i = 0; i < n; i++)
		{
			cin >> able[i];
		}
		cin >> k >> d;

		Chorus(n, able, k, d);
	}
}



