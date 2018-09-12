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
	int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int y,m,d;
	while(~scanf("%d/%d/%d",&y,&m,&d))
	{
		int p = 0;
		if(((y %4 == 0 && y % 100 != 0) || (y %400 == 0)) && (m > 2))
			p += 1;
		for(int i = 1;i < m;i++)
			p += mon[i];
		p += d;
		printf("%d\n",p);
	}
	
	return 0;
}


