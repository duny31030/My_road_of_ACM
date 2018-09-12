#include <bits/stdc++.h>

using namespace std;

int a[1000];

int main()
{
	int n;
	scanf("%d",&n);
	int mmax = 0,Mmax = 0;
	while(n--)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
		if(a[x] > mmax)
		{
			mmax = a[x];
			Mmax = x;
		}
	}
	printf("%d %d\n",Mmax,mmax);

	return 0;
}