#include <bits/stdc++.h>

using namespace std;
int ans;
int su[90] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431};
int flag;
int vis[50];
int a[50];

bool check(int x,int y)
{
	int z = x+y;
	for(int i = 0;i <= 82;i++)
	{
		if(z == su[i])
		{
			return true;
			break;
		}
		if(z < su[i])
			return false;
	}
	return false;
}



void dfs(int n,int step)
{
	if(step == n)
	{
		if(check(a[0],a[n-1]))
		{
			for(int i = 0;i < n;i++)
			{
				flag++;
				printf("%d ",a[i]);
			}
			printf("\n");
			return ;
		}
	}


	for(int i = 2;i <= n;i++)
	{
		if(vis[i] != 1)
		{
			if(check(a[step-1],i))
			{
				vis[i] = 1;
				a[step] = i;
				dfs(n,step+1);
				vis[i] = 0;
			}

		}
	}
}


int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		flag = 0;
		if(n == 0)
			break;
		printf("Case %d:\n",++ans);
		a[0] = 1;
		
		if(n%2 == 1 && n != 1)
		{
			printf("No Answer\n");
		}
		else
		{
			dfs(n,1);
		}
	}
	return 0;
}