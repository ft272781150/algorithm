/*
��Ŀ����
��ʵ�����½ӿ�

public   static   int  findNumberOf1( int num)

{

  ��ʵ��  

return  0;

	} Ʃ�磺����5 ��5�Ķ�����Ϊ101�����2



	�漰֪ʶ�㣺

		�������� :
	����һ������

		������� :
	����������������1�ĸ���
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



