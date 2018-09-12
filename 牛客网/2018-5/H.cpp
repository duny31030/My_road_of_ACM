#include <cstdio>
#include <cstring>
#define maxn 50047
int c[maxn],a[maxn];
int n,t,q;

int Lowbit(int x)   //2^k
{
	return x & (-x);
}

void update(int i,int x)   //i点增量为x
{
	while(i <= t)
	{
		c[i] += x;
		i += Lowbit(i);
	}
}

int sum(int x)   //区间求和[1,x]
{
	int sum = 0;
	while(x >0)
	{
		sum += c[x];
		x -= Lowbit(x);
	}
	return sum;
}

int Getsum(int x1,int x2)   //求任意区间和
{
	return sum(x2) - sum(x1-1);
}

int main()
{
	int i,j;
	scanf("%d %d",&t,&q);
	memset(c,0,sizeof c);
	memset(a,0,sizeof a);
	for(i = 1;i <= t;i++)
	{
		scanf("%d",&a[i]);
		// printf("a[%d] = %d\n",i,a[i]);
		update(i,a[i]);
	}

	// for(i = 1;i <= t;i++)
	// {
	// 	printf("c[%d] = %d\n",i,c[i]);
	// }
	
	while(q--)
	{
		char s[10];
		int ii,jj,kk;
		scanf("%s",s);

		if(s[0] == 'Q')
		{
			scanf("%d %d",&ii,&jj);
			printf("%d\n",Getsum(ii,jj));
		}

		if(s[0] == 'C')
		{
			scanf("%d %d %d",&ii,&jj,&kk);
			for(i = ii;i <= jj;i++)
			{
				update(i,kk);
			}
		}

	}


	return 0;
}