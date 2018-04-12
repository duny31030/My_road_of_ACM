#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	long long a[n+10],amin,amax,diff = -1,row,col,x,y,minrow,maxrow,m = 1000000000;
	for(i = 0;i < n;i++)
	{
		scanf("%lld",&a[i]);
		if(i == 0)
		{
			amin = a[i];
			amax = a[i];
		}
		else
		{
			if(a[i] > amax)
				amax = a[i];
			if(a[i] < amin)
				amin = a[i];
		}
	}

	for(i = 0;i < n-1;i++)
	{
		x = abs(a[i] - a[i+1]);
		if(x != 1)
		{
			diff = x;
			if(diff == 0)
			{
				printf("NO\n");
				return 0;
			}
			break;
		}
	}

	if(diff == -1)
	{
		col = amax-amin+1;
		if(col > m)
		{
			printf("NO\n");
			return 0;
		}

		for(x = m;x >= col;x--)
		{
			minrow = (amin+x-1)/x;
			maxrow = (amax+x-1)/x;
			if(maxrow > m || minrow >m)
			{
				printf("NO\n");
				return 0;
			}
			if(maxrow == minrow)
			{
				printf("YES\n");
				printf("%lld %lld\n",minrow,x);
				return 0;
			}
		}
		printf("NO\n");
		return 0;
	}

	for(i = 0;i < n-1;i++)
	{
		x = abs(a[i]-a[i+1]);
		if(x != 1 && x != diff)
		{
			printf("NO\n");
			return 0;
		}
		if(x == 1)
		{
			if((a[i]%diff == 0 && a[i+1]>a[i]) || (a[i+1]%diff == 0 && a[i] > a[i+1]))
			{
				printf("NO\n");
				return 0;
			}
		}
	}

	row = (amax+diff-1)/diff;
	if(row > m)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	printf("%lld %lld\n",row,diff);
	return 0;
}


