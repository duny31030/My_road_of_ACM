/*
 * =========================================================================
 *
 *       Filename:  1050.cpp
 *
 *           Link:  http://172.17.21.15/problem.php?id=1050
 *
 *        Version:  1.0
 *        Created:  2018/10/16 19时49分36秒
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
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6+100;
int T,n;
int tot = 1;
char s[20];

struct node
{
    int son[12];
    int cnt;
    bool have;
    void clear()
    {
        memset(son,0,sizeof son);
        cnt = 0;
        have = false;
    }
}trie[N];

bool Insert(char *s)
{
    int len = strlen(s);
    int u = 0,v;
    bool b = 0;
    for(int i = 0;i < len;i++)
    {
        v = s[i]-'0'+1;
        if(!trie[u].son[v])
        {
            if(trie[u].have)
                b = 1;
            trie[u].son[v] = tot++;
        }
        u = trie[u].son[v];
    }
    if(b)   return 1;
    trie[u].have = true;
    for(int i = 1;i <= 10;i++)
        if(trie[u].son[i])
            b = 1;
    if(b)   return 1;
    return 0;
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
    while(T--)
    {
        trie[0].clear();
        scanf("%d",&n);
        bool flag = 1;
        rep(i,1,n)
        {
            scanf("%s",s);
            if(flag)
            {
                flag = !Insert(s);
            }
        }
        if(!flag)
            printf("NO\n");
        else 
            printf("YES\n");
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

