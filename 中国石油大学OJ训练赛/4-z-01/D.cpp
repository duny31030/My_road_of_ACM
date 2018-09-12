/*
 * =========================================================================
 *
 *       Filename:  D.cpp
 *
 *           Link:  http://exam.upc.edu.cn/problem.php?id=5215
 *
 *        Version:  1.0
 *        Created:  2018/08/21 21时16分29秒
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
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const ll maxn = 1e6+10;

int t;
ll n;

ll power_mod(ll a,ll b)
{
    ll base = a%mod;
    a = a%mod;
    ll res = 1LL;
    while(b)
    {
        if(b & 1)
        {
            res = base*res%mod;
        }
        base = base*base%mod;
        b = b>>1;
    }
    return res%mod;
}


ll C(ll n,ll m)
{
    if(m > n)
        return 0;
    ll ans = 1;
    for(int i = 1;i <= m;i++)
    {
        ll a = (n+i-m)%mod;
        ll b = i%mod;
        ans = ans*(a*power_mod(b,mod-2)%mod)%mod;
    }
    return ans;
}


ll lucas(ll a,ll b)
{
    if(a < mod && b < mod)
        return C(a,b);
    else 
        return C(a%mod,b%mod)*lucas(a/mod,b/mod);
}



int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d",&t);
    rep(i,1,t)
    {
        scanf("%lld",&n);
        printf("Case #%d: %lld\n",i,(lucas(n,2)+lucas(n,4)+1)%mod);
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

