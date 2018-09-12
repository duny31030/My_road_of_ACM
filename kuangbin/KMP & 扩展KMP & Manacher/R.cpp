/*
 * =========================================================================
 *
 *       Filename:  R.cpp
 *
 *           Link:  http://poj.org/problem?id=3376
 *
 *        Version:  1.0
 *        Created:  2018/08/29 22时14分31秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
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
const int N = 2e6+20;

struct node
{
    int next[26];
    int leaf;   // 以这个节点为终点的叶子节点个数
    int count;  // 后边回文串的数量

    void Free()
    {
        leaf = count = 0;
        clr(next,0);
    }
}trie[N];

int top;   // 配合字典树使用,表示没有使用的内存
int start[N],p[N<<1];
char str[N],estr[N<<1];
bool sf[N];   // 后缀是否是回文
bool pf[N];   // 前缀是否是回文

void BuildTrie(int n)
{
    int p = 0;
    for(int i = start[n+1]-1;i >= start[n];i--)
    {
        int k = str[i]-'a';
        // trie[p].count += pf[i];
        if(pf[i])
            trie[p].count++;
        if(trie[p].next[k] == 0)
        {
            trie[p].next[k] = ++ top;
            trie[top].Free();
        }
        p = trie[p].next[k];
    }
    trie[p].leaf += 1;
}

void Manacher(int n)
{
    int i,id = 0,len = 1;
    estr[0] = '$';
    for(i = start[n];i < start[n+1];i++)
    {
        estr[len++] = '#';
        estr[len++] = str[i];
        sf[i] = false;
        pf[i] = false;
    }
    estr[len] = '#';
    estr[len+1] = 0; 

    for(i = 2;i < len;i++)
    {
        p[i] = 1;
        if(p[id]+id > i)
            p[i] = min(p[id*2-i],p[id]+id-i);

        while(estr[i+p[i]] == estr[i-p[i]])
            p[i]++;

        if(p[id]+id < p[i]+i)
            id = i;
        
        if(p[i] == i)
            pf[start[n]+p[i]-2] = true;
        if(p[i]+i-1 == len)
            sf[start[n+1]-p[i]+1] = true;
    }
}
int query(int n)
{
    int i,p = 0,sum = 0;
    for(i = start[n];i < start[n+1];i++)
    {
        int k = str[i]-'a';
        if(trie[p].next[k] == 0)
            break;
        p = trie[p].next[k];

        if(sf[i+1] || i == start[n+1]-1)
            sum += trie[p].leaf;
    }
    if(i == start[n+1])
        sum += trie[p].count;
    return sum;
}
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int n;
    while(scanf("%d",&n) != EOF)
    {
        int i,len;
        top = 0;
        trie[0].Free();
        for(i = 1;i <= n;i++)
        {
            scanf("%d%s",&len,str+start[i]);
            start[i+1] = start[i]+len;
            Manacher(i);
            BuildTrie(i);
        }
        ll ans = 0;
        for(i = 1;i <= n;i++)
        {
            ans += query(i);
        }
        printf("%lld\n",ans);
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

