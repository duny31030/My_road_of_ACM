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

int a[1000010];

int main()
{
	int d = 0;
	for(int i = 1;i <= 1000000;i++)
	{

		if(i>10)
		{
			if(i%10 == 4 || i/10%10 == 4 || i/100%10 == 4 || i/1000%10 == 4 || i/10000%10 == 4 || i/100000%10 == 4)
			{

			}
			else
			{	
				if(i%100 == 62 || i/10%100 == 62 || i/100%100 == 62 || i/1000%100 == 62 || i/10000%100 == 62)
				{

				}
				else
				{
					d++;
				}
			}
		}
		else
		{
			if(i == 4)
			{

			}
			else
			{
				d++;
			}
		}
		a[i] += d;
	}
	int s,e;
	while(scanf("%d %d",&s,&e))
	{
		if(s == 0 && e == 0)
			break;
		printf("%d\n",a[e]-a[s-1]);
	}
	return 0;
}


