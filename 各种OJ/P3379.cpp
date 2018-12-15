/*
 * =========================================================================
 *
 *       Filename:  P3379.cpp
 *
 *           Link:  https://www.luogu.org/problemnew/show/P3379
 *
 *        Version:  1.0
 *        Created:  2018/10/15 23时38分34秒
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
const int N = 500010;
int n,m,s,x,y;
struct node
{
    int to,next;
}e[2*N];
int deepth[N],head[N];
int fa[N][22];   
// fa[i][k]:节点i的上2^k层的祖先是哪个点
int lg[N];
// lg[i]:log(i)+1
int tot;

void add(int x,int y)
{
    e[++tot].to = y;
    e[tot].next = head[x];
    head[x] = tot;
}

// 记录各个点的深度和他们2^i级的祖先
void dfs(int f,int fath)   // f:当前节点 fath:f的父亲节点
{
    deepth[f] = deepth[fath]+1;
    fa[f][0] = fath;
    for(int i = 1;(1 << i) <= deepth[f];i++)
        fa[f][i] = fa[fa[f][i-1]][i-1];
    for(int i = head[f];i;i = e[i].next)
        if(e[i].to != fath)
            dfs(e[i].to,f);
}

// 倍增LCA
int lca(int x,int y)
{
    if(deepth[x] < deepth[y])   swap(x,y);      // 保证y的深度不大于x
    while(deepth[x] > deepth[y])
        x = fa[x][lg[deepth[x]-deepth[y]]-1];   // 先跳到同一深度
    if(x == y)
        return x;
    for(int k = lg[deepth[x]];k >= 0;k--)
        if(fa[x][k] != fa[y][k])
            x = fa[x][k],y = fa[y][k];
    return fa[x][0];    // x,y已经在LCA一下1深度,返回LCA
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif  
    s = 1;
    scanf("%d %d",&n,&m);
    for(int i = 1;i < n;i++)
    {
        scanf("%d %d",&x,&y);
        add(x,y);   add(y,x);
    }
    dfs(s,0);
    for(int i = 1;i <= n;i++)
        lg[i] = lg[i-1]+(1<<lg[i-1] == i);

    rep(i,1,m)
    {
        scanf("%d %d",&x,&y);
        printf("%d\n",lca(x,y));
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

