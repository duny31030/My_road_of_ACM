/*
 * =========================================================================
 *
 *       Filename:  hdu1847.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=1847
 *
 *        Version:  1.0
 *        Created:  2018/10/04 21时12分21秒
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
const int N = 1e3+10;
int SG[N];
bool vis[N];
int f[15];
void getSG()
{
    int i,j;
    f[0] = 1;
    for(i = 1;i <= 12;i++)
        f[i] = f[i-1]*2;
    memset(SG,0,sizeof SG);
    for(i = 0;i < N;i++)
    {
        memset(vis,0,sizeof vis);
        for(j = 0;f[j] <= i && j <= 12;j++)
            vis[SG[i-f[j]]] = 1;
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
    int n;
    getSG();
    while(scanf("%d",&n) != EOF)
    {
        if(SG[n])
            printf("Kiki\n");
        else 
            printf("Cici\n");
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

