#include <bits/stdc++.h>

using namespace std;

#define N 1000

char x[N],y[N];
int b[N+5][N+5];
int c[N+5][N+5];

void LCSLength(int m,int n)
{
	int i,j;
	for(i = 1;i <= m;i++)
		c[i][0] = 0;
	for(i = 1;i <= m;i++)
		c[0][i] = 0;
	for(i = 1;i <= m;i++)
		for(j = 1;j <= m;j++)
		{
			if(x[i] == y[j])
			{
				c[i][j] = c[i-1][j-1]+1;
				b[i][j] = 1;
			}
			else
				if(c[i-1][j] >= c[i][j-1])
				{
					c[i][j] = c[i-1][j];
					b[i][j] = 2;
				}
				else
				{
					c[i][j] = c[i][j-1];
					b[i][j] = 3;
				}
		}
}

void LCS(int i,int j)
{
	if(i == 0 || j == 0)
		return ;
	if(b[i][j] == 1)
	{
		LCS(i-1,j-1);
		cout << x[i];
	}
	else
		if(b[i][j] == 2)
			LCS(i-1,j);
		else
			LCS(i,j-1);
}

int main()
{
	int n,m,i;
	scanf("%d %d",&n,&m);
	getchar();
	for(i = 1;i <= n;i++)
		scanf("%c",&x[i]);
	getchar();
	for(i = 1;i <= m;i++)
		scanf("%c",&y[i]);
	LCSLength(n,m);
	LCS(n,m);
	cout << endl;
	return 0;
}


