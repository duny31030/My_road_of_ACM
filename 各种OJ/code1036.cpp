/*
 * =========================================================================
 *
 *       Filename:  code1036.cpp
 *
 *           Link:  http://codevs.cn/problem/1036/
 *
 *        Version:  1.0
 *        Created:  2018/10/16 17时05分27秒
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
int n,m,x,y,w,tot;
struct node
{
    int to,next;
}edge[2*N];
int head[N],deepth[N],lg[N],fa[N][20];
void add(int x,int y)
{
    edge[++tot].to = y;
    edge[tot].next = head[x];
    head[x] = tot;
}

void dfs(int f,int fath)
{
    deepth[f] = deepth[fath]+1;
    fa[f][0] = fath;
    for(int i = 1;(1<<i) <= deepth[f];i++)
        fa[f][i] = fa[fa[f][i-1]][i-1];
    for(int i = head[f];i;i = edge[i].next)
        if(edge[i].to != fath)
            dfs(edge[i].to,f);
}

int lca(int x,int y)
{
    if(deepth[x] < deepth[y])   swap(x,y);
    while(deepth[x] > deepth[y])
        x = fa[x][lg[deepth[x]-deepth[y]]-1];
    if(x == y)  return x;
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
    ll ans = 0;
    scanf("%d",&n);
    for(int i = 1;i < n;i++)
    {
        scanf("%d %d",&x,&y);
        add(x,y);   add(y,x);
    }
    dfs(1,0);   
    rep(i,1,n)  lg[i] = lg[i-1]+(1<<lg[i-1]==i);
    scanf("%d",&m);
    x = 1;
    rep(i,1,m)
    {
        scanf("%d",&y);
        ans += 1ll*deepth[x]+1ll*deepth[y]-2ll*deepth[lca(x,y)];
        x = y;
    }
    printf("%lld\n",ans);
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

