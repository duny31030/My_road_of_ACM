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
	double a,b,t;
	while(scanf("%d",&n)!=EOF)
	{
		double p = 0.0;
		double temp = 0.0;
		scanf("%lf %lf",&a,&b);
		for(int i = 1;i <= n;i++)
		{
			scanf("%lf",&t);
			temp += 2*(n-i+1)*t;
		}
		
		printf("%.2f\n",(n*a+b-temp)/(n+1));
	}
	
	return 0;
}


