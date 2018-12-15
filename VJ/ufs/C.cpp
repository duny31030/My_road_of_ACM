/*
 * =========================================================================
 *
 *       Filename:  C.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=1213
 *
 *        Version:  1.0
 *        Created:  2018/09/18 18时50分18秒
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
const int MAXN = 1e3+10;
int T;
int N,M,x,y;
int f[MAXN];

int find(int x)
{
    if(x != f[x])
        f[x] = find(f[x]);
    return f[x];
}
set<int> s;
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
        s.clear();
        cin >> N >> M;
        rep(i,0,N)
            f[i] = i;
        rep(i,1,M)
        {
            cin >> x >> y;
            if(x > y)
                swap(x,y);
            int x1 = find(x);
            int x2 = find(y);
            if(x1 != x2)
                f[x2] = x1;
        }
        rep(i,1,N)
        {
            s.insert(find(i));
        }
        cout << s.size() << endl;
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

