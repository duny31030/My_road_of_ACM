/*
 * =========================================================================
 *
 *       Filename:  B_easy.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/07 00时39分31秒
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
#define pre(i,a,n) for(int i=n;i>=a;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int t,n;
ll pr;
const int N = 1e6+100;
char a[N];
char b[10];

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("b1.in","r",stdin);
    freopen("b1.out","w",stdout); 
#endif
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> a;
        cin >> b;
        pr = 1;
        if(b[0] == 'L' || b[0] == 'R')
        {
            for(int i = 0;i < n;i++)
            {
                if(a[i] == 'T' || a[i] == 'B')
                {
                    pr *= 2;
                    pr %= mod;
                }
            }
            printf("%lld\n",(pr+1)%mod);
        }
        else 
        {
            for(int i = 0;i < n;i++)
            {
                if(a[i] == 'L' || a[i] == 'R')
                {
                    pr *= 2;
                    pr %= mod;
                }
            }
            printf("%lld\n",(pr+1)%mod);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

