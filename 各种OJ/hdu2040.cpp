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
	int a,b,temp;
	while(n--)
	{
		int flag = 1;
		scanf("%d %d",&a,&b);
		// printf("%d %d\n",a,b);
		temp = 1;
		for(int i = 2;i <= a/2;i++)
		{
			if(a%i == 0)
				temp += i;
		}
		// printf("%d\n",temp);
		if(temp != b)
		{
			flag = 0;
			// printf("1\n");
		}
		temp = 1;
		for(int i = 2;i <= b/2;i++)
		{
			if(b%i == 0)
				temp += i;
		}
		// printf("%d\n",temp);
		if(temp != a)
		{
			flag = 0;
			// printf("2\n");
		}
		if(flag == 0)
			printf("NO\n");
		else
			printf("YES\n");
	}	
	return 0;
}


