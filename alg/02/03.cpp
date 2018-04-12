#include <bits/stdc++.h>

using namespace std;



int dfs(int n)
{
	int Sum = 1;
	if(n == 1)
		return 1;
	else
		for(int i = 1;i <= n/2;i++)
		{
			Sum += dfs(i);
		}
	return Sum;
}

int main()
{	
	int n;
	scanf("%d",&n);
	printf("%d\n",dfs(n));
	// int i;
	// for(i = 1;i < 20;i++)
	// {
	// 	printf("i = %d dfs(%d) = %d\n",i,i,dfs(i));
	// }

	return 0;
}