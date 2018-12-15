/*
 * =========================================================================
 *
 *       Filename:  P1984.cpp
 *
 *           Link:  https://www.luogu.org/problemnew/show/P1984
 *
 *        Version:  1.0
 *        Created:  2018/10/15 16时19分30秒
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


int main()
{
    // ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    ll n;
    cin >> n;

    double tmp = 100.00,tmp2 = 100.00;;
    for(int i = 1;i < n;i++)
    {
        tmp2 *= (double)(2*i-1)/(double)(2*i);
        // cout << tmp2 << endl;
        tmp += tmp2;
    }
    tmp *= 4200.0/(double)n;
    printf("%.2f\n",tmp);
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

