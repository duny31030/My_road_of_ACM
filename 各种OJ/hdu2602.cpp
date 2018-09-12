/*
 * =========================================================================
 *
 *       Filename:  hdu2602.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=2602
 *
 *        Version:  1.0
 *        Created:  2018/07/11 11时44分51秒
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

int a[1050],b[1050];
int d[1050][1050];

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int T,N,V;
    cin >> T;
    while(T--)
    {
        cin >> N >> V;
        for(int i = 1;i <= N;i++)
        {
            cin >> a[i];
        }
        for(int i = 1;i <= N;i++)
        {
            cin >> b[i];
        }
        memset(d,0,sizeof d);
        for(int i = 1;i <= N;i++)
        {
            for(int j = 0;j <= V;j++)
            {
                if(j >= b[i])
                    d[i][j] = max(d[i-1][j],d[i-1][j-b[i]]+a[i]);
                else 
                    d[i][j] = d[i-1][j];
            }
        }
/*      优化空间复杂度
 *      int dp[1010];
 *      memset(dp,0,sizeof dp);
 *      for(int i = 1;i <= N;i++)
 *      {
 *          for(int j = V;j >= b[i];j--)
 *          {
 *              dp[j] = max(dp[j],dp[j-b[i]]+a[i]);
 *          }
 *      }
 */
        cout << d[N][V] << endl;
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

