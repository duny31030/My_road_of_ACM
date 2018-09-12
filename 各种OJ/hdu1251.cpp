/*
 * =========================================================================
 *
 *       Filename:  hdu1251.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=1251
 *
 *        Version:  1.0
 *        Created:  2018/08/29 11时40分08秒
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
const int N = 1000010;
struct node
{
    int next[27];
}trie[N];
int num[N];   // 以某一字符串为前缀的单词的数量
int tot = 1;
char s[20];
void add(char a[])
{
    int i,now = 0;
    int len = strlen(a);
    for(i = 0;i < len;i++)
    {
        int tmp = a[i]-'a'+1;
        int next = trie[now].next[tmp];
        if(!next)   // 如果对应字符还没有值
            trie[now].next[tmp] = tot++;
        now = trie[now].next[tmp];
        num[now]++;
    }
}

int query(char a[])
{
    int len = strlen(a);
    int now = 0,i;
    for(i = 0;i < len;i++)
    {
        int tmp = a[i]-'a'+1;
        if(trie[now].next[tmp] == 0)
            return 0;
        now = trie[now].next[tmp];
    }
    return num[now];
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    while(gets(s))
    {
        if(!s[0])
            break;
        add(s);
    }
    while(gets(s))
    {
        printf("%d\n",query(s));
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

