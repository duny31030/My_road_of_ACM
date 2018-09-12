/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/26 13时07分58秒
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
int n;
int a[60];

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
        scanf("%d",&a[i]);
    }
    map<int,bool> m;
    for(int i = n;i >= 1;i--)
    {
        if(m[a[i]] == 1)
        {

            a[i] = -1;
        }
        m[a[i]] = 1;
    }


    int flag = 0;
    int pr = 0;
    rep(i,1,n)
    {
        if(a[i] != -1)
            pr++;
    }
    printf("%d\n",pr);
    rep(i,1,n)
        if(a[i] != -1)
        {
            printf("%d",a[i]);
            flag = i;
            break;
        }
    rep(i,flag+1,n)
        if(a[i] != -1)
            printf(" %d",a[i]);
    printf("\n");
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

