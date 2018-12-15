/*
 * =========================================================================
 *
 *       Filename:  A_hard.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/07 00时00分37秒
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

int t,n,tmp;

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("a2.in","r",stdin);
    freopen("a2.out","w",stdout); 
#endif
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> tmp;
            if(i == n)
                cout << "1";
            else 
            {
                if(tmp == 100)
                    cout << "100";
                else 
                    if(tmp >= 10)
                        cout << "10";
                    else 
                    cout << "1";
            }
            if(i == n)
                cout << endl;
            else 
                cout << " ";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

