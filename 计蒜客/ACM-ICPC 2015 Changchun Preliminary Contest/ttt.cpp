#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <string>
#include <ctime>
#include <list>
#include <bitset>
using namespace std;
typedef unsigned char byte;
#define pb push_back
#define input_fast std::ios::sync_with_stdio(false);std::cin.tie(0)
#define pi acos(-1)

using namespace std;
const int maxn = 150000 + 500;
typedef pair<int,int>dl;
struct node
{
    int val;
    int idx;
    friend bool operator < (const node & a,const node & b)
    {
        return a.val < b.val || (a.val == b.val && a.idx > b.idx);
    }    
    node(int val,int idx) : val(val) , idx(idx) {}
};

priority_queue<node>qq;
int k , m , q , Time[maxn];
int v[maxn];
char ks[maxn][400];
dl tt[maxn];
int id[maxn];

void initiation()
{
   scanf("%d%d%d",&k,&m,&q);
   for(int i = 1 ; i <= k ; ++ i) scanf("%s%d",ks[i],&v[i]);
   for(int i = 1 ; i <= m ; ++ i) scanf("%d%d",&tt[i].first,&tt[i].second);
   sort(tt + 1 , tt + 1 + m);
   for(int i =1;i <= m;i++)
       printf("%d %d\n",tt[i].first,tt[i].second);
   for(int i = 1 ; i <= q; ++ i) scanf("%d",&id[i]);
}


void solve()
{
    int ptr = 1;
    int cot = 0;
    int T = 1;
    for(int i = 1 ; i <= k ; ++ i)
    {
        cot++;
        qq.push(node(v[i],i));
        while(ptr != m+1 && tt[ptr].first <= cot)
        {
            int cv = tt[ptr].second;
            while(cv && !qq.empty())
            {
                node ss = qq.top();qq.pop();
                Time[T++] = ss.idx;
                cv--;
            }
            ptr++;
        }
    }
    while(!qq.empty())
    {
        node ss = qq.top();qq.pop();
        Time[T++] = ss.idx;
    }
    printf("%s",ks[Time[id[1]]]);
    for(int i = 2 ; i <= q ; ++ i) printf(" %s",ks[Time[id[i]]]);
    printf("\n");
}


int main()
{
        freopen("in.txt","r",stdin);
    int Case;
    scanf("%d",&Case);
    while(Case--)
    {
        initiation();
        solve();
    }
        fclose(stdin);
    // fclose(stdout);
    return 0;
}
