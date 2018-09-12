/*
 * =========================================================================
 *
 *       Filename:  C.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/26 13时19分26秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 2e5+10;
int n,k;
ll a[N];

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d",&n,&k);
    rep(i,1,n)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);

    if(n == k)
    {
        printf("%lld\n",a[n]);
    }
    else 
    {
        if(k == 0)
        {
            if(a[1] > 1)
                printf("1\n");
            else 
                printf("-1\n");
        }
        else 
        {
            if(a[k] == a[k+1])
            {
                printf("-1\n");
            }
            else 
            {
                printf("%lld\n",a[k]);
            }

        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

