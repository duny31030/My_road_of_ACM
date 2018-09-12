/*
 * =========================================================================
 *
 *       Filename:  C.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/03 12时09分26秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.github.io/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <iostream>
#include <queue>
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
const int MAXN = 1e6+10;
struct node 
{
    int from,to,w;
}e[MAXN];
int dis[MAXN],head[MAXN];
bool vis[MAXN];
int tot,k,a,b,c;

void add(int u,int v,int w)
{
    e[tot].to = v;
    e[tot].w = w;
    e[tot].from = head[u];
    head[u] = tot++;
}

void spfa()
{
    queue<int> q;
    vis[1] = 1;
    q.push(1);
    dis[1] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = head[u];i != -1;i = e[i].from)
        {
            int v = e[i].to;
            if(dis[v] > dis[u]+e[i].w)
            {
                dis[v] = dis[u]+e[i].w;
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
    tot = 1;
    clr(vis,0);
    clr(head,-1);
    fill(dis,dis+MAXN,INF);
    scanf("%d",&k);
    rep(i,0,k-1)
    {
        a = i;
        b = (i+1)%k;
        c = i*10%k;
        add(a,b,1);
        add(a,c,0);
    }
    spfa();
    printf("%d\n",dis[0]+1);
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

