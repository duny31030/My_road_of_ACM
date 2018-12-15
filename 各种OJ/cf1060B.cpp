/*
 * =========================================================================
 *
 *       Filename:  cf1060B.cpp
 *
 *           Link:  http://codeforces.com/problemset/problem/1060/B
 *
 *        Version:  1.0
 *        Created:  2018/10/04 23时52分42秒
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
ll in,p;
int n = 0;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> in;
    if(in <= 10)
    {
        cout << in << endl;
        return 0;
    }
    ll tmp = in;
    while(tmp)
    {
        n++;
        tmp/=10;
    }
    tmp = 9;
    for(int i = 2;i < n;i++)
        tmp = tmp*10+9;
    p = (n-1)*9;
    tmp = in-tmp;
    while(tmp)
    {
        p += tmp%10;
        tmp /= 10;
    }
    cout << p << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

