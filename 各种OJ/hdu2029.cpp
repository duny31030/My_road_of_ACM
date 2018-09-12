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
	while(n--)
	{
		int flag = 1;
		char s1[1005],s2[1005];
		scanf("%s",s1);
		getchar();
		int len = strlen(s1);
		// cout << len << endl;
		for(int i = len-1;i >= 0;i--)
		{	
			// cout << i << " " << s1[i] << endl;
			s2[len-i-1] = s1[i];
		}
		// cout << s1 << endl;
		// cout << s2 << endl;
		for(int i = 0;i <= len/2;i++)
		{
			// cout << s1[i] << " " <<s2[len-i-1] << endl;
			if(s1[i] != s2[i])
			{
				flag = 0;
			}
		}
		if(flag == 1)
			cout << "yes" <<'\n';
		else
			cout << "no" << '\n';
	}
	
	return 0;
}


