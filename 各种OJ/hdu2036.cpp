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
	while(scanf("%d",&n))
	{
		if(n == 0)
			break;
		int x[110] = {0};
		int y[110] = {0};
		for(int i = 1;i <= n;i++)
			scanf("%d %d",&x[i],&y[i]);

		double s = 0.0;
		for(int i = 1;i < n;i++)
		{
			s += 0.5*(x[1]*(y[i]-y[i+1])+x[i]*(y[i+1]-y[1])+x[i+1]*(y[1]-y[i]));
		}
		s = fabs(s);
		printf("%.1lf\n",s);
	}
	
	return 0;
}


