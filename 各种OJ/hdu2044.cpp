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
	ll aa[52];
	aa[0] = 0;
	aa[1] = 1;
	aa[2] = 2;
	aa[3] = 3;

	for(int i = 4;i <= 50;i++)
	{
		aa[i] = aa[i-1]+aa[i-2];
		// cout << aa[i] << " ";
	}

	int n;
	cin >> n;
	int a,b;
	while(n--)
	{
		scanf("%d %d",&a,&b);
		printf("%lld\n",aa[b-a]);
	}
	
	return 0;
}


