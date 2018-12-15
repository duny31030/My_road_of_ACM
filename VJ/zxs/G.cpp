/*
 * =========================================================================
 *
 *       Filename:  G.cpp
 *
 *           Link:  http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=2112
 *
 *        Version:  1.0
 *        Created:  2018/09/11 18时36分17秒
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
#define lowbit(a) a&(-a)
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 200050;

int cnt,siz,dot,idx;
// 内存分配的下标,不同数值点的个数,总共的点数,修改操作的下标
int root[N],cpy[N],data[N];
// 静态主席树的根节点,离散化后的数据,原始数据
int vir[N],use[N];
// 树状数组的节点,计算前缀和时向前走的节点

// 因为主席树必须离线,所以将指令存下来
struct order
{
    bool typ;   // 标记查询还是修改
    int from,to,k;
}command[N];

struct node
{int son[2],sum;}tree[N*250];
// 内存一定要开的足够大,因为在这里静态主席树和树状数组共用这个数组内的点

int build(int l,int r)   // 建立空树 类似线段树
{
    int now = cnt++;
    tree[cnt].sum = 0;
    if(l != r)
    {
        int mid = (l+r)>>1;
        tree[now].son[0] = build(l,mid);
        tree[now].son[1] = build(mid+1,r);
    }
    return now;
}

int updata(int last,int pos,int val)   // 更新虚拟节点或者插入静态主席树的函数
// 为了方便删除,传入val代表修改的量
{
    int now = cnt++,tmp = now,mid;
    int l = 0,r = siz-1;   // 保存的是离散化后的对应的值的编号
    tree[now].sum = tree[last].sum+val;
    while(l < r)
    {
        mid = (l+r)>>1;
        if(pos <= mid)   // 待插入节点在左子树
        {
            tree[now].son[1] = tree[last].son[1];
            // 那么当前节点的右子树节点和之前的那棵权值线段树共用节点
            tree[now].son[0] = cnt++;   // 向左新开一个节点
            now  = tree[now].son[0];
            last = tree[last].son[0];
            r = mid;
        }
        else            // 待插入节点在右子树 
        {
            tree[now].son[0] = tree[last].son[0];
            tree[now].son[1] = cnt++;
            now  = tree[now].son[1];
            last = tree[last].son[1];
            l = mid+1;
        }
        tree[now].sum = tree[last].sum+val;
    }
    return tmp;
}

void add(int now,int pos,int val)
{
    while(now <= dot)
    {
        vir[now] = updata(vir[now],pos,val);
        now += lowbit(now);
    }
}

int getsum(int now)   // 查询当前点更改值的左子树的大小
{
    int ret = 0;
    while(now > 0)
    {
        ret += tree[tree[use[now]].son[0]].sum;
        now -= lowbit(now);
    }
    return ret;
}

int query(int l,int r,int kth)
{
    int left_root  = root[l-1];  // 静态主席树的两个相减的根节点
    int right_root = root[r];
    int lef = 0,rig = siz-1;     // 查询时左右范围
    for(int i = l-1;i;i -= lowbit(i))  use[i] = vir[i];
    // 初始化更改值的路径
    for(int i = r;i;i -= lowbit(i))    use[i] = vir[i];
    while(lef < rig)
    {
        int mid = (lef+rig)>>1;
        int now_sum = getsum(r)-getsum(l-1)+tree[tree[right_root].son[0]].sum-tree[tree[left_root].son[0]].sum;
        // 查询当前点的左儿子是否满足达到了k个
        // 在静态主席树和树状数组上一起算
        if(now_sum >= kth)   // 达到了
        {
            rig = mid;
            for(int i = l-1;i;i -= lowbit(i))   use[i] = tree[use[i]].son[0];
            // 将查询范围缩小至左子树内
            for(int i = r;i;i -= lowbit(i))     use[i] = tree[use[i]].son[0];
            left_root  = tree[left_root].son[0];   // 同时静态主席树也要如此
            right_root = tree[right_root].son[0];
        }
        else   // 没达到就在右子树范围内继续查找 
        {
            lef = mid+1;
            kth -= now_sum;   // 因为有了左子树的一部分点,所以要减去
            for(int i = l-1;i;i -= lowbit(i))   use[i] = tree[use[i]].son[1];
            for(int i = r;i;i -= lowbit(i))     use[i] = tree[use[i]].son[1];
            left_root  = tree[left_root].son[1];
            right_root = tree[right_root].son[1];
        }
    }
    return lef;   // 返回是第几个离散出来的数据
}

int id(int now)
{
    return lower_bound(cpy,cpy+siz,now)-cpy;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        int num;
        read(dot),read(num);
        // scanf("%d %d",&dot,&num);
        idx = dot;
        for(int i = 1;i <= dot;i++)
        {
            read(data[i]);
            // scanf("%d",&data[i]);
            cpy[i-1] = data[i];   // cpy从0开始存方便unique和sort
        }
        char c;
        for(int i = 1;i <= num;i++)
        {
            // read(c); 
            // getchar();
            scanf("%c",&c);
            getchar();
            if(c == 'Q')
            {
                command[i].typ = false;
                read(command[i].from),read(command[i].to),read(command[i].k);
                // scanf("%d %d %d",&command[i].from,&command[i].to,&command[i].k);
            }
            else 
            {
                command[i].typ = true;
                read(command[i].from),read(command[i].k);
                // scanf("%d %d",&command[i].from,&command[i].k);
                cpy[idx++] = command[i].k;   // 如果是修改的话存入cpy中
            }
        }
        sort(cpy,cpy+idx);
        siz = unique(cpy,cpy+idx)-cpy;
        root[0] = build(0,siz-1);    // 建立空静态主席树
        for(int i = 1;i <= dot;i++)
            root[i] = updata(root[i-1],id(data[i]),1);   // 建立满的静态主席树
        for(int i = 1;i <= dot;++i)
            vir[i] = root[0];         // 初始化树状数组
        for(int i = 1;i <= num;i++)   // 处理指令
        {
            if(!command[i].typ)
                writeln(cpy[query(command[i].from,command[i].to,command[i].k)]);
            else 
            {
                add(command[i].from,id(data[command[i].from]),-1);
                add(command[i].from,id(command[i].k),1);
                data[command[i].from] = command[i].k;   // 将原数据修改至新数据
            }
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


