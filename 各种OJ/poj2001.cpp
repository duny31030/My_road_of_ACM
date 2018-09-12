/*
 * =========================================================================
 *
 *       Filename:  poj2001.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/29 14时09分22秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
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
    int next[27];
}trie[N];
int num[N];
char s[N][30];
int tot = 0;
int size = 0;
void add(char a[])
{
    int i,now = 0;
    int len = strlen(a);
    for(i = 0;i < len;i++)
    {
        int tmp = a[i]-'a'+1;
        int next = trie[now].next[tmp];
        if(next == 0)
            trie[now].next[tmp] = ++tot;
        now = trie[now].next[tmp];
        num[now]++;
    }
}
void query(char a[])
{
    int len = strlen(a);
    int now = 0,i;
    for(i = 0;i < len;i++)
    {
        if(num[now] == 1)
            break;
        int tmp = a[i]-'a'+1;
        printf("%c",a[i]);
        now = trie[now].next[tmp];
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
    while(scanf("%s",s[size++]) != EOF)
        add(s[size-1]);
    rep(i,0,size-1)
    {
        printf("%s ",s[i]);
        query(s[i]);
        printf("\n");
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

