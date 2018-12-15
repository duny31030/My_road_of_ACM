/*
 * =========================================================================
 *
 *       Filename:  P1552.cpp
 *
 *           Link:  https://www.luogu.org/problemnew/show/P1552
 *
 *        Version:  1.0
 *        Created:  2018/10/29 12时35分18秒
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
struct node
{
    int next,to;
}e[N];
struct heap
{
    ll w;
    int l,r;
}h[N];
int head[N];
int rt[N],sz[N];
int n,q,cnt,j;
ll c[N],l[N],s[N],m,ans;

void addedge(int x,int y)
{
    e[++cnt] = (node){head[x],y};
    head[x] = cnt;
}

int merge(int x,int y)
{
    if(!x || !y)    return x+y;
    if(h[x].w < h[y].w) swap(x,y);
    h[x].r = merge(h[x].r,y);
    swap(h[x].l,h[x].r);
    return x;
}

int pop(int x)
{
    return merge(h[x].l,h[x].r);
}

void dfs(int u)
{
    rt[u] = ++cnt;
    h[cnt].w = c[u];
    s[u] = c[u];    sz[u] = 1;
    for(int i = head[u];i;i = e[i].next)
    {
        dfs(e[i].to);
        s[u] += s[e[i].to];
        sz[u] += sz[e[i].to];
        rt[u] = merge(rt[u],rt[e[i].to]);
    }
    while(s[u] > q)
    {
        s[u] -= h[rt[u]].w;
        rt[u] = pop(rt[u]);
        --sz[u];
    }
    ans = max(ans,(ll)(sz[u]*l[u]));
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d",&n,&q);
    rep(i,1,n)
    {
        scanf("%d %lld %lld",&j,&c[i],&l[i]);
        if(j)   addedge(j,i);
        else 
            rt[0] = i;
    }
    cnt = 0;
    dfs(rt[0]);
    printf("%lld\n",ans);
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

