#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))

bool cmp(const ll &a,const ll &b)
{
	return a>b;
}

ll a[1000010],b[1000010],MAX,temp;

int main()
{
	ios::sync_with_stdio(false);
	ll m;
	int n,i;
	scanf("%d %lld",&n,&m);
	for(i = 0;i < n;i++)
		scanf("%lld",&a[i]);
	for(i = 0;i < n;i++)
		scanf("%lld",&b[i]);
	
	sort(a,a+n);
	sort(b,b+n,cmp);

	temp = 0,MAX = 0;
	for(i = 0;i < n;i++)
	{
		temp += b[i]-a[i];
		if((i+1)%3 == 0)
			temp += m;
		MAX = max(MAX,temp);
	}
	printf("%lld\n",MAX);
	return 0;
}


