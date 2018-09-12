#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define max3(a,b,c) fmax(a,fmax(b,c))

int n;
long long m,a[1000010],b[1000010];

bool cmp(const LL &a,const LL &b)
{
    return a>b;
}


int main()
{
	ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
	int i;
	scanf("%d %lld",&n,&m);
	for(i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i = 1;i <= n;i++)
	{
		scanf("%lld",&b[i]);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1,cmp);
	
	int step = 0;
	int flag = 0;
	long long pri = 0;
	for(i = 1;i <= n;i++)
	{
		if(a[i] <= b[i])
		{
			pri -= a[i];
			pri += b[i];
			step++;
		}
		else
		{
			flag = i;
			break;
		}
	}



	// ~~~~~~~~~~
	int xx = step/3;
	pri += xx*m;
	// int step2 = step%3;
	i = flag;
	long long tteem = 0;
	for(;i <= (xx+1)*3;i++)
	{
		tteem -= a[i];
		tteem += b[i];
	}
	tteem += m;
	if(tteem > 0)
		pri += tteem;

	while(i < n-2)
	{
		long long tmp = m+b[i]+b[i+1]+b[i+2]-a[i]-a[i+1]-a[i+2];
		if(tmp > 0)
		{
			pri += tmp;
		}
		i += 3;
	}
	for(;i <= n;)
	{
		long long tmp = b[i]+b[i+1]+b[i+2]-a[i]-a[i+1]-a[i+2];
		if(tmp > 0)
		{
			pri += tmp;
		}
		i += 3;
	}
	
	printf("%lld\n",pri);

	return 0;
}


