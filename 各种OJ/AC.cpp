/*
 * =========================================================================
 *
 *       Filename:  AC.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/09/02 09时02分43秒
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
const int N = 5e5+10;
queue<int> q;
struct node
{
    int next[26];   // 子节点的位置
    int fail;       // 失配指针
    int count;      // 标记有几个单词以这个节点结尾
    void init()
    {
        memset(next,-1,sizeof next);
        fail = 0;
        count = 0;
    }
}ac[N];

int tot = 0;

// 插入
void Insert(char str[])
{
    int len = strlen(str);
    int now = 0;   // 字典树的当前指针
    int tmp;
    for(int i = 0;i < len;i++)
    {
        tmp = str[i]-'a';
        if(ac[now].next[tmp] == 0)     // Trie树没有这个子节点
            ac[now].next[tmp] = ++tot; // 构造出来
        now = ac[now].next[tmp];       // 向下构造
    }
    ac[now].count++;   // 标记单词结尾
}

// 构造fail指针
void MakeFail()
{
    queue<int> q;   // 队列
    for(int i = 0;i < 26;i++)   // 第二层的fail指针提前处理一下
    {
        if(ac[0].next[i] != 0)
        {
            ac[ac[0].next[i]].fail = 0;   // 指向根节点
            q.push(ac[0].next[i]);        // 压入队列
        }
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0;i < 26;i++)    // 枚举所有子节点
        {
            if(ac[u].next[i] != 0)   // 存在这个子节点
            {
                ac[ac[u].next[i]].fail = ac[ac[u].fail].next[i];
                // 子节点的fail指针指向当前节点的
                // fial指针所指向的结点的相同子节点
                q.push(ac[u].next[i]);   // 压入队列
            }
            else 
                ac[u].next[i] = ac[ac[u].fail].next[i];
                // 当前节点的这个子节点指向
                // 当前节点fial指针的子节点
        }
    }
}

// AC自动机匹配
int Query(char s[])
{
    int len = strlen(s);
    int now = 0,ans = 0,tmp;
    for(int i = 0;i < len;i++)
    {
        tmp = s[i]-'a';
        now = ac[now].next[tmp];   // 向下一层
        for(int t = now;t && ac[t].count != -1;t = ac[t].fail)   // 循环求解
        {
            ans += ac[t].count;
            ac[t].count = -1;
        }
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



    fclose(stdin);
    // fclose(stdout);
    return 0;
}

