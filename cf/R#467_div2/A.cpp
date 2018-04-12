//http://codeforces.com/contest/937

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a[610];
	memset(a,0,sizeof a);
	int n,tmp,ans=0;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&tmp);
		if(a[tmp] == 0 && tmp != 0)
		{
			ans++;
			a[tmp]++;
		}
	}
	printf("%d\n",ans);
	return 0;
}