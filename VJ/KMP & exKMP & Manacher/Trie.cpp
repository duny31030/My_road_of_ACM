/*
 * =========================================================================
 *
 *       Filename:  Trie.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/29 10时13分23秒
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
struct node 
{
    int Next[26];
    int v;
    void init()
    {
        v = 0;
        memset(Next,-1,sizeof Next);
    }
}trie[N];

int tot = 0;

void add(char a[],int len)
{
    int now = 0;
    for(int i = 0;i < len;i++)
    {
        int tmp = a[i]-'a';
        int next = trie[now].Next[tmp];
        if(next == -1)
        {
            next = ++tot;
            trie[next].v = -1;
            trie[next].init();
            trie[now].Next[tmp] = next;
        }
        now = next;
    }
    trie[now].v = 0;
}

int query(char a[],int len)
{
    int now = 0;
    for(int i = 0;i < len;i++)
    {
        int tmp = a[i]-'a';
        int next = trie[now].Next[tmp];
        if(next == -1)
        {
            return -1;
        }
        now = next;
    }
    return trie[now].v;
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

