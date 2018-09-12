/*
 * =========================================================================
 *
 *       Filename:  L.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/10 12时23分18秒
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

int n;
int a[210];

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> n;
    rep(i,1,n)
        cin >> a[i];
    int pr = 99999;
    rep(i,1,n)
    {
        int x = a[i];
        int flag = 0;
        while(x%2 == 0)
        {
            x /= 2;
            flag++;
        }
        pr = min(pr,flag);
    }
    cout << pr << endl;

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

