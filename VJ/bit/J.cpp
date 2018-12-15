/*
 * =========================================================================
 *
 *       Filename:  J.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=3974
 *
 *        Version:  1.0
 *        Created:  2018/09/15 17时29分26秒
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
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=n;i>=a;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int MAXN = 5e4+100;
int T,N,M,u,v,x,y;
char op[10];

vector<vector<int> > G;
int s[MAXN],e[MAXN],du[MAXN],Index;

void dfs(int u)
{
    s[u] = ++Index;  // 相当于是记录u的起始下属下标，结束下标在递归回来的时候确定的
    int len = G[u].size();
    for(int i = 0;i < len;i++)
        dfs(G[u][i]);
    e[u] = Index;
}

struct node
{
    int l,r;
    int task,flag;   // flag表示区间是否被全部覆盖,task表示此区间的工作室什么
}tree[MAXN<<2];

void Build(int rt,int L,int R)
{
    tree[rt].l = L; tree[rt].r = R; tree[rt].task = -1;
    if(L == R)
        return ;
    int mid = (L+R)>>1;
    Build(rt<<1,L,mid);
    Build(rt<<1|1,mid+1,R);
}

void Down(int rt)
{
    if(tree[rt].flag && tree[rt].l != tree[rt].r)
    {
        tree[rt<<1].flag = tree[rt<<1|1].flag = tree[rt].flag;
        tree[rt<<1].task = tree[rt<<1|1].task = tree[rt].task;
        tree[rt].flag = 0;
    }
}

void Update(int rt,int L,int R,int task)
{
    if(tree[rt].l == L && tree[rt].r == R)
    {
        tree[rt].flag = 1;
        tree[rt].task = task;
        return ;
    }
    Down(rt);
    int mid = (tree[rt].l+tree[rt].r)>>1;
    if(R <= mid)
        Update(rt<<1,L,R,task);
    else 
        if(L > mid)
            Update(rt<<1|1,L,R,task);
        else 
        {
            Update(rt<<1,L,mid,task);
            Update(rt<<1|1,mid+1,R,task);
        }
}

int Query(int rt,int pos)
{
    Down(rt);   // 因为上面可能没有更新到最底部
    if(tree[rt].l == tree[rt].r)   // 找到叶子节点，并返回
        return tree[rt].task;

    int mid = (tree[rt].l+tree[rt].r)>>1;
    if(pos <= mid)
        return Query(rt<<1,pos);
    else 
        return Query(rt<<1|1,pos);
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
    rep(cas,1,T)
    {
        printf("Case #%d:\n",cas);
        clr(du,0);  clr(s,0);   clr(e,0);
        scanf("%d",&N);
        G.clear();
        G.resize(N+5);
        rep(i,2,N)
        {   
            scanf("%d %d",&u,&v);
            G[v].push_back(u);
            du[u] = 1;
        }
        Index = 0;
        rep(i,1,N)
        {
            if(!du[i])   // 找到根节点,然后按照递归的形式找到自己连续的下属
            {
                dfs(i);
                break;
            }
        }
        // 建树
        Build(1,1,N);
        scanf("%d",&M);
        rep(i,1,M)
        {
            scanf("%s",op);
            if(op[0] == 'C')
            {
                scanf("%d",&x);
                printf("%d\n",Query(1,s[x]));
            }
            else 
            {
                scanf("%d %d",&x,&y);
                Update(1,s[x],e[x],y);   // 更新的是x这个人的所有下属
            }
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

