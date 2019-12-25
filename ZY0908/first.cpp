#include <iostream>
#include <string>
#include <vector>


using namespace std;

#define random(x) (rand()%x)

void func(const char*str, float sum, int num, float min, float max)
{

	sscanf(str, "总金额%f元，总人数%d,红包最小金额%f元，最大金额%f元", &sum, &num, &min, &max);
	sum -= 1;




}

int main()
{
	float sum;
	int num;
	float min, max;
	string input;
	while (getline(cin, input))
	{
		func(input.c_str(), sum, num, min, max);
	}
	return 0;
}