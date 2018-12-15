/*
 * =========================================================================
 *
 *       Filename:  cai0131.cpp
 *
 *           Link:  https://loj.ac/problem/131
 *
 *        Version:  1.0
 *        Created:  2018/10/08 12时44分22秒
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
ll sum[N<<2];
int n,q;
int x,y;
ll a[N];
ll t;
void add(ll p,ll x)
{
    while(p <= n)
        sum[p] += x,p += p&(-p);
}
// 给区间[l,r]加上x
void range_add(int l,int r,int x)
{
    add(l,x),add(r+1,-x);
}
ll ask(int p)
{
    ll res = 0;
    while(p)
        res += sum[p],p -= p&(-p);
    return res;
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
    rep(i,1,n)  scanf("%lld",&a[i]);
    pre(i,2,n)    a[i] -= a[i-1];
    rep(i,1,n)  add(i,a[i]);
    rep(i,1,q)
    {
        scanf("%lld",&t);
        if(t&1)
        {
            scanf("%d %d %lld",&x,&y,&t);
            range_add(x,y,t);
        }
        else 
        {
            scanf("%d",&x);
            printf("%lld\n",ask(x));
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

