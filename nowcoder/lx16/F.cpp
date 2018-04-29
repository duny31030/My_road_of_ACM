#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100010];
int main()
{
	ll n,d,p = 0,i,j;
	scanf("%lld %lld",&n,&d);
	for(i = 0;i < n;i++)
		scanf("%lld",&a[i]);
	for(p = 0,i = n-1;i > 1;i--)
	{
		j = lower_bound(a,a+n,a[i]-d)-a;
		if(j < i-1)
			p += (i-j)*(i-j-1)/2;   // 等差数列求和公式
	}
	printf("%lld\n",p);
	return 0;
}


