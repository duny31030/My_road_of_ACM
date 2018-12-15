/*
 * =========================================================================
 *
 *       Filename:  I.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=1540
 *
 *        Version:  1.0
 *        Created:  2018/09/15 12时22分38秒
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
const int N = 5e4+100;
int tot = 0;
int a[N];

struct node
{
    int l,r;
    int le,ri,mi;
}tree[N<<2];
// tree[i].le 区间左端点开始的最大连续个数
// tree[i].ri 区间右端点开始的最大连续个数
// tree[i].mi 区间最大的连续点的个数


void Build(int i,int l,int r)
{
    tree[i].l = l;
    tree[i].r = r;
    tree[i].le = tree[i].ri = tree[i].mi = r-l+1;
    if(r == l)
        return ;
    int mid = (l+r)>>1;
    Build(i<<1,l,mid);
    Build(i<<1|1,mid+1,r);
}

// val = 1 恢复这个点
// val = 0 破坏这个点
void Update(int i,int t,int val)
{
    if(tree[i].l == tree[i].r)
    {
        if(val == 1)
            tree[i].le = tree[i].ri = tree[i].mi = 1;
        else 
            tree[i].le = tree[i].ri = tree[i].mi = 0;
        return ;
    }
    int mid = (tree[i].l+tree[i].r)>>1;
    if(t <= mid)
        Update(i<<1,t,val);
    else 
        Update(i<<1|1,t,val);
    tree[i].le = tree[i<<1].le;
    tree[i].ri = tree[i<<1|1].ri;
    tree[i].mi = max(tree[i<<1].mi,tree[i<<1|1].mi);
    tree[i].mi = max(tree[i].mi,tree[i<<1].ri+tree[i<<1|1].le);

    if(tree[i<<1].le == tree[i<<1].r-tree[i<<1].l+1)
        tree[i].le += tree[i<<1|1].le;
    if(tree[i<<1|1].ri == tree[i<<1|1].r-tree[i<<1|1].l+1)
        tree[i].ri += tree[i<<1].ri;
}

int Query(int i,int t)
{
    if(tree[i].l == tree[i].r || tree[i].mi == 0 || tree[i].mi == tree[i].r-tree[i].l+1)
        return tree[i].mi;
    int mid = (tree[i].l+tree[i].r)>>1;
    if(t <= mid)
    {
        if(t >= tree[i<<1].r-tree[i<<1].ri+1)
            return Query(i<<1,t)+Query(i<<1|1,mid+1);
        else 
            return Query(i<<1,t);
    }
    else 
    {
        if(t <= tree[i<<1|1].l+tree[i<<1|1].le-1)
            return Query(i<<1|1,t)+Query(i<<1,mid);
        else 
            return Query(i<<1|1,t);
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
    int n,m,x;
    char op[10];
    while(scanf("%d %d",&n,&m) != EOF)
    {
        tot = 0;
        Build(1,1,n);
        rep(i,1,m)
        {
            // cin >> op;
            scanf("%s",op);
            if(op[0] == 'D')
            {
                scanf("%d",&x);
                a[tot++] = x;
                Update(1,x,0);
            }
            else 
            {
                if(op[0] == 'R')
                {   
                    x = a[--tot];
                    Update(1,x,1);
                }
                else 
                {
                    scanf("%d",&x);
                    printf("%d\n",Query(1,x));
                }
            }
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

