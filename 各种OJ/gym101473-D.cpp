/*
 * =========================================================================
 *
 *       Filename:  gym101473-D.cpp
 *
 *           Link:  http://codeforces.com/gym/101473/attachments
 *
 *        Version:  1.0
 *        Created:  2018/10/29 21时05分30秒
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
int n,m;
int a[30],b[30],ta[30];

bool check(int len)
{
    bool l1 = 0,l2 = 0;
    for(int i = 1;i <= len;i++) if(ta[i] != b[i])  l1 = 1;
    for(int i = 1;i <= len;i++) if(ta[i] != b[len-i+1]) l2 = 1;
    if(l1 && l2)    return 0;
    return 1;
}

bool flag = 0;
int l,r,sv;
void dfs(int len)
{
    if(flag)    return ;
    if(len < m) return ;
    if(len == m)
    {
        if(check(len))
        {
            printf("S\n");
            flag = 1;
        }
        return ;
    }
    int tta[30];
    for(int i = 1;i < len;i++)
    {
        l = i,r = len-i;
        // 备份
        for(int j = 1;j <= len;j++) tta[j] = ta[j];

        if(l < r)
        {
            for(int k = i,g = i+1;k && g <= len;k--,g++)    ta[g] += ta[k];
            for(int j = 1;j <= r;j++)   ta[j] = ta[j+l];
        }
        else 
        {
            for(int k = i,g = i+1;k && g <= len;k--,g++)    ta[k] += ta[g];
        }
        sv = max(l,r);
        dfs(sv);
        for(int j = 1;j <= len;j++) ta[j] = tta[j];
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
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i = 1;i <= m;i++)   scanf("%d",&b[i]);
    for(int i = 1;i <= n;i++)   ta[i] = a[i];
    if(n == m)
    {
        if(check(n))
            printf("S\n");
        else 
            printf("N\n");
        return 0;
    }
    dfs(n);
    if(!flag)
        printf("N\n");

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

