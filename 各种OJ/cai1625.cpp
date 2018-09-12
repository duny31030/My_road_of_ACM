/*
 * =========================================================================
 *
 *       Filename:  cai1625.cpp
 *
 *           Link:  http://caioj.cn/problem.php?id=1625
 *
 *        Version:  1.0
 *        Created:  2018/09/04 20时42分44秒
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
const int N = 50010;
const int M = 32767;
ll sum[M];
ll ans[N];
ll a[N];
ll pr = 0;
int n;
void add(ll p,ll x)
{
    while(p <= M)
        sum[p] += x,p += p&(-p);
}

ll ask(ll p)
{
    ll res = 0;
    while(p)
        res += sum[p],p -= p&(-p);
    return res;
}

int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    while(scanf("%d",&n) != EOF){
        pr = 0;
        clr(ans,0);
        clr(sum,0);
    for(int i = 1;i <= n;++i)
    {
        scanf("%lld",&a[i]);
        a[i]++;
        add(a[i],1);
        ans[i] = ask(a[i]-1);
    }
    clr(sum,0);
    for(int i = n;i >= 1;i--)
    {
        add(a[i],1);
        ans[i] *= ask(a[i]-1);

        pr += (ll)ans[i];
    }
    printf("%lld\n",pr);
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

