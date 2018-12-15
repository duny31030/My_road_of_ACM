/*
 * =========================================================================
 *
 *       Filename:  gym101485-D.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/11/01 23时46分20秒
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
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1000010;
ll n,r,q;
ll dp[N];
ll ce(ll x,ll y)
{
    ll z = x/y;
    if(z*y == x)    return z;
    return z+1;
}

ll dfs(ll n)
{
    if(dp[n])   return dp[n];
    if(n <= 1)  return 0;
    ll res = INF;
    for(ll i = 2;i <= n;i++)
    {
        res = min(res,dfs(ce(n,i))+(i-1)*q+r);
    }
    return dp[n] = res;
}


int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> n >> r >> q;
    clr(dp,0);
    ll ans = dfs(n);
    cout << ans << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

