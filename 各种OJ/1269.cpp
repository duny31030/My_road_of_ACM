/*
 * =========================================================================
 *
 *       Filename:  1269.cpp
 *
 *           Link:  http://210.44.144.221/problem.php?id=1269
 *
 *        Version:  1.0
 *        Created:  2018/10/26 20时18分52秒
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
const int mod = 10007;
const int N = 100100;
ll n,n2;
ll a[N],b[N];
ll dp[N];
// ans1[]: i
// ans2[]: cigema a[i]
// ans3[]: cigema i*a[i]
// ans4[]: 个数
ll ans1[N],ans2[N],ans3[N],ans4[N];
ll ans;
map<ll,ll> m;

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    clr(ans1,0);    clr(ans2,0);    clr(ans3,0);    clr(ans4,0);
    scanf("%lld %lld",&n,&n2);
    rep(i,1,n)  {   scanf("%lld",&a[i]);    a[i] %= mod;    }
    rep(i,1,n)  scanf("%lld",&b[i]);
    m.clear();
    for(ll i = 1;i <= n;i += 2)
    {
        if(m[b[i]] == 0)
        {
            m[b[i]] = i;
            ans1[i] = i;
            ans2[i] = a[i];
            ans3[i] = a[i]*i;
            ans4[i] = 0;
            dp[i] = i;
        }
        else 
        {
            ll tmp = m[b[i]];
            ans1[i] = ans1[tmp]+i;
            ans2[i] = ans2[tmp]+a[i];
            ans3[i] = ans3[tmp]+a[i]*i%mod;
            ans4[i] = ans4[tmp]+1;
            dp[i] = tmp;
            m[b[i]] = i;
        }
        ans1[i] %= mod; ans2[i] %= mod;  ans3[i] %= mod; ans4[i] %= mod;
    }
    m.clear();
    for(ll i = 2;i <= n;i += 2)
    {
        if(m[b[i]] == 0)
        {
            m[b[i]] = i;
            ans1[i] = i;
            ans2[i] = a[i];
            ans3[i] = a[i]*i;
            ans4[i] = 0;
            dp[i] = i;
        }
        else 
        {
            ll tmp = m[b[i]];
            ans1[i] = ans1[tmp]+i;
            ans2[i] = ans2[tmp]+a[i];
            ans3[i] = ans3[tmp]+a[i]*i;
            ans4[i] = ans4[tmp]+1;
            dp[i] = tmp;
            m[b[i]] = i;
        }
        ans1[i] %= mod; ans2[i] %= mod;  ans3[i] %= mod; ans4[i] %= mod;
    }
    ans = 0;
    for(ll i = 1;i <= n;i++)
    {
        if(dp[i] != i)
        {
            ll tmp = dp[i];
            ans += ans3[tmp];       ans %= mod;
            ans += a[i]*ans1[tmp];  ans %= mod;
            ans += ans2[tmp]*i;     ans %= mod;
            ans += ans4[i]*i*a[i];  ans %= mod;
        }
    }
    printf("%lld\n",ans);
    fclose(stdin);
    // fclose(stdout);
    return 0;
}



