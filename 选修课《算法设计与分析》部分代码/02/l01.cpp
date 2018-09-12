#include <bits/stdc++.h>

using namespace std;
int visited[10];
int a[10];
int ans = 0;
void dfs(int step,int n,int x)
{
	if(step == n+1)
	{
		printf("case %d:\n",++ans);
		for(int j = 1;j<= n;j++)
		{
			printf("%d ",a[j]);
		}
		printf("\n");
	}

	for(int i = 1;i <= x;i++)
	{
		if(visited[i] != 1)
		{
			visited[i] = 1;
			a[step] = i;
			dfs(step+1,n,x);
			visited[i] = 0;
		}
	}

}

int main()
{
	int x;
	scanf("%d",&x);
	dfs(1,x,x);
	return 0;
}