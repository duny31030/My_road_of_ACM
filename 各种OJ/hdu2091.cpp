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
	char x;
	int n,i,j,k;
	int flag = 0;
	while(scanf("%c",&x))
	{
		if(x == '@')
			break;
		// if(flag != 0)
		// 	cout << '\n';
		// flag++;
		n = 1;
		int j = 1;
		scanf("%d",&n);
		getchar();
		if(flag)
				cout << '\n';
		for(i = 1;i < n;i++)
		{
			cout << string(n-i,' ');
			// for(j = n;j > i;j--)
			// 	printf(" ");
			cout << x << string(i-j,' ');
			// printf("%c",x);
			// for(k = 1;k < i*2-2;k++)
			// {
			// 	printf(" ");
			// 	if(k == i*2-3)
			// 		printf("%c",x);
			// }
			// printf("\n");
			if(i > 1)
			{
				cout << x;
				j--;
			}
			cout << endl;
			// if(i == n-1)
			// {
			// 	for(i = 1;i <= (n*2-1);i++)
			// 		printf("%c",x);
			// 	printf("\n");
			// }
			
		}
		cout << string(2*n-1,x) << endl;
		flag = 1;
		// getchar();
	}
	
	return 0;
}


