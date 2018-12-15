/*
 * =========================================================================
 *
 *       Filename:  cai0132.cpp
 *
 *           Link:  https://loj.ac/problem/132
 *
 *        Version:  1.0
 *        Created:  2018/10/08 22时04分09秒
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
const int N = 1e6+100;
ll a[N];
ll sum1[N<<2];
ll sum2[N<<2];
ll n,q,t,x,y;
void add(ll p,ll x)
{
    for(int i = p;i <= n;i += i&(-i))
        sum1[i] += x,sum2[i] += x*p;
}

void range_add(ll l,ll r,ll x)
{
    add(l,x),add(r+1,-x);
}
ll ask(ll p)
{
    ll res = 0;
    for(int i = p;i;i -= i&(-i))
        res += (p+1)*sum1[i]-sum2[i];
    return res;
}
ll range_ask(ll l,ll r)
{
    return ask(r)-ask(l-1);
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%lld %lld",&n,&q);
    rep(i,1,n)  scanf("%lld",&a[i]);
    pre(i,2,n)  a[i] = a[i]-a[i-1];
    rep(i,1,n)  add(i,a[i]);

    rep(i,1,q)
    {
        scanf("%lld",&t);
        if(t&1)
        {
            scanf("%lld %lld %lld",&x,&y,&t);
            range_add(x,y,t);
        }
        else 
        {
            scanf("%lld %lld",&x,&y);
            printf("%lld\n",range_ask(x,y));
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

