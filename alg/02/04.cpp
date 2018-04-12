#include <bits/stdc++.h>

using namespace std;

int a[1005];

int HalfSet(int n)
{
	if(a[n] > 0)
		return a[n];
	else
	{
		a[n] = 1;
		for(int i = 1;i <= n/2;i++)
		{
			a[n] += HalfSet(i);
			if(i > 10 && ((i/10) <= ((i%10)/2)))
			{
				a[n] -= a[i/10];
			}
		}
		return a[n];
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",HalfSet(n));
	return 0;
}