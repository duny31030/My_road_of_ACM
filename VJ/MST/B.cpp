/*
 * =========================================================================
 *
 *       Filename:  B.cpp
 *
 *           Link:  http://poj.org/problem?id=1287
 *
 *        Version:  1.0
 *        Created:  2018/09/26 15时38分15秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=n;i>=a;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 100;
int n,m,ev,eu,mmin,ans,tot,now,tmp;
int cost[N][N];
int v2[N];
bool v1[N];

void init()
{
    clr(v1,0);
    rep(i,0,n)
        rep(j,0,n)
        cost[i][j] = INF;
}

int prim()
{
    for(int i = 1;i <= n;i++)
        v2[i] = cost[1][i];
    v1[1] = 1;
    tot = 1;
    ans = 0;
    while(tot < n)
    {
        mmin = INF;
        tot++;
        for(int i = 1;i <= n;i++)
        {
            if(!v1[i] && v2[i] < mmin)
            {
                mmin = v2[i];
                now = i;
            }
        }
        ans += mmin;
        for(int i = 1;i <= n;i++)
        {
            if(v2[i] > cost[now][i] && !v1[i])
                v2[i] = cost[now][i];
        }
        v1[now] = 1;
    }
    return ans;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
            break;
        scanf("%d",&m);
        init();
        for(int i = 1;i <= m;i++)
        {
            scanf("%d %d %d",&eu,&ev,&tmp);
            if(cost[eu][ev] > tmp)
            {
                cost[eu][ev] = cost[ev][eu] = tmp;
            }
        }
        printf("%d\n",prim());
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

