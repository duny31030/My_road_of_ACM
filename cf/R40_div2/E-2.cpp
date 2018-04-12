#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fi first
#define se second


bool cmp(const int &a,const int &b)
{
  return a>b;
}


pair<ll,double> t[200005];
int n,T;

bool check(double flow)
{
	double x;
	double Max = 0,Taken = 0;
	for(int i = n;i >= 1;i--)
	{
		x = min(flow-Taken,t[i].se);
		Max += t[i].fi*x;
		Taken += x;
	}
	double Min = 0;
	Taken = 0;
	for(int i = 1;i <= n;i++)
	{
		x = min(flow-Taken,t[i].se);
		Min += t[i].fi*x;
		Taken += x;
	}
	return (Min <= T*flow && T*flow <= Max);
}





int main()
{
	scanf("%d %d",&n,&T);
	double lo = 0;
	double hi = 0;

	for(int i = 1;i <= n;i++)	
	{
		scanf("%lf",&t[i].se);
		hi += t[i].se;
	}
  	for(int i = 1;i <= n;i++)
  	{
  		scanf("%lld",&t[i].fi);
  	}

  	sort(t+1,t+n+1);

  	// for(int i = 1;i <= n;i++)
  	// {
  	// 	printf("%lld %.4lf\n",t[i].fi,t[i].se);
  	// }
  	for(int i = 1;i <= 200;i++)
  	{
  		double mid = (lo+hi)/2;
  		if(check(mid))
  			lo = mid;
  		else
  			hi = mid;
  	}
  	printf("%.10lf\n",lo);
  return 0;
}


