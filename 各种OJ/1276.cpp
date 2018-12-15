/*
 * =========================================================================
 *
 *       Filename:  1276.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/26 18时18分42秒
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

int n;
int i,j,k;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> n;
    j = 1;
    k = 0;
    ll ans = 0;
    for(i = 1;i <= n;i++)
    {
        ans += j;
        k++;
        if(k == j)
        {
            k = 0;
            j++;
        }
    }
    cout << ans << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

