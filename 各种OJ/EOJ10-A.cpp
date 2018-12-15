/*
 * =========================================================================
 *
 *       Filename:  EOJ10-A.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/02 19时59分47秒
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

int n,m,p;
int a[110][110];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    clr(a,0);
    int tot = 1,k = 0;
    cin >> n >> m >> p;
    if(n*m % p || (p > n && p > m))
        cout << "No" << endl;
    else 
    {
        cout << "Yes" << endl;
        for(int i = 1,j = 1;i <= n;)
        {
            if(m-j+1 >= p)
            {
                for(k = j;k < j+p;k++)
                    a[i][k] = tot;
                tot++;
                j = k;
            }
            else 
            {
                if(a[i][j] == 0)
                {
                    for(k = i;k < i+p;k++)
                        a[k][j] = tot;
                    tot++;
                }
                j++;
            }
            if(j > m)
                i++,j = 1;

        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                if(j == 1)
                    cout << a[i][j];
                else 
                    cout << " " << a[i][j];
                if(j == m)
                    cout << endl;
            }
        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

