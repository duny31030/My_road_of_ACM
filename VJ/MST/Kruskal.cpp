/*
 * =========================================================================
 *
 *       Filename:  Kruskal.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/09/26 11时26分29秒
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
struct Edge{int u,v,w;}edge[200005];
int fa[5005],n,m,ans,eu,ev,cnt;
inline bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
//快排的依据
inline int find(int x)
{
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
//并查集循环实现模板，及路径压缩，不懂并查集的同学可以戳一戳代码上方的“并查集详解”
inline int kruskal()
{
    ans = 0;
    for(int i = 0;i <= n;i++)   fa[i] = i;   // 初始化并查集
    sort(edge,edge+m,cmp);
    //将边的权值排序
    for(int i=0;i<m;i++)
    {
        eu=find(edge[i].u), ev=find(edge[i].v);
        if(eu==ev)
        {
            continue;
        }
        //若出现环，则continue
        ans+=edge[i].w;
        //将此边权计入答案
        fa[ev]=eu;
        if(++cnt==n-1)
        {
            break;
        }
        //循环结束条件，及边数为点数减一时
    }
    return ans;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d",&n,&m);
    for(int i = 0;i < m;i++)
    {
        scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    printf("%d\n",kruskal());
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

