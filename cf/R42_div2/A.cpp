#define _CRT_SBCURE_NO_DEPRECATE
#include <set>
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
	scanf("%d",&n);
	int a[200010];
	ll sum = 0,equ = 0;
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	int flag = 0;
	for(int i = 0; ;i++)
	{
		if(equ*2 >= sum)
		{
			flag = i;
			break;
		}
		else
		{
			equ += a[i]; 
		}
	}

	printf("%d\n",flag);
	
	return 0;
}


