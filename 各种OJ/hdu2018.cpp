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
	long long a[100] = {0};
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	a[4] = 4;
	for(int i = 5;i <= 55;i++)
	{
		a[i] = a[i-1]+a[i-3];
	}
	int n;
	while(cin >> n)
	{
		if(n == 0)
			break;

		cout << a[n] << endl;
	}
	return 0;
}


// 1 2 3 4 6 9  