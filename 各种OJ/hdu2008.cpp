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
	while(scanf("%d",&n) && n)
	{
		double temp;
		int l = 0,d = 0,x = 0;
		for(int i = 1;i <= n;i++)
		{
			scanf("%lf",&temp);
			if((temp-0 <= 0.000001) && (0-temp <= 0.000001))
				l++;
			if(temp > 0)
				d++;
			if(temp < 0)
				x++;
		}
		printf("%d %d %d\n",x,l,d);
	}
	
	return 0;
}


