/*
 * =========================================================================
 *
 *       Filename:  C.cpp
 *
 *           Link:  https://vjudge.net/problem/19282/origin
 *
 *        Version:  1.0
 *        Created:  2018/09/22 14时34分25秒
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
const int MAXN = 5e5+100;
char r[MAXN];
int wa[MAXN],wb[MAXN],wv[MAXN],wss[MAXN];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b] && r[a+l]==r[b+l];
}
int sa[MAXN],rk[MAXN],height[MAXN];
void SA(int n,int m)
{
    int *x=wa,*y=wb;

    for(int i=0; i<m; ++i) wss[i]=0;
    for(int i=0; i<n; ++i) ++wss[x[i]=r[i]];
    for(int i=1; i<m; ++i) wss[i]+=wss[i-1];
    for(int i=n-1; i>=0; --i) sa[--wss[x[i]]]=i;

    int p=1;
    for(int j=1; p<n; j<<=1,m=p)
    {
        p=0;
        for(int i=n-j; i<n; ++i) y[p++]=i;
        for(int i=0; i<n; ++i) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(int i=0; i<n; ++i) wv[i]=x[y[i]];
        for(int i=0; i<m; ++i) wss[i]=0;
        for(int i=0; i<n; ++i) ++wss[wv[i]];
        for(int i=1; i<m; ++i) wss[i]+=wss[i-1];
        for(int i=n-1; i>=0; --i) sa[--wss[wv[i]]]=y[i];
        swap(x,y); x[sa[0]]=0; p=1;
        for(int i=1; i<n; ++i) x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }

    for(int i=1; i<n; ++i) rk[sa[i]]=i;
    int k=0;
    for(int i=0; i<n-1; height[rk[i++]]=k)
    {
        if(k) --k;
        for(int j=sa[rk[i]-1]; r[i+k]==r[j+k]; ++k);
    }
}

ll n;

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",r);
        n = strlen(r);
        // r[n+1] = 0;
        SA(n+1,180);
        ll pr = n*(n+1)/2;
        rep(i,1,n)
            pr -= height[i];
        printf("%lld\n",pr);
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

