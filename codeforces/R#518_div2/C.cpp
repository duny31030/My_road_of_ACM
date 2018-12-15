/*
 * =========================================================================
 *
 *       Filename:  C.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/25 01时20分24秒
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
const int N = 1010;

vector<int> p[N];

int n,m,x,y;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> n >> m;
    for(int i = 1;i <= m;i++)
    {
        cin >> x >> y;
        p[x].push_back(i+n+1);
        p[y].push_back(i+n+1);
    }
    for(int k = 1;k <= n;k++)
    {
        int tmp = p[k].size();
        cout << tmp+1 << endl;
        cout << k << " " << k << endl;
        for(int i = 1;i <= tmp;i++)
        {
            cout << k << " " << p[k][i-1] << endl;
        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

