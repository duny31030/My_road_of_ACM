/*
 * =========================================================================
 *
 *       Filename:  G.cpp
 *
 *           Link:  http://poj.org/problem?id=3259
 *
 *        Version:  1.0
 *        Created:  2018/08/15 17时04分51秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int MAXN = 5500;
int u[MAXN],v[MAXN],c[MAXN],dis[MAXN];
int T,N,M,W,a,b,cc,tot;

bool Bellman()
{
    // 初始化dis数组
    rep(i,1,M)
        dis[i] = INF;
    dis[1] = 0;

    rep(k,1,N-1)
    {
        bool bo = false;
        rep(i,1,tot-1)
        {
            if(dis[v[i]] > dis[u[i]]+c[i])
            {
                dis[v[i]] = dis[u[i]]+c[i];
                bo = true;
            }
        }
        if(!bo)
            return false;
    }
    rep(i,1,tot-1)
    {
        if(dis[v[i]] > dis[u[i]]+c[i])
            return true;
    }

    return false;
}


int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d",&T);
    while(T--)
    {
        tot = 1;
        scanf("%d %d %d",&N,&M,&W);
        // 读入边
        rep(i,1,M)
        {
            scanf("%d %d %d",&a,&b,&cc);
            u[tot] = a;
            v[tot] = b;
            c[tot] = cc;
            tot++;
            u[tot] = b;
            v[tot] = a;
            c[tot] = cc;
            tot++;
        }
        rep(i,1,W)
        {
            scanf("%d %d %d",&a,&b,&cc);
            u[tot] = a;
            v[tot] = b;
            c[tot] = -cc;
            tot++;
        }
        if(Bellman())
            printf("YES\n");
        else 
            printf("NO\n");
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

