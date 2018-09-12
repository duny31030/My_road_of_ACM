#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int mod = 998244353;

bool cmp(const int &a,const int &b)
{
	return a>b;
}

ll po(ll a,ll i)
{
	if(i == 0)
		return 1;
	int temp = po(a,i>>1);
	temp = temp*temp%mod;
	if(i & 1)
		temp = (ll)temp*a%mod;
	return temp%mod;
}

int main()
{
	ll n,p;
	scanf("%lld",&n);
	p = po(n,n+1);
	printf("%lld\n",p%mod);
	
	return 0;
}


