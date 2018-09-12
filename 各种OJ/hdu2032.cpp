#define _CRT_SBCURE_NO_DEPRECATE
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int maxn = 110;
const int INF = 0x3f3f3f3f;

bool cmp(const int &a,const int &b)
{
	return a>b;
}

int ll a[32][32];

int main()
{
	int i,j;
	
	a[0][0] = 1;
	a[1][0] = 1;
	a[1][1] = 1;
	for(i = 2;i < 30;i++)
	{
		for(j = 0;j <= i;j++)
		{
			a[i][j] = a[i-1][j-1] + a[i-1][j];
		}
	}
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(i = 0;i < n;i++)
		{

			for(j = 0;j <= i;j++)
			{
				if(j == 0)
					printf("%lld",a[i][j]);
				else
					printf(" %lld",a[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}


