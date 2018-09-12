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
	int n,temp;
	while(cin >> n)
	{
		if(n == 0)
			break;
		temp = n;
		int t = 0,f = 0,flag = 0;
		while(temp)
		{
			f += temp%10;
			temp /= 10;
		}
		temp = n;
		while(temp)
		{
			t += temp%12;
			temp /= 12;
		}
		if(t != f)
		{
			flag = 1;
		}
		t = 0;
		temp = n;
		while(temp)
		{
			t += temp%16;
			temp /= 16;
		}
		if(t != f)
		{
			flag = 1;
		}
		if(flag == 0)
		{
			printf("%d is a Sky Number.\n",n);
		}
		else
		{
			printf("%d is not a Sky Number.\n",n);
		}
	}
	
	return 0;
}


