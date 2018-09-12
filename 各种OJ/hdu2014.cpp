#define _CRT_SBCURE_NO_DEPRECATE
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int maxn = 110;
const int INF = 0x3f3f3f3f;

bool cmp(const int &a,const int &b)
{
	return a>b;
}


int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int p = 0,temp;
		int mmax = -100;
		int mmin = 999;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&temp);
			if(mmax < temp)
				mmax = temp;
			if(mmin > temp)
				mmin = temp;
			p += temp;
		}
		double pp = ((p-mmax-mmin)*1.0)/(n-2);
		printf("%.2f\n",pp);
	}
	
	return 0;
}


