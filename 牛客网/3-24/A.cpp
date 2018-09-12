#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main()
{
	long long sum = 0;
	long long num[40]={0};
	for(int i = 0;i < 30;i++)
	{
		sum += num[i];
		num[i+1] = sum + 1;
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n",num[n]);
	}
	return 0;
}


