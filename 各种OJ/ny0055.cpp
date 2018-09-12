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

struct cmp1{
    bool operator ()(int &a,int &b){
        return a>b;//最小值优先
    }
};

int main()
{
	priority_queue<int,vector<int>,cmp1> q;
	int N,n,temp;
	ll p;
	scanf("%d",&N);
	while(N--)
	{
		p = 0;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&temp);
			q.push(temp);
		}
		while(q.size() >= 2)
		{
			temp = 0;
			temp += q.top();
			q.pop();
			temp += q.top();
			q.pop();
			q.push(temp);
			p += temp;
			temp = 0;
		}
		//p += q.top();
		while(!q.empty())
		{
			q.pop();
		}
		printf("%lld\n",p);
	}
	
	return 0;
}


