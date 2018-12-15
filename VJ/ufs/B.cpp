/*
 * =========================================================================
 *
 *       Filename:  B.cpp
 *
 *           Link:  https://vjudge.net/problem/10536/origin
 *
 *        Version:  1.0
 *        Created:  2018/09/18 11时26分26秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
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
const int N = 3e4+10;
int f[N];

int find(int x)
{
    if(f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}

int n,m,tmp;
int a[N];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    while(scanf("%d %d",&n,&m))
    {
        rep(i,0,n)
            f[i] = i;
        if(n == m && n == 0)
            break;
        rep(i,1,m)
        {
            scanf("%d",&tmp);
            scanf("%d",&a[1]);
            rep(j,2,tmp)
            {
                scanf("%d",&a[j]);
                int k1 = find(a[j]);
                int k2 = find(a[1]);
                if(k1 != k2)
                {
                    f[k1] = k2;
                }
            }
        }
        ll pr = 0;
        tmp = find(0);
        rep(i,0,n-1)
        {
            if(find(i) == f[0])
                pr++;
        }
        printf("%lld\n",pr);
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

