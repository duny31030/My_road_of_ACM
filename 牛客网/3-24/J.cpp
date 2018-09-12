#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool cmp(const int &a,const int &b)
{
	return a>b;
}


int main()
{
	ll T,i,a[100010];
	scanf("%lld",&T);
	while(T--)
	{
		memset(a,0,sizeof a);
		ll n;
		scanf("%lld",&n);
		for(i = 0;i < n;i++)
		{
			scanf("%lld",&a[i]);
		}
		ll ans = 0;
		sort(a,a+n);
		for(i = 1;i < n;i++)
		{
			ll t = a[i]+ans-a[0];
			a[0] += t;
			ans += t;
		}
		printf("%lld %lld\n",ans,a[0]);

	}
	
	return 0;
}


