/*
 * =========================================================================
 *
 *       Filename:  EOJ10-B.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/02 20时29分11秒
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
const int N = 2e5+100;
ll n;
ll a[N];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%lld",&n);
    ll p = 0;
    for(ll i = 1;i <= n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i] > p)
            p = a[i];
    }
    p++;
    ll i,x;
    x = a[1]-1;
    if(x < 0)
        x += p;
    ll j = 1;
    for(i = 2;i <= n;i++)
    {
        // cout << (j+x)%p << endl;
        if(a[i] > a[i-1])
            j += a[i]-a[i-1];
        else 
            if(a[i] < a[i-1])
                j += p+a[i]-a[i-1];
            else 
                j += p;
    }
    
    printf("%lld\n",j);
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

