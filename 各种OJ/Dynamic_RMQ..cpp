/*
 * =========================================================================
 *
 *       Filename:  Dynamic_RMQ.cpp
 *
 *           Link:  Rujia Liu 模板 
 *           
 *        Version:  1.0
 *        Created:  2018/07/23 15时51分53秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.github.io/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int maxnode = 1<<17;
// 输入格式
// n m 数组范围是a[1]~a[n],初始化为0。操作有m个
// 1 p v 表示设a[p] = v
// 2 L R 查询a[L]~a[R]的min
int op,qL,qR,p,v;   // qL和qR为全局变量，询问区间[qL,qR]
struct IntervalTree
{
    int minv[maxnode];
    
    void update(int o,int L,int R)
    {
        int M = L+(R-L)/2;
        if(L == R)
            minv[o] = v;   // 叶节点,直接更新
        else 
        {
            // 先递归更新左子树或右子树
            if(p <= M)
                update(o*2,L,M);
            else 
                update(o*2+1,M+1,R);
            // 然后计算本节点的minv
            minv[o] = min(minv[o*2],minv[o*2+1]);
        }
    }

    int query(int o,int L,int R)
    {
        int M = L+(R-L)/2,ans = INF;
        if(qL <= L && R <= qR)
            return minv[o];   // 当前节点完全包含在查询区间内
        if(qL <= M)
            ans = min(ans,query(o*2,L,M));   // 往左走
        if(M < qR)
            ans = min(ans,query(o*2+1,M+1,R));   // 往右走
        return ans;
    }
};// 18366168337

IntervalTree tree;

int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(&tree,0,sizeof tree);
        while(m--)
        {
            scanf("%d",&op);
            if(op == 1)
            {
                scanf("%d %d",&p,&v);
                tree.update(1,1,n);   // 修改树节点，或者是建树的过程
            }
            else 
            {
                scanf("%d %d",&qL,&qR);   // 修改询问区间
                printf("%d\n",tree.query(1,1,n));
            }
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

