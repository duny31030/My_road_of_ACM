//http://codeforces.com/contest/940
//经测试long long 改为int 也对
//一开始错的很迷

#include <cstdio>
#include <algorithm>

#define ll long long
using namespace std;
ll a[110],n,d,mmax,max1;
int main()
{
	
	while(~scanf("%lld %lld",&n,&d))
	{
		for(ll i = 1;i <= n;i++)
			scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		max1=-1;
		for(ll i = 1;i <= n;i++)
		{
			mmax = 1;
			for(ll j = i+1;j<=n;j++)
			{
				if(a[j]-a[i] <= d)	
					mmax++;
				else	
					break;
			}
			
			if(mmax>max1)
				max1 = mmax;
		}
		printf("%lld\n",n-max1);
	}
	return 0;
}