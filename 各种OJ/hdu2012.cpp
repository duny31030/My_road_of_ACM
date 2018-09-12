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

bool check(int n)
{
	for(int i = 2;i < n;i++)
	{
		if(n%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int x,y;
	while(~scanf("%d %d",&x,&y))
	{
		if(x == 0 && y == 0)
			break;
		int temp,flag = 0;
		for(int i = x;i <= y;i++)
		{
			temp = i*i+i+41;
			if(check(temp))
			{

			}
			else
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			printf("Sorry\n");
		else
			printf("OK\n");
	}
	
	return 0;
}


