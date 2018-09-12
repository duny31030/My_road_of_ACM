#include <cstdio>
#include <string.h>

using namespace std;


int inf = 99999;
int need;
int a[105][105],b[105][105],tmp[105][105];
int m,n;

void changeL(int x,int y)
{
	if(x == y)
		return ;
	int i;
	for(i = 1;i <= n;i++)
	{
		int tt = tmp[i][y];
		tmp[i][y] = tmp[i][x];
		tmp[i][x] = tt;
	}
	need++;
}

void changeH(int x)
{
	int i;
	for(i = 1;i <= m;i++)
		tmp[x][i] ^= 1;
}

bool Same(int x,int y)
{
	int i;
	for(i = 1;i <= n;i++)
		if(b[i][x] != tmp[i][y])
			return false;

	return true;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);   // n行 m列
		int i,j;
		// a[N][N]
		for(i = 1; i <= n;i++)
			for(j = 1;j <= m;j++)
				scanf("%d",&a[i][j]);

		// b[N][N]
		for(i = 1;i <= n;i++)
			for(j = 1;j <= m;j++)
				scanf("%d",&b[i][j]);

		int k;
		int ans = inf;

		for(k = 1;k <= n;k++)
		{
			//copy
			for(i = 1;i <= n;i++)
				for(j = 1; j<= m;j++)
					tmp[i][j] = a[i][j];

			need = 0;
			changeL(1,k);

			for(i = 1;i <= n;i++)
			{
				if(tmp[i][1] != b[i][1])
				{
					changeH(i);
					need++;
				}
			}

			bool find;
			for(i = 1;i <= m;i++)
			{
				find = false;
				if(Same(i,i))
				{
					find = true;
					continue;
				}

				for(j = i+1;j <= m;j++)   // 寻找tmp中与b与i列相同的列
				{
					if(Same(i,j))   // tmp的j列与b的i列相同
					{
						if(Same(j,j))   // tmp的j列与b的j列相同
							continue;  
						changeL(i,j);   // 交换tmp的i,j列
						find = true;
						break;
					}
				}

				if(find == false)   // 找不到该列对应列
					break;
			}

			if(find == true && need < ans)
				ans = need;
		}
		if(ans < inf) 
			printf("%d\n",ans );
		else
			printf("-1\n");
	}
	
	return 0;
}