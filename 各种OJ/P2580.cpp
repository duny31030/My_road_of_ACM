/*
 * =========================================================================
 *
 *       Filename:  P2580.cpp
 *
 *           Link:  https://www.luogu.org/problemnew/show/P2580
 *
 *        Version:  1.0
 *        Created:  2018/08/31 14时42分32秒
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
const int N = 1e6;
int num = 0;
int n,m;
char name[60];
string p[3];
struct node
{
    int son[26];
    int cnt;
    int have;
    node()
    {
        clr(son,0);
        cnt = 0;
        have = false;
    }
}trie[N];

void Insert(char *s)
{
    int len = strlen(s);
    int u = 0,v;
    rep(i,0,len-1)
    {
        v = s[i]-'a';
        if(!trie[u].son[v])
            trie[u].son[v] = ++num;
        u = trie[u].son[v];
    }
    trie[u].have = true;
}

int Find(char *s)
{
    int len = strlen(s);
    int u = 0,v;
    rep(i,0,len-1)
    {
        v = s[i]-'a';
        if(!trie[u].son[v])   // 没有这个单词
            return 2;
        u = trie[u].son[v];
    }
    if(!trie[u].have)
        return 1;
    if(!trie[u].cnt)
    {
        trie[u].cnt++;
        return 0;
    }
    return 1;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    p[0] = "OK";
    p[1] = "REPEAT";
    p[2] = "WRONG";
    scanf("%d",&n);
    rep(i,1,n)
    {
        scanf("%s",name);
        Insert(name);
    }
    scanf("%d",&m);
    rep(i,1,m)
    {
        scanf("%s",name);
        cout << p[Find(name)] << endl;
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

