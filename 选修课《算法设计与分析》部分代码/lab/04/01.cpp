#include <bits/stdc++.h>

using namespace std;

// n = 5 c = 10
// w = {2,2,6,5,4}
// v = {6,3,5,4,6}

const int n = 1000;
int dp[n][n];
int main()
{
	int w[6] = {0,2,2,6,5,4};
	int v[6] = {0,6,3,5,4,6};
	int n = 5;
	int C = 10;
	for(int i = n;i >= 1;i--)
	{
		for(int j = 0;j <= C;j++)
		{
			dp[i][j] = (i == n ? 0 : dp[i+1][j]);
			if(j >= v[i])
				dp[i][j] = max(dp[i][j],dp[i+1][j-v[i]]+w[i]);
		}
	}
	// for(int i = n;i >= 1;i--)
	// {
	// 	for(int j = 0;j <= C;j++)
	// 	{
	// 		printf("%2d ",dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
	
	printf("==========================\n背包内最大总价值为：%d\n==========================\n",dp[1][C]);
	return 0;
}


