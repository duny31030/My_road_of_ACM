/*
 * =========================================================================
 *
 *       Filename:  F.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/07/28 13时07分12秒
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
#define rep(i,n) for(int i=1;i<=n;i++)
#define ll long long
#define min3(a,b,c) fmin(a,fmin(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int T;
int n,m,p,q,n1,m1,p1,q1;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> T;
    while(T--)
    {
        char a[2020][2020];
        cin >> n >> m;
        p = n1 = n/2;
        q = m1 = m/2;
        p1 = p+1;
        q1 = q+1;
        // cout << "p = " << p << " q = " << q << endl;

        // cout << "p1 = " << p1 << " q1 = " << q1 << endl;

        rep(i,n)
        {
            rep(j,m)
            {
                cin >> a[i][j];
            }
        }   
        rep(i,n1)
        {
            rep(j,m1)
            {
                if(a[i][j] != a[n-i+1][j])
                {
                    p = min(p,i);
                    // cout << "i = " << i << "  j = " << j << endl;
                }
                if(a[i][j] != a[i][m-j+1])
                {
                    q = min(q,j);
                    // cout << "i = " << i << "  j = " << j << endl;
                }
                
            }
        }

        for(int i = n1+1;i <= n;i++)
        {
            for(int j = m1+1;j <= m;j++)
            {
                if(a[i][j] != a[n-i+1][j])
                    p1 = max(p1,i);
                if(a[i][j] != a[i][m-j+1])
                    q1 = max(q1,j);
            }
        }



        // cout << "p = " << p << " q = " << q << endl;
        // cout << "p1 = " << p1 << " q1 = " << q1 << endl;
        
        p = p-1;
        q = q-1;
        p1 = n-p1;
        q1 = m-q1;
        // cout << "p1 = " << p1 << " q1 = " << q1 << endl;

        p = min(p,p1);
        q = min(q,q1);
        cout << p*q << endl;

    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

