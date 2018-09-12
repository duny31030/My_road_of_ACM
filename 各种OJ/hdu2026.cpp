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
	char s[110];
	while(gets(s))
	{
		int len = strlen(s);
		s[0] = s[0]-32;
		for(int i = 1;i < len;i++)
		{
			if(s[i] == ' ')
				s[i+1] = s[i+1]-32;
		}
		printf("%s\n",s);
	}
	return 0;
}


