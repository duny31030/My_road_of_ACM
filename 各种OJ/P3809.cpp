/*
 * =========================================================================
 *
 *       Filename:  P3809.cpp
 *
 *           Link:  https://www.luogu.org/problemnew/show/P3809
 *
 *        Version:  1.0
 *        Created:  2018/09/21 00时08分38秒
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
const int N = 1e6+10;
char s[N];
int y[N],x[N],c[N],sa[N],height[N],wt[30];
int n,m;
void get_SA()
{
    for(int i = 1;i <= n;++i)   ++c[x[i]=s[i]];
    for(int i = 2;i <= m;++i)   c[i] += c[i-1];
    for(int i = n;i >= 1;--i)   sa[c[x[i]]--] = i;
    for(int k = 1;k <= n;k <<= 1)
    {
        int num = 0;
        for(int i = n-k+1;i <= n;++i)   y[++num] = i;
        for(int i = 1;i <= n;++i)   if(sa[i] > k)   y[++num] = sa[i]-k;
        for(int i = 1;i <= m;++i)   c[i] = 0;
        for(int i = 1;i <= n;++i)   ++c[x[i]];
        for(int i = 2;i <= m;++i)   c[i] += c[i-1];
        for(int i = n;i >= 1;--i)   sa[c[x[y[i]]]--] = y[i],y[i] = 0;
        swap(x,y);
        x[sa[1]] = 1;   num = 1;
        for(int i = 2;i <= n;++i)
            x[sa[i]] = (y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?num:++num;
        if(num == n)    break;
        m = num;
    }
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%s",s+1);
    n = strlen(s+1);
    m = 122;
    get_SA();
    printf("%d",sa[1]);
    rep(i,2,n)
        printf(" %d",sa[i]);
    printf("\n");

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

