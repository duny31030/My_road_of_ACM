#include <bits/stdc++.h>

using namespace std;

int a[10];
int vis[10];

void dfs(int n,int r,int step)
{
	
	if(step == r)
	{
		for(int i = 0;i < r;i++)
			printf("%d",a[i]);
		printf("\n");
		return ;
	}

	for(int i = n;i >= 1;i--)
	{
		if(vis[i] != 1)
		{
			vis[i] = 1;
			a[step] = i;
			if(step == 0)
			{
				dfs(n,r,step+1);
			}
			else
				if(a[step] < a[step-1])
				{
					dfs(n,r,step+1);
				}
			vis[i] = 0;
		}
	}
}


int main()
{
	int n,r;
	scanf("%d %d",&n,&r);
	dfs(n,r,0);
	return 0;
}