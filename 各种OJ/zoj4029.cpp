/*
 * =================================================================
 *
 *       Filename:  zoj4029.cpp
 *
 *           Link:  http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=4029
 *
 *        Version:  1.0
 *        Created:  2018/10/22 21时11分39秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =================================================================
 */
#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=n;i>=a;i--)
#define LL long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9;
const int N = 5e5+100;
LL a[N];
LL sum[N][35];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
        LL n,m;
        scanf("%lld %lld",&n,&m);
        rep(i,1,n)  scanf("%lld",&a[i]);
        sort(a+1,a+1+n);
        // 打表预处理
        for(LL k = 1;k <= 30;k++)
            for(LL i = 1;i <= n;i++)
                sum[i][k] = sum[i-1][k]+a[i]/k;
        
        LL ans = 0;
        for(LL j = 1;j <= m;j++)
        {
            LL x;
            scanf("%lld",&x);
            LL pos;
            LL up = x;
            LL k = 1;
            LL tmp = 0;
            for(LL i = 1;i <= n;i = pos+1)
            {
                pos = i-1;
                LL l = i,r = n;
                while(l <= r)
                {
                    LL mid = (l+r)>>1;
                    if(a[mid] <= up)
                    {
                        pos = mid;
                        l = mid+1;
                    }
                    else 
                        r = mid-1;
                }
                tmp = (tmp+sum[pos][k]-sum[i-1][k]+mod)%mod;
                k++;
                up *= x;
            }

            ans = (ans+tmp*j)%mod;
        }
        printf("%lld\n",ans);
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}
