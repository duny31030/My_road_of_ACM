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
	return abs(a)>abs(b);
}


int main()
{
	int n;
	while(cin >> n)
	{
		if(n == 0)
			break;
		int a[105];
		for(int i = 1;i <= n;i++)
			cin >> a[i];
		sort(a+1,a+n+1,cmp);
		for(int i = 1;i < n;i++)
			cout << a[i] << " ";
		cout << a[n] << endl;
	}
	
	return 0;
}


