/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=2544
 *
 *        Version:  1.0
 *        Created:  2018/08/11 18时55分28秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <algorithm>
#include <cstdio>
using namespace std;
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int ma[10010][10010],dis[10010];
bool vis[10010];
int n,m;
void dijstra()
{
    int i,k,t,mmin;
    memset(vis,0,sizeof vis);
    for(i = 1;i <= n;++i)
        dis[i] = ma[1][i];
    for(vis[1] = k = 1;k < n;k++)
    {
        for(mmin = INF,i = 1;i <= n;i++)
        {
            if(!vis[i] && mmin > dis[i])
            {
                mmin = dis[i];
                t = i;
            }
        }
        vis[t] = 1;
        for(int i = 1;i <= n;i++)
        {
            if(!vis[i] && dis[i] > mmin+ma[t][i])
                dis[i] = mmin+ma[t][i];
        }
    }
}
int a,b,c;
int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
        while(scanf("%d %d",&n,&m))
        {
            if(m == 0 && n == 0)
                break;
            for(int i = 1;i <= n;i++)
            {
                for(int j = 1;j <= n;j++)
                {
                    ma[i][j] = ma[j][i] = INF;
                }
            }
            for(int i = 1;i <= m;i++)
            {
                scanf("%d %d %d",&a,&b,&c);
                ma[a][b] = ma[b][a] = c;
            }
            dijstra();
            printf("%d\n",dis[n]);
        }
        fclose(stdin);
    // fclose(stdout);
    return 0;
}

