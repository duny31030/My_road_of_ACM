/*
 * =========================================================================
 *
 *       Filename:  hdu1203.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=1203
 *
 *        Version:  1.0
 *        Created:  2018/07/15 15时16分12秒
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
double dp[10020];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int n,m;
    int a[10020];
    double b[10020];
    while(cin >> n >> m)
    {
        if(n == 0 && m == 0)
            break;
        memset(a,0,sizeof a);   memset(b,0,sizeof b);   // aemset(dp,0,sizeof dp); 
        for(int i = 0;i < 10020;i++)
            dp[i] = 1.0;
        for(int i = 1;i <= m;i++)
        {
            cin >> a[i] >> b[i];
            b[i] = 1-b[i];
        }

        for(int i = 1;i <= m;i++)
        {
            for(int j = n;j >= a[i];j--)
            {
                dp[j] = min(dp[j],dp[j-a[i]]*b[i]);
            }
        }
        //double pr = 1.0;
        //for(int i = 1;i <= n;i++)
        //    pr = min(pr,dp[i]);
        //pr = 1-pr;
        //pr *= 100;
        printf("%.1lf%%\n",(1-dp[n])*100);

    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

