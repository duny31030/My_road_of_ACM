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
	int n,m;
	while(scanf("%d %d",&n,&m))
	{
		if(n == 0 && m == 0)
			break;
		int flag = 0;
		for(int i = -10000;i <= 10000;i++)
		{
			int j = n-i;
			if(i*j == m)
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';

	}
	
	return 0;
}


