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
	int s;
	while(~scanf("%d",&s))
	{
		int ss = s/10;
		if(s > 100 || s < 0)
		{
			printf("Score is error!\n");
			continue;
		}
		if(ss == 9 || ss == 10)
		{
			printf("A\n");
			continue;
		}
		if(ss == 8)
		{
			printf("B\n");
			continue;
		}
		if(ss == 7)
		{
			printf("C\n");
			continue;
		}
		if(ss == 6)
		{
			printf("D\n");
			continue;
		}
		else
		{
			printf("E\n");
			continue;
		}
	}
	
	return 0;
}


