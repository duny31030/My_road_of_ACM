#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool cmp(const int &a,const int &b)
{
	return a>b;
}


int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(int i = 0;i <= n+1;i++)
		{
			if(i == 0 || i == n+1)
				printf("+");
			else
				printf("-");
		}
		printf("\n");
		for(int i = 1;i <= m;i++)
		{
			for(int j = 0;j <= n+1;j++)
			{
				if(j == 0 || j == n+1)
					printf("|");
				else
					printf(" ");
			}
			printf("\n");
		}
		for(int i = 0;i <= n+1;i++)
		{
			if(i == 0 || i == n+1)
				printf("+");
			else
				printf("-");
		}
		printf("\n\n");
	}
	
	return 0;
}


