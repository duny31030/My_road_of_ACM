/*
 * =========================================================================
 *
 *       Filename:  E.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/26 15时48分54秒
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
ll n,w;
ll l,r;
ll nmax,nmin;
ll a[1010];
ll sum[1010];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%lld %lld",&n,&w);
    nmax = -INF;
    nmin = INF;
    sum[0] = 0;
    for(ll i = 1;i <= n;i++)
    {
        scanf("%lld",&a[i]);
        sum[i] = sum[i-1]+a[i];
        nmax = max(nmax,sum[i]);
        nmin = min(nmin,sum[i]);
    }
    // printf("%lld %lld\n",nmax,nmin);
    if(nmax > w || nmin < (-1*w))
        printf("0\n");
    else 
    {
        if(nmin < 0)
        {
            l = (-1*nmin);
        }
        else 
        {
            l = 0;
        }
        if(nmax < 0)
        {
            l = max(l,nmax);
            r = w;
        }
        else 
        {
            r = w-nmax;
        }
        if((r-l+1) < 0)
            printf("0\n");
        else 
            printf("%lld\n",r-l+1);
    }
        
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

