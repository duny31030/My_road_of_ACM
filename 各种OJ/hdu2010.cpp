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
	int m,n;
	while(scanf("%d %d",&m,&n) != EOF)
	{
		int flag = 0;
		for(int i = m;i <= n;i++)
		{
			int a,b,c;
			a = i/100;
			b = i%100/10;
			c = i%10;
			if(a*a*a+b*b*b+c*c*c == i)
			{
				if(flag == 0)
				{
					printf("%d",i);
					flag = 1;
				}
				else
					printf(" %d",i);
			}
		}
		if(flag == 0)
			printf("no");
		printf("\n");
	}
	
	return 0;
}


