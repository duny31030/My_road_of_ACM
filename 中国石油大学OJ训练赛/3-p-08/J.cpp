/*
 * =========================================================================
 *
 *       Filename:  J.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/03 12时31分23秒
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
const int N = 1e5+10;
int n;
int a[N],b[N],c[N],a1[N],b1[N],c1[N];
ll pr = 0;
map<int,int> ma,mb,mc;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> n;
    rep(i,1,n)  cin >> a[i];
    rep(i,1,n)  cin >> b[i];
    rep(i,1,n)  cin >> c[i];

    sort(a+1,a+n+1);    sort(b+1,b+n+1);    sort(c+1,c+n+1);

    ll ai = 0,ci = 0;
    rep(i,1,n)
    {
        while(a[ai+1] < b[i] && ai <= n-1)
        {
            ai++;
        }
        while(c[ci+1] <= b[i] && ci <= n-1)
        {
            ci++;
        }
        ll tmp = n-ci;
        pr += ai*tmp;
    }

    cout << pr << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

