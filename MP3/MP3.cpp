/*
��Ŀ����
MP3 Player��Ϊ��Ļ��С����ʾ�����б��ʱ��ÿ��ֻ����ʾ���׸������û�Ҫͨ�����¼�����������еĸ�����Ϊ�˼򻯴�������ÿ��ֻ����ʾ4�׸���������ʼ��λ��Ϊ��1�׸衣



����Ҫʵ��ͨ�����¼����ƹ���ƶ�����������б������߼����£�

��������<=4��ʱ�򣬲���Ҫ��ҳ��ֻ��Ų�����λ�á�

����ڵ�һ�׸�����ʱ����Up�����Ų�����һ�׸�������������һ�׸���ʱ����Down�����Ų����һ�׸�����



����������û���Up�������Ų����һ�׸������û���Down�������Ų����һ�׸�����



2. ������������4��ʱ����һ����10�׸�Ϊ������



���ⷭҳ����Ļ��ʾ���ǵ�һҳ������ʾ��1 �C 4�ף�ʱ������ڵ�һ�׸����ϣ��û���Up������ĻҪ��ʾ���һҳ������ʾ��7-10�׸裩��ͬʱ���ŵ����һ�׸��ϡ�ͬ���ģ���Ļ��ʾ���һҳʱ����������һ�׸����ϣ��û���Down������ĻҪ��ʾ��һҳ�����Ų����һ�׸��ϡ�



һ�㷭ҳ����Ļ��ʾ�Ĳ��ǵ�һҳʱ������ڵ�ǰ��Ļ��ʾ�ĵ�һ�׸���ʱ���û���Up������Ļ�ӵ�ǰ��������һ�׿�ʼ��ʾ�����ҲŲ����һ�׸�������굱ǰ��Ļ�����һ�׸�ʱ��Down������Ҳ���ơ�



������������÷�ҳ��ֻ��Ų�������С�



��������:
����˵����
1 �����������
2 �������� U����D

�������:
���˵��
1 �����ǰ�б�
2 �����ǰѡ�и���
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int move(int curIndex, char command, vector<int> link, int &head)
{
	int nextIndex = curIndex;
	switch (command)
	{
	case 'U':
	{
		if (curIndex == 0)
		{
			nextIndex = link.size() - 1;
			head = (link.size() - 4) >= 0 ? (link.size() - 4) : 0;
		}
		else
		{
			nextIndex = curIndex--;

		}
		break;
	}

	case 'D':
	{
		if (curIndex == link.size() - 1)
		{
			nextIndex = 0;
		}
		else
		{
			nextIndex = curIndex++;
		}
		break;
	}

	default:
		break;
	}
	return nextIndex;
}

void MP3(int n, string str)
{
	vector<int> link;
	int block = 0;
	for (int i = 1; i <= n; i++)
	{
		link.push_back(i);
	}
	for (int i = 0; i < str.size(); i++)
	{
		//block = move(block, str[i], link);
	}

	for (int i = block; i < block + 4 && i < link.size(); i++)
	{
		cout << link[i] << " ";
	}
	cout << endl;


}


int main()
{
	int n;
	string command;
	while (cin >> n >> command)
	{
		MP3(n, command);
	}
	return 0;
}




