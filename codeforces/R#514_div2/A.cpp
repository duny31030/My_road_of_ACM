/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/05 22时34分59秒
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
const int N = 1e5+100;
int n,L,a;
int t[N];
int l[N];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d %d",&n,&L,&a);
    rep(i,1,n)
    {
        scanf("%d %d",&t[i],&l[i]);
    }
    int end = 0;
    int p = 0;
    for(int i = 1;i <= n;i++)
    {
        if(t[i]-end >= a)
        {    
            p += (t[i]-end)/a;
        }
        end = t[i]+l[i];
    }
    p += (L-end)/a;
    printf("%d\n",p);
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

