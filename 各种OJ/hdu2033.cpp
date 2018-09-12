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
	scanf("%d",&n);
	while(n--)
	{
		int ah,am,as,bh,bm,bs;
		scanf("%d %d %d %d %d %d",&ah,&am,&as,&bh,&bm,&bs);
		int a = 0,b = 0;
		a = ((ah*60)+am)*60+as;
		// printf("a = %d\n",a);
		b = ((bh*60)+bm)*60+bs;
		// printf("b = %d\n",b);
		a = a+b;
		as = a%60;
		a /= 60;
		am = a%60;
		a /= 60;
		ah = a;
		printf("%d %d %d\n",ah,am,as);
	}
	
	return 0;
}


