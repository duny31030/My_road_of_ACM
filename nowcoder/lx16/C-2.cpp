#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int m[1010][1010];
void dfs(int x,int y)
{
	m[x][y] = 0;
	for(int i = 1;i <= 1000;i++)
	{
		if(m[x][i] == 1)	dfs(x,i);
		if(m[i][y] == 1)	dfs(i,y);
	}
	return ;
}

int main()
{
	int n,x,y;
	ll ans = 0;
	cin >> n;
	memset(m,0,sizeof m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d %d",&x,&y);
		m[x][y] = 1;
	}
	for(int i = 1;i <= 1000;i++)
	{
		for(int j = 1;j <= 1000;j++)
		{
			if(m[i][j] == 1)
			{
				dfs(i,j);
				ans++;
			}
		}
	}
	printf("%lld\n",ans-1);
	
	return 0;
}


