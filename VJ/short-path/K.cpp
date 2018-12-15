/*
 * =========================================================================
 *
 *       Filename:  K.cpp
 *
 *           Link:  http://poj.org/problem?id=3159
 *
 *        Version:  1.0
 *        Created:  2018/08/16 00时47分09秒
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
#include <string.h>
#include <iostream>
#include <stack>
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
const int MAXN = 30010;
bool vis[MAXN];
int head[MAXN];
int N,M,a,b,c,tot;
int dis[MAXN];
stack<int> q;
struct node
{
    int to,v,next;
}e[MAXN*5];

void add(int u,int v,int w)
{
    e[tot].to = v;
    e[tot].v = w;
    e[tot].next = head[u];
    head[u] = tot++;
}

void spfa()
{
    rep(i,1,N)
    {
        vis[i] = 0;
        dis[i] = INF;
    }
    q.push(1);
    vis[1] = 1;
    dis[1] = 0;
    while(!q.empty())
    {
        int u = q.top();
        q.pop();
        vis[u] = 0;
        for(int i = head[u];i != -1;i = e[i].next)
        {
            int v = e[i].to;
            if(dis[v] > dis[u]+e[i].v)
            {
                dis[v] = dis[u]+e[i].v;
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d",&N,&M);
    tot = 1;
    rep(i,1,N)
        head[i] = -1;
    rep(i,1,M)
    {
        scanf("%d %d %d",&a,&b,&c);
        add(a,b,c);
    }
    spfa();
    printf("%d\n",dis[N]);
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

