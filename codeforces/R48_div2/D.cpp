/*
 * =========================================================================
 *
 *       Filename:  D.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/04 00时31分37秒
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

int n,m;
int a[110],b[110],c[110][110];
void debug()
{
    rep(i,0,n-1)
    {
        rep(j,0,m-1)
        {
            printf("%d%c",c[i][j],(j == m-1 ? '\n' : ' '));
        }
    }
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> n >> m;
    int tmp = 0;
    rep(i,0,n-1)
    {
       cin >> a[i];
       tmp ^= a[i];
    }
    rep(i,0,m-1)
    {
        cin >> b[i];
        tmp ^= b[i];
    }
    if(tmp != 0)
    {
        cout << "NO" << endl;
    }
    else 
    {
        int t = b[0];
        rep(i,1,n-1)
            t ^= a[i];
        c[0][0] = t;
        rep(i,1,m-1)
            c[0][i] = b[i];
        rep(i,1,n-1)
            c[i][0] = a[i];
        // debug();
        t = 0;
        rep(i,0,m-1)
            t ^= c[0][i];
        if(t != a[0])
            cout << "NO" << endl;
        else 
        {
            cout << "YES" << endl;
            rep(i,0,n-1)
            {
                rep(j,0,m-1)
                {
                    printf("%d%c",c[i][j],(j == m-1 ? '\n' : ' '));
                }
            }
        }
    }
    

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

