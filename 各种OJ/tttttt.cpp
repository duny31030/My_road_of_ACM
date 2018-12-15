/*
 * =========================================================================
 *
 *       Filename:  tttttt.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/30 21时11分22秒
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
const int N = 1e6;

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int tot = 1;
    int t = 10;
    while(t--)
    {
        if(t >= 1 && t <= N)
        {
            for(int i = t;i > 0;i--)
            {
                cout << "输入第" << tot++ << "个a" << endl;
            }
        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

