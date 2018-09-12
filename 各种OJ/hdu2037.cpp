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


struct node
{
	int s,e;
}a[110],t;

int main()
{
	int n;
	while(scanf("%d",&n))
	{
		if(n == 0)
			break;
		for(int i = 0;i < n;i++)
		{
			scanf("%d %d",&a[i].s,&a[i].e);
		}
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < i;j++)
			{
				if(a[i].e < a[j].e)
				{
					t = a[i];
					a[i] = a[j];
					a[j] = t;
				}
			}
		}
		// for(int i = 0;i < n;i++)
		// {
		// 	printf("%d %d\n",a[i].s,a[i].e);
		// }
		int p = 1;
		int end = a[0].e;
		for(int i = 1;i < n;i++)
		{
			if(a[i].s >= end)
			{
				end = a[i].e;
				p++;
			}
		}
		printf("%d\n",p);
	}
	
	return 0;
}


