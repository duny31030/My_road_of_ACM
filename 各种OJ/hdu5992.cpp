/*
 * =========================================================================
 *
 *       Filename:  hdu5992.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=5992
 *
 *        Version:  1.0
 *        Created:  2018/10/10 14时25分05秒
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
const int N = 1e5+100;

struct node
{
    ll pos[10];
    int id;
}T[N],op,point;
int split[N],now,n,demension,q,t;
bool use[N];
ll ans,id;
double var[10];

bool cmp(node a,node b)
{
    return a.pos[split[now]] < b.pos[split[now]];
}

void Build(int L,int R)
{
    if(L > R)   return ;
    int mid = (L+R)>>1;
    // 求出每一维上面的方差
    for(int pos = 0;pos < demension;pos++)
    {
        double ave = var[pos] = 0.0;
        for(int i = L;i <= R;i++)
            ave += T[i].pos[pos];
        ave /= (R-L+1);
        for(int i = L;i <= R;i++)
            var[pos] += (T[i].pos[pos]-ave)*(T[i].pos[pos]-ave);
        var[pos] /= (R-L+1);
    }

    // 找到方差最大的那一维,用它来作为当前区间的split_method
    // split_method保存在split[mid]中
    split[now = mid] = 0;
    for(int i = 1;i < demension;i++)
        if(var[split[mid]] < var[i])    
            split[mid] = i;

    // 对区间排序，找到中间点
    nth_element(T+L,T+mid,T+R+1,cmp);
    Build(L,mid-1);
    Build(mid+1,R);
}
// 排序过后split[i]表示以i结点为中心点的分裂方式

void Query(int L,int R)
{
    if(L > R)   return ;
    int mid = (L+R) >> 1;
    
    // 求出目标点op到现在的根节点的距离
    ll dis = 0;
    for(int i = 0;i < demension;i++)
        dis += (op.pos[i]-T[mid].pos[i])*(op.pos[i]-T[mid].pos[i]);

    // 如果当前区间的根节点能够用来更新最近距离，并且dis小于已经求得的ans
    if(!use[T[mid].id] && dis<ans)
    {
        ans = dis;      // 更新最近距离
        point = T[mid]; // 更新取得最近距离下的点
        id = T[mid].id; // 更新取得最近距离的点的id
    }
    
    // 计算op到分裂平面的距离
    ll radius = (op.pos[split[mid]]-T[mid].pos[split[mid]])*(op.pos[split[mid]]-T[mid].pos[split[mid]]);

    // 对子区间进行查询
    if(op.pos[split[mid]] < T[mid].pos[split[mid]])
    {
        Query(L,mid-1);
        if(radius <= ans)   
            Query(mid+1,R);
    }
    else 
    {
        Query(mid+1,R);
        if(radius <= ans)
            Query(L,mid-1);
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
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        demension = 3;

    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

