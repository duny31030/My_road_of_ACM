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
	int mmax = -999,mmin = 999;
	int n,ans = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(mmax < temp)
			mmax = temp;
		if(mmin > temp)
			mmin = temp;
		ans += 2;
	}
	printf("mmax = %d mmin = %d\n",mmax,mmin);
	printf("比较次数为%d次\n",ans);
	return 0;
}


