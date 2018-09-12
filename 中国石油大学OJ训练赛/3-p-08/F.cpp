/*
 * =========================================================================
 *
 *       Filename:  F.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/17 01时24分30秒
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


int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int n,k;
    scanf("%d %d",&n,&k);
    if(n%2 == 0)
    {
        for(int i = 1;i <= k;i++)
        {
            printf("%d%c",i == 1?n/2:n,i == k?:' ');
        }
    }
    else 
    {
        for(int i = 1;i <= k;i++)
        {
            printf("%d%c",i != k?(n+1)/2:(n+1)/2-k/2,i == k?:' ');
        }
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

