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
	char s[105];
	
	while(scanf("%s",s)!=EOF)
	{
		char x = ('a'-1);
		int len = strlen(s);
		for(int i = 0;i < len;i++)
		{
			if(x < s[i])
				x = s[i];
		}
		for(int i = 0;i < len;i++)
		{
			if(s[i] == x)
			{
				printf("%c(max)",s[i]);
			}
			else
			{
				printf("%c",s[i]);
			}
		}
		printf("\n");
	}
	
	return 0;
}


