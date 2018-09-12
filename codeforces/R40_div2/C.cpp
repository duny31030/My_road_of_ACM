// 超时
#include <bits/stdc++.h>
using namespace std;

long long x=5,y=0;
int a[200010];
int main()
{	
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	int flag1 = 1;
	int flag2 = 1;
	for(int i = 1; i < n;i++)
	{

		if(a[i] == a[i-1])
		{
			flag2 = 0;
			break;
		}
		if(fabs(a[i] - a[i-1]) == 1)
		{
		}
		else
		{
			if(flag1 == 1)
			{
				flag1 = 0;
				y = fabs(a[i] - a[i-1]);
				break;
			}
			else
			{
				if(fabs(a[i] - a[i-1]) != y)
				{

					flag2 = 0;
					break;
				}
			}
		}
	}
	if(flag2 == 1)
	{
		for(int i = 1; i < n;i++)
		{
			if(a[i] == a[i-1])
			{
				flag2 = 0;
				break;
			}
			if(fabs(a[i] - a[i-1]) == 1)
			{
				if(a[i-1]%y == 0 && a[i] - a[i-1] == 1)
				{
					flag2 = 0;
					break;
				}
			}
			else
			{
				if(flag1 == 1)
				{
					flag1 = 0;
					y = fabs(a[i] - a[i-1]);
					break;
					// printf("y = %lld\n",y);
				}
				else
				{
					if(fabs(a[i] - a[i-1]) != y)
					{

						flag2 = 0;
						break;
					}
					else
					{
						x++;
					}
				}
			}
		}
	}
	

	if(flag2 == 0)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		if(y == 0)
			printf("%lld 1\n",x);
		else
			printf("%lld %lld\n",x,y);
	}


	return 0;
}