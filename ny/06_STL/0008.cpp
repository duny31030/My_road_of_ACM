#define _CRT_SBCURE_NO_DEPRECATE
// #include <set>
// #include <map>
// #include <cmath>
// #include <queue>
// #include <stack>
// #include <vector>
// #include <string>
#include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <iostream>
#include <algorithm>
// #include <functional>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int maxn = 110;
const int INF = 0x3f3f3f3f;

struct fa
{
	int b,c,k;
}f[1010];

bool cmp(struct fa a,struct fa b)
{
	if(a.b != b.b)
	{
		return a.b < b.b;
	}
	else
	{
		if(a.c != b.c)
		{
			return a.c < b.c;
		}
		else
		{
			return a.k < b.k;
		}
	}
}

int main()
{
	int n,m;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		for(int i = 0;i < m;i++)
		{
			scanf("%d %d %d",&f[i].b,&f[i].c,&f[i].k);
			if(f[i].c < f[i].k)
				swap(f[i].c,f[i].k);
		}
		sort(f,f+m,cmp);
		for(int i = 0;i < m;i++)
		{
			if(i == 0)
			{
				printf("%d %d %d\n",f[i].b,f[i].c,f[i].k);
			}
			else
			{
				if(f[i].b == f[i-1].b && f[i].c == f[i-1].c && f[i].k == f[i-1].k)
					continue;
				else
				{
					printf("%d %d %d\n",f[i].b,f[i].c,f[i].k);
				}
			}
		}

	}
	
	return 0;
}


