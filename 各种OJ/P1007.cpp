/*
 * =========================================================================
 *
 *       Filename:  P1007.cpp
 *
 *           Link:  https://www.luogu.org/problemnew/show/P1007
 *
 *        Version:  1.0
 *        Created:  2018/10/15 16时08分30秒
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
const int N = 5010;
int L,n;
int a[N];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> L;
    cin >> n;
    rep(i,1,n)  cin >> a[i];
    int mmax = 0,mmin = 0;
    int tmp = 0;
    rep(i,1,n)
    {
        tmp = L-a[i]+1;
        mmax = max(mmax,max(a[i],tmp));
        mmin = max(mmin,min(a[i],tmp));
    }
    cout << mmin << " " << mmax << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

