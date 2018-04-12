#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll mod = 998244353;

ll quickpow(ll a,ll b,ll p)
{
	ll ret = 1;
	while(b)
	{
		if(b & 1)
			ret = (ret*a)%p;
		a = (a*a)%p;
		b >>= 1;
	}
	return ret;
}

// ll fermat(ll a,ll p)   // 费马求a关于b的逆元
// {
// 	return quickpow(a,p-2,p);
// }


int main()
{
	ll n,m;
	scanf("%lld %lld",&n,&m);
	ll c = n*n;
	ll ans = (c-m)*quickpow(c,mod-2,mod)%mod;
	printf("%lld\n",ans);
	return 0;
}


