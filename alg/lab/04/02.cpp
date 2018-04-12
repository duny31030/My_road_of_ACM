#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int dp[N][N];
int w[6] = {0,2,2,6,5,4};   // w[0]不用
int v[6] = {0,6,3,5,4,6};   // v[0]不用
int n = 5,C = 10;
int Knapsack(int i,int j)
{
	int r1 = 0;
	int r2 = 0;
	int r = 0;

	if(i == -1)
		return 0;

	if(j >= v[i])
	{
		r1 = Knapsack(i-1,j-v[i]+w[i]);
		r2 = Knapsack(i-1,j);
		r = max(r1,r2);
		printf("r1 = %d r2 = %d r = %d\n",r1,r2,r);
	}
	return r;
}


int main()
{
	printf("%d\n",Knapsack(n,C));
	
	return 0;
}


