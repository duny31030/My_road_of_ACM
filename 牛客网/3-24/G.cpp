#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool cmp(const int &a,const int &b)
{
	return a>b;
}
int T,i,j,l=0,r=0;
char s[35][35];
char lr[1010];
int n,m;
void print(int n,int m)
{
	printf("%d %d\n",n,m);
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < m;j++)
			printf("%c",s[i][j]);
		printf("\n");
	}
	printf("\n");
}

void print1(int n,int m)
{
	printf("%d %d\n",m,n);
	for(j = m-1;j >= 0;j--)
	{
		for(i = 0;i < n;i++)
		{
			// printf("%d%d",i,j);
			if(s[i][j] == '-')
				printf("|");
			else
				if(s[i][j] == '|')
					printf("-");
				else
					printf("%c",s[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void print2(int n,int m)
{
	printf("%d %d\n",n,m);
	for(i = n-1;i  >= 0;i--)
	{
		for(j = m-1;j >= 0;j--)
			printf("%c",s[i][j]);
		printf("\n");
	}
	printf("\n");
}

void print3(int n,int m)
{
	printf("%d %d\n",m,n);
	for(j = 0;j < m;j++)
	{
		// printf("j = %d\n",j);
		for(i = n-1;i >= 0;i--)
		{
			if(s[i][j] == '-')
				printf("|");
			else
				if(s[i][j] == '|')
					printf("-");
				else
					printf("%c",s[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	
	scanf("%d",&T);
	
	while(T--)
	{
		
		scanf("%d %d",&n,&m);
		for(i = 0;i < n;i++)
		{
			scanf("%s",s[i]);
		}
		// for(i = 0;i < n;i++)
		// {
		// 	for(j = 0;j < m;j++)
		// 	{
		// 		printf("%d%d%c ",i,j,s[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// getchar();
		scanf("%s",lr);
		int len = strlen(lr);
		l = 0,r = 0;
		for(i = 0;i < len;i++)
		{
			if(lr[i] == 'L')
				l++;
			else
				r++;
		}
		int ans = (l-r)%4;
		// printf("ans = %d\n",ans);
		if(ans == 0)
		{
			// printf("===ans = 0===\n");
			print(n,m);
		}
		else
		{
			if(ans < 0)
			{
				ans = 4+ans;
				// printf("2 = %d\n",ans);
			}
			if(ans == 1)
			{
				// printf("===ans = 1===\n");
				print1(n,m);
			}
			if(ans == 2)
			{
				// printf("===ans = 2===\n");
				print2(n,m);
			}
			if(ans == 3)
			{
				// printf("===ans = 3===\n");
				print3(n,m);
			}
		}

	}
	
	return 0;
}


