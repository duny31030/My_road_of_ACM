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
	ios
	int n,m;
	while(cin >> n >> m)
	{
		int flag = 0;
	if(n%m == 0)
	{
		for(int i = 1;i <= n;i+=m)
		{
			int sum = 0;
			for(int j = 0;j < m;j++)
			{
				sum += i*2+j*2;
			}
			if(flag == 0)
			{
				cout << sum/m;
				flag = 1;
			}
			else
			{
				cout << " " << sum/m;
			}
		}
		cout << endl;
	}
	else
	{
		for(int i = 1;i < n;i+=m)
		{
			int sum = 0;
			for(int j = 0;j < m;j++)
			{
				sum += i*2+j*2;
			}
			if(flag == 0)
			{
				cout << sum/m;
				flag = 1;
			}
			else
			{
				cout << " " << sum/m;
			}
			// cout << "111" << endl;
		}
		int ssum = 0;
		for(int i = 1;i <= n%m;i++)
		{
			ssum += (i+n/m*m)*2;
		}
		cout << " " << ssum/(n%m);
		cout << endl;
	}
	}
	
	
	return 0;
}


