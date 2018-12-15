/*
 * =========================================================================
 *
 *       Filename:  cf1060A.cpp
 *
 *           Link:  http://codeforces.com/problemset/problem/1060/A
 *
 *        Version:  1.0
 *        Created:  2018/10/04 23时45分04秒
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
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int n,a1,a2,p;
    a1 = 0,a2 = 0,p = 0;
    char a[110];
    cin >> n;
    cin >> a;
    for(int i = 0;i < n;i++)
    {
        if(a[i] == '8')
            a1++;
    }
    a2 = n/11;
    p = min(a1,a2);
    cout << p << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

