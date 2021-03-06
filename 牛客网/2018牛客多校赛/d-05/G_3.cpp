/*
 * =========================================================================
 *
 *       Filename:  G_3.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/02 13时59分28秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.github.io/), duny31030@126.com
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

//================读入挂&&输出挂================

//====================end=====================


ll c,n,p,a,b;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> c >> n;
    a = n/c*c;
    b = max((n/c-1)*c,c);
    p = a*b;
    // cout << a << " " << b << endl;
    if(c > n)
        cout << "-1" << endl;
    else 
        cout << p << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

