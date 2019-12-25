/*
��Ŀ����
���Һ�����

��Ŀ���������⣨�û����ɼ������У����Ի�óɼ��Ӹߵ��ͻ�ӵ͵��ߵ�����,��ͬ�ɼ�
������¼��������ǰ�Ĺ�����

��ʾ��
jack      70
peter     96
Tom       70
smith     67

�Ӹߵ���  �ɼ�
peter     96
jack      70
Tom       70
smith     67

�ӵ͵���

smith     67

Tom       70
jack      70
peter     96

��������:
������У�������Ҫ������˵ĸ�����Ȼ��ֱ��������ǵ����ֺͳɼ�����һ���ո����

�������:
����ָ����ʽ������ֺͳɼ������ֺͳɼ�֮����һ���ո����
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<string, int> KV_PAIR;





bool Ascending(KV_PAIR a, KV_PAIR b)
{
	return a.second < b.second;
}

bool Descending(KV_PAIR a, KV_PAIR b)
{
	return a.second > b.second;
}


int main()
{
	int n, order;
	
	while (cin >> n >> order)
	{
		vector<KV_PAIR> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i].first >> v[i].second;
		}

		if (order == 0)
		{
			stable_sort(v.begin(), v.end(), Descending);
		}
		else
		{
			stable_sort(v.begin(), v.end(), Ascending);
		}

		for (int i = 0; i < n; i++)
		{
			cout << v[i].first << " " << v[i].second << endl;
		}
	}
	return 0;
}
