/*
 * =========================================================================
 *
 *       Filename:  G.cpp
 *
 *           Link:  https://www.jisuanke.com/contest/1404/80896
 *
 *        Version:  1.0
 *        Created:  2018/07/10 12时14分04秒
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
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("./in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int T;
    int n,a,b,c;
    cin >> T;
    while(T--)
    {
        int mmax = -9999;
        int flag = 0;
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> a >> b >> c;
            a = -a;
            int tmp = (4*a*c-b*b)/(4*a);
            //printf("%.4f\n",tmp);
            if(tmp > mmax)
            {
                mmax = tmp;
                flag = i;
            }
        }
        cout << flag << endl;
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

