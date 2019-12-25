/*
题目描述
请实现如下接口

public   static   int  findNumberOf1( int num)

{

  请实现  

return  0;

	} 譬如：输入5 ，5的二进制为101，输出2



	涉及知识点：

		输入描述 :
	输入一个整数

		输出描述 :
	计算整数二进制中1的个数
*/
#include <iostream>
#include <bitset>

using namespace std;

void findBinaryOne(int n)
{
	int count = 0;
	bitset<32> b;
	b = n;
	string str = b.to_string();
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '1') count++;
	}
	cout << count << endl;

}


int main()
{
	int n;
	while (cin >> n)
	{
		findBinaryOne(n);
	}
	return 0;
}



