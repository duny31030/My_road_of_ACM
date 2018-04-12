#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool cmp(const int &a,const int &b)
{
	return a>b;
}


int main()
{
	int n,m,p,i,j,mmax = 0;
	int a[600];
	scanf("%d %d",&n,&m);
	memset(a,0,sizeof a);
	for(i = 1;i <= n;i++)
		for(j = 1;j <= m;j++)
		{
			a[i+j]++;
			if(a[i+j] > mmax)
				mmax = a[i+j];
		}
	p = 1;
	for(i = 1;i <= n+m;i++)
		if(a[i] == mmax)
		{
			if(p == 1)
			{
				printf("%d",i);
				p++;
			}
			else
				printf(" %d",i);
		}
	return 0;
}


