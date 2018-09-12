/*
 * =========================================================================
 *
 *       Filename:  BZOJ3676.cpp
 *
 *           Link:  https://www.lydsy.com/JudgeOnline/problem.php?id=3676
 *
 *        Version:  1.0
 *        Created:  2018/09/03 00时56分04秒
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
const int MAXN = 301000;
const int N = 26;
char s[MAXN];
struct node
{
    int next[N];   // next指针,next指针和字典树类似,指向的串为
                   // 当前穿两端加上同一个字符构成
    int fail;      // fail指针,失配后跳转到fail指针指向的节点
    int cnt;       // 表示节点i的本质不同的串的个数
                   // 建树时求出的不是完全的，最后count()函数跑一遍以后才是正确的
    int num;       // 表示以节点i表示的最长回文串的最右端点为回文串结尾的回文个数
    int len;       // 表示以当前节点表示的最长回文串长度（一个节点表示一个回文串）
    int S;         // 存放添加的字符
}pam[MAXN];
int last;   // 指向新添加一个字母后所形成的最长回文串表示的节点
int n;      // 表示添加的字符个数
int p;      // 表示添加的节点个数

// 新建节点
int newnode(int x)
{
    for(int i = 0;i < N;i++)
        pam[p].next[i] = 0;
    pam[p].cnt = 0;
    pam[p].num = 0;
    pam[p].len = x;
    return p++;
}

// 初始化
void init()
{
    p = 0;
    newnode(0);
    newnode(-1);
    last = 0;
    n = 0;
    pam[n].S = -1;   // 开头存放一个字符集中没有的字符,减少特判
    pam[0].fail = 1;
}

int get_fail(int x)
{
    while(pam[n-pam[x].len-1].S != pam[n].S)
        x = pam[x].fail;
    return x;
}

void Add(int c)
{
    c -= 'a';
    pam[++n].S = c;
    int cur = get_fail(last);   // 通过上一个回文串找这个回文串的匹配位置
    if(!pam[cur].next[c])       // 如果这个回文串没有出现过，说明出现了
                                // 一个新的本子不同的回文串
    {
        int now = newnode(pam[cur].len+2);   // 新建节点
        pam[now].fail = pam[get_fail(pam[cur].fail)].next[c];   
        // 和AC自动机一样建立fil指针,以便失败后回跳
        pam[cur].next[c] = now;
        pam[now].num = pam[pam[now].fail].num+1;
    }
    last = pam[cur].next[c];
    pam[last].cnt++;
}

void count()
{
    for(int i = p-1;i >= 0;--i)
    {
        pam[pam[i].fail].cnt += pam[i].cnt;
        // 父亲累加儿子才cnt,因为如果fail[v] = u , 则u一定是v的子回文串
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
    scanf("%s",s);
    int len = strlen(s);
    init();
    rep(i,0,len-1)
        Add(s[i]);
    count();
    ll pr = 0;
    rep(i,2,p-1)
    {
        pr = max((ll)pam[i].len*pam[i].cnt,pr);
    }
    printf("%lld\n",pr);
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

