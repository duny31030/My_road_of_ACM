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
	int N,R;
	
	while(scanf("%d %d",&N,&R) != EOF)
	{
		char p[10100];
		int len = 0;
		int flag = 0;
		if(N < 0)
		{
			flag = 1;
			N = -N;
		}
		while(N)
		{
			int temp = N%R;
			N /= R;
			switch(temp)
			{
				case 0: p[len++] = '0';	break;
				case 1:	p[len++] = '1';	break;
				case 2:	p[len++] = '2';	break;
				case 3:	p[len++] = '3';	break;
				case 4:	p[len++] = '4';	break;
				case 5:	p[len++] = '5';	break;
				case 6:	p[len++] = '6';	break;
				case 7:	p[len++] = '7';	break;
				case 8:	p[len++] = '8';	break;
				case 9:	p[len++] = '9';	break;
				case 10:	p[len++] = 'A';	break;
				case 11:	p[len++] = 'B';	break;
				case 12:	p[len++] = 'C';	break;
				case 13:	p[len++] = 'D';	break;
				case 14:	p[len++] = 'E';	break;
				case 15:	p[len++] = 'F';	break;
			}
		}	
		if(flag)
			printf("-");
		for(int i = len-1;i >= 0;i--)
			printf("%c",p[i]);
		cout << '\n';
	}
	
	return 0;
}


