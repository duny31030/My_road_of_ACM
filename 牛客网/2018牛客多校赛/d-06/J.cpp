/*
 * =========================================================================
 *
 *       Filename:  J.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/04 12时01分53秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
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
const int N = 1e7+10;
ll t;
int n;
unsigned a[N];
unsigned long long ans;
unsigned  A,B,C;
unsigned x,y,z;
unsigned  gcd(unsigned  a, unsigned  b){ return a == 0 ? b : gcd(b % a, a); } 
unsigned tang()
{
    unsigned t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    t = x;
    x = y;
    y = z;
    z = t^x^y;
    return z;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> t;
    rep(ca,1,t)
    {
        cin >> n >> A >> B >>C;
        x = A,y = B,z = C;
        rep(i,0,n-1)
            a[i] = tang();
        int m = min(n,100);
        nth_element(a,a+n-m,a+n);
        ans = 0;
        rep(i,n-m,n-1)
            rep(j,i+1,n-1)
                ans = max(ans,a[i]/gcd(a[i],a[j])*(unsigned long long)a[j]);
        cout << "Case #" << ca << ": " << ans << endl;

    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

