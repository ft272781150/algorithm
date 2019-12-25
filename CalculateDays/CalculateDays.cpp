#include<iostream>
using namespace std;
int dataToDay(int year, int month, int day)
{
	if (year <= 0 || month <= 0 || month>12 || day>31 || day <= 0) return -1;
	int lemp[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int Nolemp[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	bool flag;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		flag = true;
	else
		flag = false;
	if (flag)
	{
		if (day>lemp[month - 1]) return -1;
	}
	else
	{
		if (day>Nolemp[month - 1]) return -1;
	}
	int temp = 0;
	for (int i = 0; i<month - 1; i++)
	{
		if (flag)
			temp = temp + lemp[i];
		else
			temp = temp + Nolemp[i];
	}
	return temp + day;
}

int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		cout << dataToDay(year, month, day) << endl;
	}

}
