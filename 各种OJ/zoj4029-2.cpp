#include <bits/stdc++.h>
using namespace std;
#define LL long long
const LL mod = 1e9;
const LL N = 5e5+33;
LL a[N];
LL sum[N][32];
int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
        LL n,m;
        scanf("%lld %lld",&n,&m);
        for(LL i = 1;i <= n;i++)  
            scanf("%lld",&a[i]);
        sort(a+1,a+1+n);
        for(LL k = 1;k <= 30;k++)
        {
            for(LL i = 1;i <= n;i++)
                sum[i][k] = sum[i-1][k]+a[i]/k;
        }
        
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
                    {
                        r = mid-1;
                    }
                }
                tmp = (tmp+sum[pos][k]-sum[i-1][k]+mod)%mod;
                k++;
                up *= x;
            }
            ans = (ans+tmp*j)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
