/*
 * =========================================================================
 *
 *       Filename:  1002.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/04 16时24分27秒
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

int T,n,q,l,r;
char a[100010];
int nex[30][100010];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> T;

    rep(ca,1,T)
    {
        clr(nex,0);
        cin >> n >> q;
        cin >> a;
        char ch = 'A';
        rep(i,0,25)
        {
            rep(j,0,n-1)
            {
                if(a[j] == (ch+i))
                    nex[i][j+1] = nex[i][j]+1;
                else 
                {
                    nex[i][j+1] = nex[i][j];
                }
            }
        }
        // rep(i,1,n)
        //     cout << nex[0][i] << " ";
        // cout << endl;
        // rep(i,1,n)
        //     cout << nex[1][i] << " ";
        // cout << endl;

        cout << "Case #" << ca << ":" << endl;
        rep(i,1,q)
        {
            cin >> l >> r;
            if(l == r)
                cout << "1" << endl;
            else 
            {
                // int mmin = 99999;
                rep(i,0,25)
                {
                    if(nex[i][r]-nex[i][l-1])
                    {
                        cout << nex[i][r]-nex[i][l-1] << endl;
                        break;
                        // mmin = min(mmin,nex[i][r]-nex[i][l-1]);
                    }
                }
                // cout << mmin << endl;
            }
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

