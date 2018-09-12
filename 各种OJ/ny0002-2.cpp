#define _CRT_SBCURE_NO_DEPRECATE
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
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
	list<char> l;
	int n,flag,len;
	char s[10010];
	scanf("%d",&n);
	while(n--)
	{
		flag = 1;
		l.clear();
		scanf("%s",s);
		len = strlen(s);
		for(int i = 0;i < len;i++)
		{
			if(s[i] == '[')
			{
				l.push_back(s[i]);
			}
			if(s[i] == '(')
			{
				l.push_back(s[i]);
			}
			if(s[i] == ']')
			{	
				if(l.back() == '[')
				{
					l.pop_back();
				}
				else
				{
					flag = 0;
					continue;
				}
			}
			if(s[i] == ')')
			{
				if(l.back() == '(')
				{
					l.pop_back();
				}
				else
				{
					flag = 0;
					continue;
				}
			}
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}


