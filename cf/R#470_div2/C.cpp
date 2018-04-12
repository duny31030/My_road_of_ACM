#include <bits/stdc++.h>

using namespace std;

#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))



int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	int a[20010];
	int b[20010];
	int c[20010];
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	for(i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for(j = 1;j <= n;j++)
	{
		scanf("%d",&b[j]);
	}

	for(i = 1;i <= n;i++)
	{
		for(j = 1;j <= i;j++)
		{
			if(a[j] -b[i] >= 0)
			{
				// printf("i = %d j = %d\n",i,j);
				a[j] = a[j]-b[i];
				// printf("j = %d a[j] = %d\n",j,a[j]);
				c[i] += b[i];
			}
			else
			{
				c[i] += a[j];
				a[j] = 0;
			}
		}
	}

	for(i = 1;i <= n;i++)
		printf("%d ",c[i]);
	printf("\n");

	return 0;
}