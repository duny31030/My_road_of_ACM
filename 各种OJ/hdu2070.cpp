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
	ll f[52];
	f[0] = 0;
	f[1] = 1;
	f[2] = 1;
	f[3] = 2;
	for(int i = 4;i <= 50;i++)
		f[i] = f[i-1]+f[i-2];
	int n;
	while(cin >> n)
	{
		if(n == -1)
			break;
		printf("%lld\n",f[n]);
	}
	
	return 0;
}


