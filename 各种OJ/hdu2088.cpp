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
	int a[55];
	int n;
	int flag = 0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n == 0)
			break;
		if(flag != 0)
		{
			printf("\n");
		}
		flag++;
		int sum = 0;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		int ave = sum/n;
		int p = 0;
		for(int i = 1;i <= n;i++)
		{
			p += abs(a[i]-ave);
		}
		printf("%d\n",p/2);
	}
	
	return 0;
}


