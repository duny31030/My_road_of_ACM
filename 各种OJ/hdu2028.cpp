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

int gcd(int a,int b)
{
	return b == 0 ? a : gcd(b,a%b);
}


int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,m,temp = 0,ans = 1;
		for(i = 0;i < n;i++)
		{
			cin >> m;
			temp = gcd(ans,m);
			ans = ans/temp*m;
		}
		cout << ans << '\n';
	}
	return 0;
}


