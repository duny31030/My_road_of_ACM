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
	int n,a1,b1,c1;
	double pr;
	cin >> n;
	while(n--)
	{
		pr = 0.0;
		scanf("%d %d %d",&a1,&b1,&c1);
		if(a1 > 12)
		{
			a1 -= 12;
		}
		pr = ((a1+b1*1.0/60+c1*1.0/3600)*30-(b1+c1*1.0/60)*6);
		// printf("%.0lf\n",pr);
		pr = fabs(pr);
		// printf("%.0lf\n",pr);
		if(pr > 180)
		{
			pr = 360-pr;
		}
		printf("%d\n",(int)pr);
	}
	
	return 0;
}


