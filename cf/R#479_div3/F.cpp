/*
 * =========================================================================
 *
 *       Filename:  F.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/26 16时15分07秒
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
const int N = 2e5+100;
int n;
ll a[N];
map<ll,int> m;
int pr = 0;
ll flag = 0;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d",&n);
    rep(i,1,n)
    {
        scanf("%lld",&a[i]);
    }
    rep(i,1,n)
    {
        if(m[a[i]-1] != 0)
        {
            m[a[i]] = m[a[i]-1]+1;
            if(pr < m[a[i]])
            {
                pr = m[a[i]];
                flag = a[i];
            }
        }
        else 
        {
            m[a[i]] = 1;
        }
    }
    if(pr == 0)
    {
        printf("1\n1\n");
        return 0;
    }
    printf("%d\n",pr);
    int p[N];
    int len = 1;
    for(int i = n;pr && i >= 1;i--)
    {
        if(a[i] == flag)
        {
            pr--;
            flag--;
            p[len++] = i;
        }
    }
    for(int i = len-1;i >= 1;i--)
    {
        printf("%d%c",p[i],i == 1 ? '\n' : ' ');
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

