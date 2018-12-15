/*
 * =========================================================================
 *
 *       Filename:  P3377.cpp
 *
 *           Link:  https://www.luogu.org/problemnew/show/P3377
 *
 *        Version:  1.0
 *        Created:  2018/10/29 18时03分09秒
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
int n,m,tmp,x,y;
int f[N],ht[N];
struct node
{
    ll w;
    int l,r;
}h[N];

int find(int x)
{
    while(f[x]) x = f[x];
    return x;
}

int merge(int x,int y)
{
    if(!x || !y)    return x+y;
    if(h[x].w > h[y].w || (h[x].w == h[y].w && x > y))
        swap(x,y);
    h[x].r = merge(h[x].r,y);
    f[h[x].r] = x;
    if(ht[h[x].l] < ht[h[x].r]) swap(h[x].l,h[x].r);
    ht[x] = ht[h[x].r]+1;
    return x;
}

void pop(int x)
{
    h[x].w = -1;    f[h[x].l] = f[h[x].r] = 0;
    merge(h[x].l,h[x].r);
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    ht[0] = 0;
    scanf("%d %d",&n,&m);
    rep(i,1,n)
    {
        scanf("%lld",&h[i].w);
    }
    rep(i,1,m)
    {
        scanf("%d",&tmp);
        if(tmp == 1)
        {
            scanf("%d %d",&x,&y);
            if(h[x].w == -1 || h[y].w == -1)    continue;
            x = find(x);    y = find(y);
            if(x == y)  continue;
            merge(x,y);
        }
        else 
        {
            scanf("%d",&x);
            if(h[x].w == -1)    
                printf("-1\n");
            else 
            {
                x = find(x);
                printf("%lld\n",h[x].w);
                pop(x);
            }
        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

