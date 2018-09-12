/*
 * =========================================================================
 *
 *       Filename:  2955.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=2955
 *
 *        Version:  1.0
 *        Created:  2018/07/15 14时30分24秒
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
const double eps = 1e-9;
const int INF = 0x3f3f3f3f;

int m[120];
double p[120];
double dp[10020];

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int T,N;
    double P;
    cin >> T;
    while(T--)
    {
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        int sum = 0;
        cin >> P >> N;
        P = 1-P;
        for(int i = 1;i <= N;i++)
        {
            cin >> m[i] >> p[i];
            p[i] = 1-p[i];
            sum += m[i];
        }
        
        for(int i = 1;i <= N;i++)
        {
            for(int j = sum;j >= m[i];j--)
            {
                dp[j] = max(dp[j],dp[j-m[i]]*p[i]);
            }
        }
        for(int i = sum;i >= 0;i--)
        {
            if(P-dp[i] < eps)
            {
                cout << i << endl;
                break;
            }
        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

