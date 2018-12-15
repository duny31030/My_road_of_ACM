/*
 * =========================================================================
 *
 *       Filename:  G.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/19 18时44分54秒
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

int a[1010];
int n,q;
int in,tmp1,tmp2;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d",&n,&q);
    rep(i,1,n)
    {
        scanf("%d",&a[i]);
    }
    rep(i,1,q)
    {
        tmp2 = INF;
        scanf("%d %d",&tmp1,&in);
        int tmp3 = 1;
        while(tmp1)
        {
            tmp3 *= 10;
            tmp1--;
        }
        
        rep(i,1,n)
        {
            if(a[i]%tmp3 == in)
                if(tmp2 >= a[i])
                    tmp2 = a[i];
        }
        if(tmp2 == INF)
            printf("-1\n");
        else 
            printf("%d\n",tmp2);
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

