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
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		int temp;
		int line,row;
		int mmin = 0;
		for(int i = 1;i <= m;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				cin >> temp;
				if(abs(temp) > abs(mmin))
				{
					mmin = temp;
					line = i;
					row = j;
				}
			}
		}
		cout << line << " " << row << " " << mmin << endl;
	}
	
	return 0;
}


