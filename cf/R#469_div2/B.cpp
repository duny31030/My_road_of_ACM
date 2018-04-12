#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[100010];
	int b[100010];
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	int i,j;
	int ans = 0;
	for(i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(j = 1;j <= m;j++)
	{
		scanf("%d",&b[j]);
	}

	i = 1;
	j = 1;
	long long ca = 0;
	long long cb = 0;
	ca += a[i];
	cb += b[j];
	while(i <= n && j <= m)
	{
		// printf("i = %d j = %d ca = %lld cb = %lld\n",i,j,ca,cb);
		
		if(ca == cb)
		{
			// printf("ca = %lld cb = %lld\n",ca,cb);
			ca += a[++i];
			cb += b[++j];
			ans++;
			// ca = 0;
			// cb = 0;
		}
		else
		{
			if(ca > cb)
			{
				cb += b[++j];
			}
			else
			{
				ca += a[++i];
			}
		}
	}

	printf("%d\n",ans);
	return 0;
}