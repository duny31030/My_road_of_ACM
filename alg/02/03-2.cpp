#include <bits/stdc++.h>

using namespace std;

int a[1000];

int main()
{
	for(int i = 1;i < 1000;i++)
	{
		a[i] = a[i/2*2-1]+a[i/2];
	}
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",a[n]);
	}
	return 0;
}