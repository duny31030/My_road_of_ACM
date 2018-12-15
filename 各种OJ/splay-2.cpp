/*
 * =========================================================================
 *
 *       Filename:  splay-2.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/11/03 10时23分09秒
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
const int INF = 2147483647;
const int mod = 1e9 + 7;
const int N = 100000+5;

int n,m;
int cnt = 0;
int root = 0;

struct node
{
    int fa;     // 记录父亲节点
    int ch[2];  // ch[0] 左儿子 ch[1] 右儿子
    int val;    // 记录节点权值
    int size;   // 记录节点子数大小(包括该节点)
    int cnt;    // 记录同样权值的元素个数
    int mark;   // 记录反转区间标记(普通平衡树不用)
}t[N];

bool get(int x)
{
    return t[t[x].fa].ch[1] == x;
    // 是右儿子返回1 左儿子返回0
}

void up(int x)
{
    t[x].size = t[t[x].ch[0]].size+t[t[x].ch[1]].size+t[x].cnt;
}

void rotate(int x)
{
    int fa = t[x].fa,gfa = t[fa].fa;
    int d1 = get(x),d2 = get(fa);
    t[fa].ch[d1] = t[x].ch[d1^1];   t[t[x].ch[d1^1]].fa = fa;
    t[gfa].ch[d2] = x;  t[x].fa = gfa;
    t[fa].fa = x;   t[x].ch[d1^1] = fa;
    up(fa); up(x);   // up是收集节点子树的个数
}

void splay(int x,int goal)
{
    while(t[x].fa != goal)
    {
        int fa = t[x].fa,gfa = t[fa].fa;
        int d1 = get(x),d2 = get(fa);
        if(gfa != goal)
        {
            if(d1 == d2)    rotate(fa);
            else    rotate(x);
        }
        rotate(x);
    }
    if(goal == 0)   root = x;
}

void insert(int val)
{
    int node = root,fa = 0;
    while(node && t[node].val != val)
        fa = node,node = t[node].ch[t[node].val<val];
    if(node)    t[node].cnt++;
    else 
    {
        node = ++cnt;
        if(fa)  t[fa].ch[t[fa].val<val] = node;
        t[node].fa = fa;
        t[node].val = val;
        t[node].cnt = 1;
        t[node].size = 1;
    }
    splay(node,0);
}

void pushdpwn(int x)
{
    t[t[x].ch[0]].mark ^= 1;
    t[t[x].ch[1]].mark ^= 1;
    t[x].mark = 0;
    swap(t[x].ch[0],t[x].ch[1]);
}

int kth(int k)
{
    int node = root;
    while(1)
    {
        int son = t[node].ch[0];
        if(k <= t[son].size)    node = son;
        else 
        {
            if(k > t[son].size+t[node].cnt)
            {
                k -= t[son].size+t[node].cnt;
                node = t[node].ch[1];
            }
            else 
                return t[node].val;
        }
    }
}

int kth1(int k)
{
    int node = root;
    while(1)
    {
        if(t[node].mark)    pushdpwn(node);
        int son = t[node].ch[0];
        if(k <= t[son].size)
            node = son;
        else 
            if(k > t[son].size+1)
            {
                k -= t[son].size+1;
                node = t[node].ch[1];
            }
            else 
            {
                return node;
            }
    }
}

void work(int l,int r)
{
    int left = kth1(l),right = kth1(r);
    splay(left,0);  splay(right,left);
    t[t[t[root].ch[1]].ch[0]].mark ^= 1;
}

void output(int x)
{
    if(t[x].mark)   pushdpwn(x);
    if(t[x].ch[0])  output(t[x].ch[0]);
    if(t[x].val >= 1 && t[x].val <= n)  printf("%d ",t[x].val);
    if(t[x].ch[1])  output(t[x].ch[1]);
}

int find(int val)
{
    int node = root;
    while(t[node].val != val && t[node].ch[t[node].val < val])
        node = t[node].ch[t[node].val<val];
    return node;
}

int get_rank(int val)
{
    splay(find(val),0);
    return t[t[root].ch[0]].size;
}

int get_pre(int val,int kind)
{
    splay(find(val),0);
    int node = root;
    if(t[node].val < val && kind == 0)  return node;
    if(t[node].val > val && kind == 1)  return node;
    node = t[node].ch[kind];
    while(t[node].ch[kind^1])
        node = t[node].ch[kind^1];
    return node;
}

void delet(int val)
{
    int last = get_pre(val,0);
    int next = get_pre(val,1);
    splay(last,0);  splay(next,last);
    if(t[t[next].ch[0]].cnt > 1)
    {
        t[t[next].ch[0]].cnt--;
        splay(t[next].ch[0],0);
    }
    else 
        t[next].ch[0] = 0;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    insert(-INF);   insert(INF);
    int x,y;
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++)   insert(i);
    for(int i = 1;i <= m;i++)
    {
        scanf("%d %d",&x,&y);
        work(x,y+2);
    }
    output(root);
    printf("\n");
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

