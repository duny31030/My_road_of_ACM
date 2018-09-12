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
	int T;
	scanf("%d",&T);
	while(T--)
	{
		double x,a,y,b;
		scanf("%lf %lf %lf %lf",&x,&a,&y,&b);
		if((long long)(a*(double)log2(x)) == (long long)(b*(double)log2(y)))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	
	return 0;
}