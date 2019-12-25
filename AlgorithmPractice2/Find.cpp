/*
��Ŀ����
��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
*/
#include <iostream>
#include <vector>


using namespace std;


/*
����˼·
һ���ǣ�
��ÿһ�п���������������飬
���ö��ֲ��ң�
ͨ������ÿһ�еõ��𰸣�
ʱ�临�Ӷ���nlogn
*/
bool Find(int target, vector<vector<int> > array) {

	for (int i = 0; i < array.size(); i++)
	{
		int left = 0;
		int right = array[0].size() - 1;
		int mid = (right - mid) / 2;
		while (left <= right)
		{
			int mid = (right + left) / 2;
			if (target == array[i][mid])
				return true;
			else if (target > array[i][mid])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}

		}
		
	}
	return false;

}

/*
����һ��˼·�ǣ�
���ö�ά�������ϵ��£������ҵ����Ĺ��ɣ�
��ôѡȡ���Ͻǻ������½ǵ�Ԫ��a[row][col]��target���бȽϣ�
��targetС��Ԫ��a[row][col]ʱ����ôtarget�ض���Ԫ��a�����е����,
��col--��
��target����Ԫ��a[row][col]ʱ����ôtarget�ض���Ԫ��a�����е��±�,
��row++��
*/
bool Find2(int target, vector<vector<int> > array) {

	int row = array.size() - 1;
	int column = 0;
	while (row >=0 && column < array[0].size())
	{
		if (array[row][column] == target)
		{
			return true;
		}
		else if(array[row][column] > target)
		{
			row--;
		}
		else
		{
			column++;
		}
	}
	return false;

}
