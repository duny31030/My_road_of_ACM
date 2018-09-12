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
	int n,t,temp,p,mmax;
	scanf("%d",&n);
	while(n--)
	{
		mmax = -1;
		map<int,int> m;
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d",&temp);
			m[temp]++;
		}
		/*
		*bool mycmp(const pair<int,int> p1, const pair<int,int> p2)
		*{
		*    return p1.second < p2.second ;
		*}
		*
		*map<int,int>::iterator i=max_element(m.begin(), m.end(),mycmp);
		*cout << i->first << " " << i->second << endl ;
		*/




		map<int,int>::iterator it;
		for(it = m.begin();it != m.end();it++)
		{
			if(it ->second > mmax)
			{
				p = it -> first;
				mmax = it -> second;
			}
		}
		printf("%d %d\n",p,mmax);
	}
	
	return 0;
}


