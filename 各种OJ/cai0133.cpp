/*
 * =========================================================================
 *
 *       Filename:  cai0133.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/08 12时19分27秒
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
const int N = 5555;
ll tree[N][N];
ll aa[N][N];
ll n,m,t,a,b,c,d;

void add(ll x,ll y,ll z)
{
    ll memo_y = y;
    while(x <= n)
    {
        y = memo_y;
        while(y <= m)
        	tree[x][y] += z,y += y&(-y);
        x += x&(-x);
    }
}
// 求左上角为(1,1)右下角为(x,y)的矩阵和
ll ask(ll x,ll y)
{
    ll res = 0,memo_y = y;
    while(x)
    {
        y = memo_y;
        while(y)
            res += tree[x][y],y -= y&(-y);
        x -= x&(-x);
    }
    return res;
}

ll range_ask(ll xa, ll ya, ll xb, ll yb)
{
    return ask(xb,yb) - ask(xb,ya - 1) - ask(xa - 1,yb) + ask(xa - 1,ya - 1);
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("1.in.txt","r",stdin);
    freopen("1.out.txt","w",stdout); 
#endif
    scanf("%lld %lld",&n,&m);

    while(scanf("%lld",&t) != EOF)
    {
        if(t&1)
        {   
            scanf("%lld %lld %lld",&a,&b,&c);
            add(a,b,c);
        }
        else 
        {
            scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
            printf("%lld\n",range_ask(a,b,c,d));
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

