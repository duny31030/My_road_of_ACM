/*
 * =========================================================================
 *
 *       Filename:  C.cpp
 *
 *           Link:  https://www.nowcoder.com/acm/contest/141/C
 *
 *        Version:  1.0
 *        Created:  2018/07/26 15时11分38秒
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
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,n) for(int i=1;i<=n;i++)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int MAXN = 1e5+10;
#define Key_value ch[ch[root][1]][0]
int par[MAXN],ch[MAXN][2],size[MAXN],root,nodecnt;   
// ↑  父节点、左右孩子、子树规模、根节点、节点数量
int key[MAXN];   // 该点的值
int add[MAXN];   // 增量的延迟标记
ll sum[MAXN];   // 子树的和
int n,m,x,y;
int a[MAXN];   // 初始的数组,建树的时候使用
bool rev[MAXN];

void NewNode(int &r,int father,int num,int k)   // r必须加引用
{
    r = num;
    par[r] = father;
    size[r] = 1;   // 必须是1
    key[r] = k;
    ch[r][0] = ch[r][1] = 0;
    rev[r] = 0;
}

void Update_Rev(int x)
{
    if(x == 0)
        return ;
    swap(ch[x][0],ch[x][1]);
    rev[x] ^= 1;
}



// 通过孩子结点更新父亲结点
void Push_Up(int r)
{
    size[r] = size[ch[r][0]] + size[ch[r][1]]+1;
    // sum[r] = sum[ch[r][0]] + sum[ch[r][1]] + key[r];
}

// 将延迟标记更新到孩子结点
void Push_Down(int r)
{
    if(rev[r])
    {
        Update_Rev(ch[r][0]);
        Update_Rev(ch[r][1]);
        rev[r] = 0;
    }
    /*
    if(add[r])
    {
        Update_Add(ch[r][0],add[r]);
        Update_Add(ch[r][1],add[r]);
        add[r] = 0;
    }
    */
}

// 建树🌲
// 先建立中间节点，再两端的方法
void Build(int &x,int l,int r,int father)
{
    if(l>r) return ;
    int mid = (l+r)/2;
    NewNode(x,father,mid+1,a[mid]);
    Build(ch[x][0],l,mid-1,x);
    Build(ch[x][1],mid+1,r,x);
    Push_Up(x);
}

// 初始化,前后各加一个空结点
void Init()
{
    root = nodecnt = 0;
    for(int i = 1;i <= n;i++)   a[i] = i;
    ch[root][0] = ch[root][1] = size[root] = key[root] = par[root] = rev[root] = 0;
    // root = ch[0][0] = ch[0][1] = par[0] = size[0] = add[0] = sum[0] = key[0] = 0;
    NewNode(root,0,1,0);   // 头部加一个空位
    NewNode(ch[root][1],root,n+2,0);   // 尾部加一个空位
    Build(Key_value,1,n,ch[root][1]);
    Push_Up(ch[root][1]);
    Push_Up(root);
}


// 旋转 0为左旋,1为右旋   ←  该部分基本固定
void Rotate(int x,int kind)
{
    int y = par[x];
    Push_Down(y);
    Push_Down(x);   // 先把y的标记向下传递,再把x的标记向下传递
    ch[y][!kind] = ch[x][kind];
    par[ch[x][kind]] = y;
    if(par[y])
        ch[par[y]][(ch[par[y]][1] == y)] = x;
    par[x] = par[y];
    ch[x][kind] = y;
    par[y] = x;
    Push_Up(y);   // 维护y结点
    Push_Up(x);
}

// Splay调整,将结点r调整到goal下面
void Splay(int r,int goal)
{
    Push_Down(r);
    while(par[r] != goal)
    {
        if(par[par[r]] == goal)
        {
            Push_Down(par[x]);
            Push_Down(x);
            Rotate(r,ch[par[r]][0] == r);
        }
        else 
        {
            Push_Down(par[par[x]]);
            Push_Down(par[x]);
            Push_Down(x);
            int y = par[r];
            int kind = (ch[par[y]][0] == y);
            if(ch[y][kind] == r)
            {
                Rotate(r,!kind);
                Rotate(r,kind);
            }
            else 
            {
                Rotate(y,kind);
                Rotate(r,kind);
            }
        }
    }
    // Push_Up(r);
    if(goal == 0)
        root = r;
}

// 得到第k个结点
int Get_kth(int r,int k)
{
    Push_Down(r);
    int t = size[ch[r][0]]+1;
    if(t == k)
        return r;
    if(t > k)
        return Get_kth(ch[r][0],k);
    else 
        return Get_kth(ch[r][1],k-t);
}

int Get_Min(int r)
{
    Push_Down(r);
    while(ch[r][0])
    {
        r = ch[r][0];
        Push_Down(r);
    }
    return r;
}

int Get_Max(int r)
{
    Push_Down(r);
    while(ch[r][1])
    {
        r = ch[r][1];
        Push_Down(r);
    }
    return r;
}

ll Query_Sum(int l,int r)
{
    Splay(Get_kth(root,l),0);   // 第1个点到根节点
    Splay(Get_kth(root,r+2),root);   // 第r+2个点到根节点的右孩子
    return sum[Key_value];
}

void Move(int l,int r,int p)   // 截取[l,r]放到位置p之后
{
    Splay(Get_kth(root,l-1+1),0);   // l的前驱l-1伸展到根
    Splay(Get_kth(root,r+1+1),root);   // r的后继r+1伸展到根的右孩子
    int tmp = Key_value;   
    Key_value = 0;   // 剥离[l,r]子树
    Push_Up(ch[root][1]);
    Push_Up(root);
    Splay(Get_kth(root,p+0+1),0);   // p伸展到根
    Splay(Get_kth(root,p+1+1),root);   // p的后继p+1伸展到根的右孩子
    Key_value = tmp;
    par[Key_value] = ch[root][1];   // 接上[l,r]子树
    Push_Up(ch[root][1]);
    Push_Up(root);
}


// 反转[l,r]区间
void Reverse(int l,int r)
{
    Splay(Get_kth(root,l-1+1),0);
    Splay(Get_kth(root,r+1+1),root);
    Update_Rev(Key_value);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
int tot;
void Inorder(int x)
{
    if(!x)
        return ;
    Push_Down(x);
    Inorder(ch[x][0]);
    tot++;
    if(tot >= 2 && tot <= n+1)
    {
        if(tot > 2)
            printf(" ");
        printf("%d",key[x]);
    }
    Inorder(ch[x][1]);
}


int main()
{
    // ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d",&n,&m);
    Init();
    rep(i,m)
    {
        scanf("%d %d",&x,&y);
        y = x+y-1;
//        if(i%2)
//            Move(x,y,0);         
//        else 
        if(x != 1)
        {
            Reverse(1,x-1);
            Reverse(x,y);
            Reverse(1,y);
        }
    }
    Inorder(root);
    printf("\n");
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

