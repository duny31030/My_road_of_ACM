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
	int n;
	while(cin >> n)
	{
		if(n == 0)
			break;
		int p = 0;
		int temp = 0;
		for(int i = 1;i <= n;i++)
		{
			cin >> temp;
			while(temp)
			{
				if(temp >= 100)
				{
					p += temp/100;
					temp -= temp/100*100;
				}
				if(temp >= 50)
				{
					p += temp/50;
					temp -= temp/50*50;
				}
				if(temp >= 10)
				{
					p += temp/10;
					temp -= temp/10*10;
				}
				if(temp >= 5)
				{
					p += temp/5;
					temp -= temp/5*5;
				}
				if(temp >= 2)
				{
					p += temp/2;
					temp -= temp/2*2;
				}
				if(temp >= 1)
				{
					p += temp/1;
					temp -= temp/1*1;
				}
			}
		}
		cout << p << endl;
	}
	
	return 0;
}


