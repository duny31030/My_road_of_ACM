/*
 * =========================================================================
 *
 *       Filename:  code2370.cpp
 *
 *           Link:  http://codevs.cn/problem/2370/
 *
 *        Version:  1.0
 *        Created:  2018/10/16 16时43分15秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <bits/stdc++.h>
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
const int N = 1e5+100;
int n,m,x,y,w;
struct node
{
    int to,next,w;
}edge[2*N];
ll dis[N];
int head[N],deepth[N],lg[N],fa[N][20];
int tot;

void add(int x,int y,int w)
{
    edge[++tot].to = y;
    edge[tot].next = head[x];
    edge[tot].w = w;
    head[x] = tot;
}

void dfs(int f,int fath,int d)
{
    deepth[f] = deepth[fath]+1;
    fa[f][0] = fath;
    dis[f] = d;
    for(int i = 1;(1<<i) <= deepth[f];i++)
        fa[f][i] = fa[fa[f][i-1]][i-1];
    for(int i = head[f];i;i = edge[i].next)
        if(edge[i].to != fath)
            dfs(edge[i].to,f,d+edge[i].w);
}

int lca(int x,int y)
{
    if(deepth[x] < deepth[y])   swap(x,y);
    while(deepth[x] > deepth[y])
        x = fa[x][lg[deepth[x]-deepth[y]]-1];
    if(x == y)
        return x;
    for(int k = lg[deepth[x]];k >= 0;k--)
        if(fa[x][k] != fa[y][k])
            x = fa[x][k],y = fa[y][k];
    return fa[x][0];
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d",&n);
    for(int i = 1;i < n;i++)
    {
        scanf("%d %d %d",&x,&y,&w);
        add(x+1,y+1,w); add(y+1,x+1,w);
    }
    dfs(1,0,0);
    rep(i,1,n)  lg[i] = lg[i-1]+(1<<lg[i-1]==i);
    scanf("%d",&m);
    rep(i,1,m)
    {
        scanf("%d %d",&x,&y);
        printf("%lld\n",dis[x+1]+dis[y+1]-2*dis[lca(x+1,y+1)]);
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

