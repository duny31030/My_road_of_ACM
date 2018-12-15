/*
 * =========================================================================
 *
 *       Filename:  hdu5952.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=5952
 *
 *        Version:  1.0
 *        Created:  2018/10/05 18时29分42秒
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
const int MAXN = 105;
vector<int> edge[MAXN];
bool m[MAXN][MAXN];
int T,N,M,S,u,v,p;
int flag;
int tot = 1;
int path[MAXN];
bool check(int now,int step)
{
    for(int i = 1;i <= step;i++)
    {
            if(!m[path[i]][now])
                return false;
    }
    return true;
}

void dfs(int st,int step)
{
    if(step == S)
    {
        p++;
        return ;
    }
    if(N-st < S-step)
        return ;
    int len = edge[st].size();
    for(int j = 0;j < len;j++)
    {
        if(check(edge[st][j],step))
        {
            path[tot++] = edge[st][j];
            dfs(edge[st][j],step+1);
            --tot;
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
    scanf("%d",&T);
    while(T--)
    {
        for(int i = 1;i <= N;i++)
            edge[i].clear();
        memset(m,0,sizeof m);
        scanf("%d %d %d",&N,&M,&S);
        for(int i = 1;i <= M;i++)
        {
            scanf("%d %d",&u,&v);
            if(u > v)
                swap(u,v);
            edge[u].push_back(v);
            m[u][v] = 1;
            m[v][u] = 1;
        }
        p = 0;
        int tmp = N-S+1;
        for(flag = 1;flag <= tmp;++flag)
        {
            path[tot++] = flag;
            dfs(flag,1);
            --tot;
        }
        printf("%d\n",p);
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


