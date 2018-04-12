#include <bits/stdc++.h>

using namespace std;

#define ll long long
priority_queue < ll,vector<ll>,greater<ll> >que;
int main()
{

	int t;
	scanf("%d",&t);
	while(t--)
	{
		while(!que.empty())
			que.pop();
		ll n,i;
		scanf("%lld",&n);
		for(i = 0;i < n;i++)
		{
			ll k;
			scanf("%lld",&k);
			que.push(k);
		}
		ll ans = 0;
		for(i = 0;i < n-1;i++)
		{
			ll sum = 0;
			sum += que.top();
			que.pop();
			sum += que.top();
			que.pop();
			ans += sum;
			que.push(sum);
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}


