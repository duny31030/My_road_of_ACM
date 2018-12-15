/*
 * =========================================================================
 *
 *       Filename:  cai0134.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/09 00时39分18秒
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
const int N = 2500;
ll n,m,Q,a,b,c,d,x;
ll t1[N][N],t2[N][N],t3[N][N],t4[N][N];
void add(ll x,ll y,ll z)
{
    for(int X = x;X <= n;X += X&(-X))
        for(int Y = y;Y <= m;Y += Y&(-Y))
        {
            t1[X][Y] += z;
            t2[X][Y] += z*x;
            t3[X][Y] += z*y;
            t4[X][Y] += z*x*y;
        }
}

void range_add(ll xa,ll ya,ll xb,ll yb,ll z)
{
    add(xa,ya,z);
    add(xa,yb+1,-z);
    add(xb+1,ya,-z);
    add(xb+1,yb+1,z);
}

ll ask(ll x,ll y)
{
    ll res = 0;
    for(int i = x;i;i -= i&(-i))
        for(int j = y;j;j -= j&(-j))
            res += (x+1)*(y+1)*t1[i][j]
            	- (y+1)*t2[i][j] - (x+1)*t3[i][j]
            	+ t4[i][j];
    return res;
}

ll range_ask(ll xa,ll ya,ll xb,ll yb)
{
    return ask(xb,yb) - ask(xb,ya-1) - ask(xa-1,yb) 
           + ask(xa-1,ya-1);
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%lld %lld",&n,&m);
    while(scanf("%lld",&Q) != EOF)
    {
        if(Q&1)
        {
            scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&x);
            range_add(a,b,c,d,x);
        }
        else 
        {
            scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
            printf("%lld\n",range_ask(a,b,c,d));
        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

