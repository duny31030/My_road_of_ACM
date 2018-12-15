/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  https://vjudge.net/contest/238376#problem/A
 *
 *        Version:  1.0
 *        Created:  2018/07/16 17时42分17秒
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

int dp[260][60];

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int t[60];   // 从i车站开往i+1车站的行驶时间
    int d[260];   // 往右开的列车的出发时间
    int e[260];   // 往左开的列车的出发时间
    bool has_train[300][55][2];
    // has_train[t][i][0]   时刻t，在车站i，是否有车往右开
    // has_train[t][i][1]   时刻t，在车站i，是否有车往左开
    int n,T,M1,M2;
    int flag = 1;
    while(cin >> n)
    {
        if(n == 0)
            break;

        memset(t,0,sizeof t);   
        memset(d,0,sizeof d);
        memset(e,0,sizeof e);
        memset(has_train,0,sizeof has_train);

        cin >> T;
        for(int i = 1;i < n;i++)
            cin >> t[i];
        cin >> M1;
        for(int i = 1;i <= M1;i++)
            cin >> d[i];
        cin >> M2;
        for(int i = 1;i <= M2;i++)
            cin >> e[i];

        // has_train
        for(int i = 1;i <= M1;i++)
        {
            int timer = d[i];
            has_train[timer][1][0] = 1;
            for(int j = 1;j < n;j++)
            {
                if(timer+t[j] <= T)
                {
                    has_train[timer+t[j]][j+1][0] = 1;
                    timer += t[j];
                }
                else 
                    break;
            }
        }
        for(int i = 1;i <= M2;i++)
        {
            int timer = e[i];
            if(d[i] <= T)
                has_train[timer][n][1] = 1;
            for(int j = n-1;j >= 1;j--)
            {
                if(timer+t[j] <= T)
                {
                    has_train[timer+t[j]][j][1] = 1;
                    timer += t[j];
                }
                else 
                    break;
            }
        }
        
        // dp 
        for(int i = 1;i <= n-1;i++) dp[T][i] = INF;
        dp[T][n] = 0;
        for(int i = T-1;i >= 0;i--)
        {
            for(int j = 1;j <= n;j++)
            {
                dp[i][j] = dp[i+1][j]+1;
                if(j < n && has_train[i][j][0] && i+t[j] <= T)
                    dp[i][j] = min(dp[i][j],dp[i+t[j]][j+1]);
                if(j > 1 && has_train[i][j][1] && i+t[j-1] <= T)
                    dp[i][j] = min(dp[i][j],dp[i+t[j-1]][j-1]);

            }
        }

        cout << "Case Number " << flag++ << ": ";
        if(dp[0][1] >= INF)
            cout << "impossible\n";
        else 
            cout << dp[0][1] << "\n";
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

