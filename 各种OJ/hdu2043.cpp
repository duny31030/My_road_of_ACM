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
	cin >> n;
	char s[110];
	int len,flag1,flag2,a,b,c,d;
	while(n--)
	{
		flag1 = 1,flag2 = 0;
		a = b = c = d = 0;
		scanf("%s",s);
		len = strlen(s);
		if(len>16 || len<8)
		{
			flag1 = 0;
		}
		if(flag1)
		{
			for(int i = 0;i < len;i++)
			{
				if(s[i] >= 'a' && s[i] <= 'z' && a == 0)
				{
					a = 1;
					flag2++;
				}
				if(s[i] >= 'A' && s[i] <= 'Z' && b == 0)
				{
					b = 1;
					flag2++;
				}
				if(s[i] >= '0' && s[i] <= '9' && c == 0)
				{
					c = 1;
					flag2++;
				}
				if((s[i] == '~' || s[i] =='!' || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%' || s[i] == '^') && d == 0)
				{
					d = 1;
					flag2++;
				}
			}
			if(flag2 >= 3)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
		{
			printf("NO\n");
		}
		
	}
	
	return 0;
}


