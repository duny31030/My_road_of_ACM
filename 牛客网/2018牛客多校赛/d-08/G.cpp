/*
 * =========================================================================
 *
 *       Filename:  G.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/11 13时58分31秒
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
const ll mod = 1000000007;
ll n;
ll a,b,c,pr;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    // cout << (ll)999999999*(ll)999999999%mod << endl;
    pr = 0;
    cin >> n;
    a = (n-1)*(n-2);
    cout << a << endl;
    if(a > mod)
    {
        pr %= mod;
        pr += mod;
    }
    b = (a+10);
    cout << b << endl;
    if(b > mod)
    {
        b %= mod;
        b += mod;
    }
    pr = a*b;
    cout << pr << endl;
    pr /= 24;
    pr %= mod;
    cout << pr << endl;

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

