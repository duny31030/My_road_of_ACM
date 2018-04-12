#include <bits/stdc++.h>

using namespace std;

int sum,k,n;
int flag;
int a[105];
void dfs(int t)
{
	// printf("sum = %d\n",sum);
	if(flag == 1)
		return ;
	if(sum > k)
		return ;
	if(sum == k)
	{
		flag = 1;
	}

	for(int i = t;i < n;i++)
	{
		sum += a[i];
		dfs(i+1);
		sum -= a[i];
	}
}

int main()
{
	while(~scanf("%d",&n))
	{
		flag = 0;
		sum = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
		}
		scanf("%d",&k);
		dfs(0);
		if(flag == 1)
			printf("Of course,I can!\n");
		else
			printf("Sorry,I can't!\n");
	}
	return 0;
}