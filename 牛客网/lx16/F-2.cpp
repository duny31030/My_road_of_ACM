#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll a[100010];
	ll n,d,i,j;
	ll p = 0;
	scanf("%lld %lld",&n,&d);
	for(int i = 0;i < n;i++)
		scanf("%lld",&a[i]);
	for(i = 0;i < n-1;i++)
	{
		j = upper_bound(a,a+n,a[i]+d)-a;
		j--;
		p += (j-i-1)*(j-i)/2;
	}
	printf("%lld\n",p);
	return 0;
}


