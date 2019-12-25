/*
Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。
许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。
编辑距离的算法是首先由俄国科学家Levenshtein提出的，故又叫Levenshtein Distance。

Ex：

字符串A:abcdefg

字符串B: abcdef

通过增加或是删掉字符”g”的方式达到目的。这两种方案都需要一次操作。把这个操作所需要的次数定义为两个字符串的距离。

要求：

给定任意两个字符串，写出一个算法计算它们的编辑距离。



请实现如下接口

  功能：计算两个字符串的距离

*  输入： 字符串A和字符串B

*  输出：无

*  返回：如果成功计算出字符串的距离，否则返回-1



public   static   int  calStringDistance(String charA, String  charB)

{

	return  0;

}


算法思想：
第一步，找到连个字符串的最长公共子序列（动态规划）
第二步，A长度-B长度 + B长度-子序列长度 就是所得结果

错误！
因为可以直接修改，不用删除 再增加

算法思想：

* 设Ai为字符串A(a1a2a3 … am)的前i个字符（即为a1,a2,a3 … ai）
    * 设Bj为字符串B(b1b2b3 … bn)的前j个字符（即为b1,b2,b3 … bj）
	    *
		    * 设 L(i,j)为使两个字符串和Ai和Bj相等的最小操作次数。
			    * 当ai==bj时 显然 L(i,j) = L(i-1,j-1)
				    * 当ai!=bj时
					    *
						    *  若将它们修改为相等，则对两个字符串至少还要操作L(i-1,j-1)次
							    *  若删除ai或在bj后添加ai，则对两个字符串至少还要操作L(i-1,j)次
								    *  若删除bj或在ai后添加bj，则对两个字符串至少还要操作L(i,j-1)次
									    *  此时L(i,j) = min( L(i-1,j-1), L(i-1,j), L(i,j-1) ) + 1
										    *
											    * 显然，L(i,0)=i，L(0,j)=j, 再利用上述的递推公式，可以直接计算出L(i,j)值。




*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//int LCS_LENGTH(std::string A, std::string B)
//{
//	int lenA = A.length();
//	int lenB = B.length();
//	std::vector<std::vector<int>> dp(lenA, std::vector<int>(lenB));
//	for (int i = 1; i < lenA; i++)
//	{
//		dp[i][0] = 0;
//	}
//
//	for (int i = 1; i < lenB; i++)
//	{
//		dp[0][i] = 0;
//	}
//
//	for (int i = 1; i < lenA; i++)
//	{
//		for (int j = 1; j < lenB; j++)
//		{
//			if (A[i] == B[j])
//			{
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//			}
//			else if(dp[i - 1][j] > dp[i][j - 1])
//			{
//				dp[i][j] = dp[i - 1][j];
//			}
//			else
//			{
//				dp[i][j] = dp[i][j - 1];
//			}
//		}
//	}
//
//	return dp[lenA - 1][lenB - 1];
//}

int  calStringDistance(std::string charA, std::string  charB)
{


	std::vector<std::vector<int>> dp(charA.size() + 1, std::vector<int>(charB.size() + 1, 0));
	for (int i = 1; i <= charB.length(); i++) dp[0][i] = i;
	for (int i = 1; i <= charA.length(); i++) dp[i][0] = i;
	for (int i = 1; i <= charA.length(); i++)
		for (int j = 1; j <= charB.length(); j++) {
			int min1 = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;
			dp[i][j] = std::min((charA[i - 1] == charB[j - 1] ? 0 : 1) + dp[i - 1][j - 1], min1);
		}
	return dp[charA.size()][charB.size()];

}


int main()
{

	std::string A, B;
	while (std::cin >> A >> B)
	{

		std::cout << calStringDistance(A, B) << std::endl;
	}

	return 0;
}


