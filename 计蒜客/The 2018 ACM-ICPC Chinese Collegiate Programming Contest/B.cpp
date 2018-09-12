/*
 * =========================================================================
 *
 *       Filename:  B.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/07/17 14时34分11秒
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
#define PI 3.14159
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int T,n;
    int a[60],b[60],x,y;
    cin >> T;
    while(T--)
    {
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i] >> b[i];
        }
        cin >> x >> y;
        double pr = 0.0;
        for(int i = 1;i <= n;i++)
        {
            double len = sqrt(((a[i]-x)*(a[i]-x)+(b[i]-y)*(b[i]-y))*1.0);
            pr += (len*PI*2/n);
        }
        printf("%.3lf\n",pr);
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

