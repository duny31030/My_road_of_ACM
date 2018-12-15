/*
 * =========================================================================
 *
 *       Filename:  F.cpp
 *
 *           Link:  http://poj.org/problem?id=1860
 *
 *        Version:  1.0
 *        Created:  2018/08/13 14时23分31秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
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
const int MAXN = 220;
double dis[MAXN];
int u[MAXN],v[MAXN];
double r[MAXN],c[MAXN];
int N,M,S,tot,a,b;
double V,cc,d,e,f;

bool Bellman_Ford()
{
    // 初始化dis数组
    rep(i,1,N)
        dis[i] = 0;
    dis[S] = V;
    
    rep(k,1,N-1)
    {
        bool bo = false;
        rep(i,1,tot-1)
        {
            if(dis[v[i]] < (dis[u[i]]-c[i])*r[i])
            {
                dis[v[i]] = (dis[u[i]]-c[i])*r[i];
                bo = true;
            }
        }
        if(!bo)
            return false;
    }
    rep(i,1,tot-1)
        if(dis[v[i]] < (dis[u[i]]-c[i])*r[i])
            return true;
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
    while(scanf("%d %d %d %lf",&N,&M,&S,&V) != EOF)
    {
        tot = 1;
        // 读入边
        rep(i,1,M)
        {
            scanf("%d %d %lf %lf %lf %lf",&a,&b,&cc,&d,&e,&f);
            u[tot] = a;
            v[tot] = b;
            r[tot] = cc;
            c[tot] = d;
            ++tot;
            u[tot] = b;
            v[tot] = a;
            r[tot] = e;
            c[tot] = f;
            ++tot;
        }
        if(Bellman_Ford())
            printf("YES\n");
        else 
            printf("NO\n");
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

