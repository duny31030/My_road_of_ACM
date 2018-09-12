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
#include <cctype>

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
	scanf("%d",&n);
	getchar();
	while(n--)
	{	
		string s;
		getline(cin,s);
		// cout << s << endl;
		int flag = 1;
		if(isalpha(s[0])  || s[0] == '_')
		{
			for(int i = 0;i < s.size();i++)
			{
				if(isalnum(s[i]) == 0 && s[i] != '_')
				{
					flag = 0;
					// cout << "22" << endl;
					// continue;
					break;
				}
			}
		}
		else
		{
			flag = 0;
		}
		if(flag)
			printf("yes\n");
		else
			printf("no\n");

	}
	
	return 0;
}


