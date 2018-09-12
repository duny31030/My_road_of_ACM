/*
 * =========================================================================
 *
 *       Filename:  hdu1171.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=1171
 *
 *        Version:  1.0
 *        Created:  2018/07/15 16时52分43秒
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

vector<int> a;
int dp[200020];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int n,t1,t2,sum,sum2;
    while(cin >> n)
    {
        if(n < 0)
            break;
        a.clear();
        sum = 0;
        memset(dp,0,sizeof dp);
        for(int i = 1;i <= n;i++)
        {
            cin >> t1 >> t2;
            sum += t1*t2;
            while(t2--)
                a.push_back(t1);
        }
        sum2 = sum/2;
        for(int i = 0;i < a.size();i++)
        {
            for(int j = sum2;j >= a[i];j--)
                dp[j] = max(dp[j],dp[j-a[i]]+a[i]);
        }
        // printf("%d %d\n",max(dp[sum2],sum-dp[sum2]),min(dp[sum2],sum-dp[sum2]));
        if(sum == dp[sum2]*2)
            printf("%d %d\n",sum/2,sum/2);
        else 
            printf("%d %d\n",sum-dp[sum2],dp[sum2]);
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

