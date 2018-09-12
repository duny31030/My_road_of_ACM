/*
 * =========================================================================
 *
 *       Filename:  hdu2546.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=2546
 *
 *        Version:  1.0
 *        Created:  2018/07/12 11时40分47秒
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
    int n,m;
    while(cin >> n && n != 0)
    {
        int a[1020];
        int dp[1020];
        memset(a,0,sizeof a);
        int p;
        p = n;
        for(int i = 1;i <= n;i++)
            cin >> a[i];
        cin >> m;
        if(m < 5)
        {
            cout << m << endl;
        }
        else 
        {
            memset(dp,0,sizeof dp);
            sort(a+1,a+n+1);
            for(int i = 1;i < n;i++)
            {
                for(int j = m-5;j >= a[i];j--)
                    dp[j] = max(dp[j],dp[j-a[i]]+a[i]);
            }
        cout << m-dp[m-5]-a[n] << endl;
        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}
//  
