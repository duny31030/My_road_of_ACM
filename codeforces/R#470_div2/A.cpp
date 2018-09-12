
//please don not hack me

#include <bits/stdc++.h>

using namespace std;


#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))

char a[600][600];
int n,m;
int main()
{
	scanf("%d %d",&n,&m);
	// printf("%d %d\n",n,m);
	int i,j;
	
	for(i = 0;i < n;i++)
	{
		scanf("%s",a[i]);
	}

	int flag = 0;
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < m;j++)
		{
			
			if((a[i][j] == 'S' && a[i][j+1] == 'W') || (a[i][j] == 'W' && a[i][j+1] == 'S'))
			{
				
				flag = 1;
				break;
			}
			if((a[i][j] == 'S' && a[i+1][j] == 'W') || (a[i][j] == 'W' && a[i+1][j] == 'S'))
			{
				flag = 1;
				break;
			}
		}
		// printf("\n");
	}
	if(flag)
		printf("No\n");
	else
	{
		printf("Yes\n");
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < m;j++)
			{
				if(a[i][j] == '.')
					printf("D");
				else
					printf("%c",a[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}