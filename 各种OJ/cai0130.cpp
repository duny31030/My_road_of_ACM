/*
 * =========================================================================
 *
 *       Filename:  cai0130.cpp
 *
 *           Link:  https://loj.ac/problem/130
 *
 *        Version:  1.0
 *        Created:  2018/10/08 12时26分01秒
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
ll tmp,x,y;
// 给位置p增加x
void add(ll p,ll x)   
{
    while(p <= n)
        sum[p] += x,p += p&(-p);
}
// 求位置p的前缀和
ll ask(ll p)
{
    ll res = 0;
    while(p)
        res += sum[p],p -= p&(-p);
    return res;
}
// 区间求和
ll range_ask(int l,int r)
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
    scanf("%d %d",&n,&q);
    rep(i,1,n){ scanf("%lld",&tmp);   add(i,tmp); }
    rep(i,1,q){ scanf("%lld %lld %lld",&tmp,&x,&y);   if(tmp&1)   add(x,y);   else printf("%lld\n",range_ask(x,y));}
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

