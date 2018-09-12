#include <cstdio>
#include <cstring>

using namespace std;

int a[10005];

int main()
{
	long long n;
	scanf("%lld",&n);
	
	a[0] = 1;
	a[1] = 2;

	for(int i =2;i<=50;i++)
	{
		a[i] = a[i-1] + a[i-2];
	}

	int flag = 0;

	for(int i = 1;i <= 50;i++)
	{
		if(a[i] == n)
		{
			flag = 1;
			break;
		}
	}

	if(flag)	printf("Sha\n");
	else	printf("Xian\n");

	return 0;
}