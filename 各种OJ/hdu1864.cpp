/*
 * =========================================================================
 *
 *       Filename:  hdu1864.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=1846
 *
 *        Version:  1.0
 *        Created:  2018/10/05 11时00分30秒
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
int T,n,m;
int SG[N];
bool vis[N];
void getSG()
{
    int i,j;
    memset(SG,0,sizeof SG);
    for(i = 1;i <= n;i++)
    {
        memset(vis,0,sizeof vis);
        for(j = 1;j <= m && j <= i;j++)
            vis[SG[i-j]] = 1;
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
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        getSG();
        if(SG[n])
            printf("first\n");
        else 
            printf("second\n");
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

