/*
 * =========================================================================
 *
 *       Filename:  hdu2897.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=2897
 *
 *        Version:  1.0
 *        Created:  2018/10/05 20时55分08秒
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
const int N = 70000;
int SG[N];
bool vis[N];
int n,p,q;

void getSG()
{
    int i,j;
    memset(SG,0,sizeof SG);
    SG[1] = 0;
    SG[2] = 0;
    for(i = 3;i <= 100;i++)
    {
        memset(vis,0,sizeof vis);
        for(j = p;j <= q && j <= i;j++)
        {
            vis[SG[i-j]] = 1;
        }
        for(j = 0;;j++)
            if(!vis[j])
            {
                SG[i] = j;
                break;
            }
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
    while(scanf("%d %d %d",&n,&p,&q) != EOF)
    {
        // getSG();
        // for(int i = 1;i <= 20;i++)
        //    printf("SG[%d] = %d\n",i,SG[i]);
        if((n%(p+q) && (n%(p+q) <= p)))
            printf("LOST\n");
        else 
            printf("WIN\n");
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

