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

bool cmp(const char &a,const char &b)
{
	return a<b;
}


int main()
{
	char s[4];
	while(~scanf("%s",s))
	{
		getchar();
		sort(s,s+3,cmp);
		printf("%c %c %c\n",s[0],s[1],s[2]);
	}
	return 0;
}


