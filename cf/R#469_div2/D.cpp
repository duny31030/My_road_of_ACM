#include <bits/stdc++.h>

using namespace std;

int main()
{

	long long a[100000];
	memset(a,0,sizeof a);
	long long n;
	int q;
	scanf("%lld %d",&n,&q);

	for(long long i = n;i >= 1;i--)
		{
			
			if(i <= (n+1)/2 && i/2 != 0)
			{
				a[2*i-1] = i;
			}
			else
			{
				long long xx = (i*2)-1;
				long long t = (n-i)*2+1;
				while(xx)
				{
					if(xx-t <= 0)
					{
						a[xx] = i;
						break;
					}
					xx -= t;
					t *= 2;
				}
			}
		}

	while(q--)
	{
		long long c;
		scanf("%lld",&c);
		printf("%lld\n",a[c]);
	}
	
	return 0;
}



