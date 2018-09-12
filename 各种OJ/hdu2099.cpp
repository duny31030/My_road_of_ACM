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
	int a,b;
	while(cin >> a >> b)
	{
		if(a == 0 && b == 0)
			break;
		int flag = 0;
		for(int i = 0;i <= 99;i++)
		{
			
			if((a*100+i)%b == 0)
			{
				if(i < 10)
				{
					if(flag == 0)
					{
						printf("0%d",i);
						flag = 1;
					}
					else
					{
						printf(" 0%d",i);
					}
				}
				else
				{
					if(flag == 0)
					{
						printf("%d",i);
						flag = 1;
					}
					else
					{
						printf(" %d",i);
					}
				}
			}
		}
		printf("\n");	
	}
	
	return 0;
}


