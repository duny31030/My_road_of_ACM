/*
 * =========================================================================
 *
 *       Filename:  hdu1110.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=1110
 *
 *        Version:  1.0
 *        Created:  2018/08/04 17时51分54秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <iostream>
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


int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int t,x,y,a,b;
    cin >> t;
    while(t--)
    {
        cin >> x >> y >> a >> b;
        if(x > y)
        {
            int t = x;
            x = y;
            y = t;
        }
        if(a > b)
        {
            int t = a;
            a = b;
            b = t;
        }
        if(x >= a && y >= b)
        {
            cout << "Escape is possible." << endl;
        }
        else 
        {
            cout << "Box cannot be dropped." << endl;
        }
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

