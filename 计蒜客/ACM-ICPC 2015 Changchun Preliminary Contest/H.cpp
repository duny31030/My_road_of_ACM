/*
 * =========================================================================
 *
 *       Filename:  H.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/07 15时10分53秒
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
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

#define Key_value ch[ch[root][1]][0]
const int MAXN = 1010;
int pre[MAXN],ch[MAXN][2],size[MAXN],root;   
// ↑  父节点、左右孩子、子树规模、根节点、节点数量
int key[MAXN];   // 该点的值
int add[MAXN];   // 增量的延迟标记
ll sum[MAXN];   // 子树的和

int a[MAXN],que[MAXN];   // 初始的数组,建树的时候使用
int n,q,T;

void NewNode(int &r,int father,int num,int k)   // r必须加引用
{
    r = num;
    pre[r] = father;
    size[r] = 1;   // 必须是1
    key[r] = k;
    add[r] = sum[r] = ch[r][0] = ch[r][1] = 0;
}

// 给r为根的子树增加值,一定把当前节点的全部更新掉,再加个延迟标记表示儿子结点没更新
void Update_Add(int r,int ADD)
{
    if(r == 0)
        return ;
    add[r] += ADD;
    key[r] += ADD;
    sum[r] += (ll)ADD*size[r];
}

// 通过孩子结点更新父亲结点
void Push_Up(int r)
{
    size[r] = size[ch[r][0]] + size[ch[r][1]]+1;
    sum[r] = sum[ch[r][0]] + sum[ch[r][1]] + key[r];
}

// 将延迟标记更新到孩子结点
void Push_Down(int r)
{
    if(add[r])
    {
        Update_Add(ch[r][0],add[r]);
        Update_Add(ch[r][1],add[r]);
        add[r] = 0;
    }
}

// 建树🌲
// 先建立中间节点，再两端的方法
void Build(int &x,int l,int r,int father)
{
    if(l > r)
        return ;
    int mid = (l+r)>>1;
    NewNode(x,father,mid+1,a[mid]);
    Build(ch[x][0],l,mid-1,x);
    Build(ch[x][1],mid+1,r,x);
    Push_Up(x);
}

// 初始化,前后各加一个空结点
void Init()
{
    for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);

    root = ch[0][0] = ch[0][1] = pre[0] = size[0] = add[0] = sum[0] = key[0] = 0;
    NewNode(root,0,1,0);   // 头部加一个空位
    NewNode(ch[root][1],root,n+2,0);   // 尾部加一个空位
    Build(Key_value,1,n,ch[root][1]);
    Push_Up(ch[root][1]);
    Push_Up(root);
}

// 旋转 0为左旋,1为右旋   ←  该部分基本固定
void Rotate(int x,int kind)
{
    int y = pre[x];
    Push_Down(y);
    Push_Down(x);   // 先把y的标记向下传递,再把x的标记向下传递
    ch[y][!kind] = ch[x][kind];
    pre[ch[x][kind]] = y;
    if(pre[y])
        ch[pre[y]][ch[pre[y]][1] == y] = x;
    pre[x] = pre[y];
    ch[x][kind] = y;
    pre[y] = x;
    Push_Up(y);   // 维护y结点
}

// Splay调整,将结点r调整到goal下面
void Splay(int r,int goal)
{
    Push_Down(r);
    while(pre[r] != goal)
    {
        if(pre[pre[r]] == goal)
            Rotate(r,ch[pre[r]][0] == r);
        else 
        {
            int y = pre[r];
            int kind = ch[pre[y]][0] == y;
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
    Push_Up(r);
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

// 区间增加一个值
// 注意因为在前面增加了个结点,所以
// 把第1个结点旋转到根节点,第r+2个结点旋转到根结点的右孩子
// 那么Key_value(ch[ch[root][1]][0])刚好就是区间[l,r]
void ADD(int l,int r,int D)
{
    Splay(l,0);   // 第1个点到根节点
    Splay(r+2,root);   // 第r+2个点到根节点的右孩子
    Update_Add(Key_value,D);
    Push_Up(ch[root][1]);
    Push_Up(root);
}

ll Query_Sum(int l,int r)
{
    Splay(Get_kth(root,l),0);   // 第1个点到根节点
    Splay(Get_kth(root,r+2),root);   // 第r+2个点到根节点的右孩子
    return sum[Key_value];
}





void Find(int r,int k)
{
    int t = key[r];
    if(t == k)
    {
        cout << endl;
        return ;
    }
    if(t > k)
    {
        cout << "E";
        return Find(key[ch[r][0]],k);
    }
    else 
    {
        cout << "W";
        return Find(key[ch[r][1]],k);
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
        cin >> n;
        Init();
        cin >> q;
        rep(i,1,q)
        {
            cin >> que[i];
            if(que[i] == a[1])
            {
                cout << endl;
            }
            else 
            {
                Find(1,que[i]);
                cout << endl;
            }
        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

