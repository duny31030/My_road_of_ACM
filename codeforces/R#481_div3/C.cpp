/*
 * =========================================================================
 *
 *       Filename:  B.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/26 13时37分32秒
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
const int N = 2e5+10;
int n,m;
ll a[N],b[N];
ll q[N];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d",&n,&m);
    rep(i,1,n)
    {
        scanf("%lld",&a[i]);
        q[i] = q[i-1]+a[i];

    }
    rep(i,1,m)
        scanf("%lld",&b[i]);
    int now = 1;
    rep(i,1,m)
    {
        while(q[now] < b[i])
            now++;
        printf("%d %lld\n",now,b[i]-q[now-1]);
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

