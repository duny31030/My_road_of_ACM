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
	double a,b,c;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf %lf %lf",&a,&b,&c);
		if(a <= 0 || b <= 0 || c <= 0)
		{
			printf("NO\n");
		}
		else
		{
			if(a+b>c && a+c>b && b+c>a)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
		
	}
	
	return 0;
}


