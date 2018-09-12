#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{

	int n,m;
	int a[60][7];
	double b[7];
	double c[60];
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(m == 0 || n == 0)
			break;
		
		int p = 0;
		
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				scanf("%d",&a[i][j]);
				b[j] += a[i][j];
				c[i] += a[i][j];
			}
		}
		for(int i = 1;i <= n;i++)
			c[i] /= m;
		for(int i = 1;i <= m;i++)
			b[i] /= n;
		for(int i = 1;i <= n;i++)
		{
			int flag = 1;
			for(int j = 1;j <= m;j++)
			{
				if(a[i][j] < b[j])
				{
					flag = 0;
					continue;
				}
			}
			if(flag)
				p++;
		}
		for(int i = 1;i <= n;i++)
		{
			if(i == 1)
			{
				printf("%.2lf",c[i]);
			}
			else
			{
				printf(" %.2lf",c[i]);
			}
		}
		printf("\n");
		for(int i = 1;i <= m;i++)
		{
			if(i == 1)
			{
				printf("%.2lf",b[i]);
			}
			else
			{
				printf(" %.2lf",b[i]);
			}
			
		}
		printf("\n");
		printf("%d\n\n",p);
	}
	
	return 0;
}


