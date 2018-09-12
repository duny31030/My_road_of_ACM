/*
 * =========================================================================
 *
 *       Filename:  D.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/07/18 16时54分48秒
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
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int T;
    cin >> T;
    int n,m;
    double n1,m1;
    n1 = 0.5000000;
    for(int i = 1;i <= T;i++)
    {
        cin >> n >> m;
        if(n == 1)
            n1 = 1.00000;
        else 
            n1 = 0.500000;
        m1 = (m*1.0+1)/(m*2.0);
        cout << "Case #" << i << ": ";
        printf("%.6f %.6f\n",n1,m1);
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

