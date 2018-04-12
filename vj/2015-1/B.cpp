#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	float sum = 0.0,a;
	for(int i = 1;i <= 12;i++)
	{
		cin >> a;
		sum += a;
	}
	printf("%.2lf$",sum/12);
	return 0;
}
