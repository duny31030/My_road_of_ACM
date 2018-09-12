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
	int mmin = 999;
	int t,n,m,temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&temp);
			mmin = min(temp,mmin);
		}
		printf("%d\n",(100-mmin)*(100-mmin));
	}
	
	return 0;
}


