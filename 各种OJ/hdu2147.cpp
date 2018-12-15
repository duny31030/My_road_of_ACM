/*
 * =========================================================================
 *
 *       Filename:  hdu2147.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=2147
 *
 *        Version:  1.0
 *        Created:  2018/10/04 21时17分54秒
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


int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int n,m;
    while(scanf("%d %d",&n,&m) != EOF)
    {
        if(n == 0 && m == 0)
            break;
        if(n*m % 2)
            printf("What a pity!\n");
        else 
            printf("Wonderful!\n");
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

