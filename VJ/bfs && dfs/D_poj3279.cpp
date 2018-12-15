#include <cstdio>

using namespace std;

int a[20][20];
int b[20][20];
int main()
{
	int m,n;
	
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		for(int i = 0;i < m;i++)
			for(int j = 0;j < n;j++)
				scanf("%d",&a[i][j]);

		for(int i = 0;i < m-1;i++)
		{
			for(int j = 0;j < n;j++)
			{
				if(a[i][j] == 1)
				{
					b[i+1][j] = 1;
					a[i][j] = 0;
					a[i+1][j] = a[i+1][j] == 1 ? 0 : 1;

					if(j-1 >= 0)
						a[i+1][j-1] = a[i+1][j-1] == 1 ? 0 : 1;
					
					if(j+1 < n)
						a[i+1][j+1] = a[i+1][j+1] == 1? 0 : 1;

					// if(i-1 >= 0)
					// 	a[i-1][j] = a[i-1][j] == 1 ? 0 : 1;

					if(i+2 < m)
						a[i+2][j] = a[i+2][j] == 1 ? 0 : 1;
				}
			}
		}

		int flag = 1;
		// for(int i = 0;i < m;i++)
		// {
		// 	for(int j = 0;j < n;j++)
		// 		printf("%d ",b[i][j]);
		// 	printf("\n");
		// }
		for(int i = 0;i < n;i++)
		{
			if(a[m-1][i] == 1)
				flag = 0;
		}

		if(flag)
			for(int i = 0;i < m;i++)
			{
				for(int j = 0;j < n;j++)
				{
					if(j == 0)
						printf("%d",b[i][j]);
					else
						printf(" %d",b[i][j]);
				}
				printf("\n");
			}
		else
			printf("IMPOSSIBLE\n");

		for(int i = 0;i < m;i++)
			for(int j = 0;j < n;j++)
			{
				a[i][j] = 0;
				b[i][j] = 0;
			}

	}

	
	return 0;
}


