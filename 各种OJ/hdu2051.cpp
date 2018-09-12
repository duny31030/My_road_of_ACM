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
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a[100];
		int len = 0;
		while(n)
		{
			a[len++] = n%2;
			n /= 2;
		}
		for(int i = len-1;i >= 0;i--)
			printf("%d",a[i]);
		printf("\n");
	}
	
	return 0;
}


