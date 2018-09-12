//#include <bits/stdc++.h>
#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

int n,m,h;
int w[300],v[300];
int dp[300];

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(n == 0)
			break;
		scanf("%d %d",&m,&h);

		int i,j,k;

		for(i = 1;i <= n;i++)
		{
			scanf("%d %d",&w[i],&v[i]);
		}
		// printf("11111\n");
		int ans = 0;
		// 当没有背包时 卡不了BUG
		if(h == 0)
		{
			memset(dp,0,sizeof(dp));
			for(i = 1;i <= n;i++)
			{
				for(j = m;j >= w[i];j--)
				{
					dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
				}
			}
			ans = dp[m];
		}
		else
		{
			for(k = 1;k <= n ;k++)
			{
				memset(dp,0,sizeof(dp));
				for(i = 1;i <= n;i++)
				{
					if(i == k)
						continue;
					for(j = m+h-1;j >= w[i];j--)
					{
						dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
					}
				}
				ans = max(ans,dp[m+h-1]+v[k]);
			}
		}
		printf("%d\n",ans);
	}


	return 0;
}