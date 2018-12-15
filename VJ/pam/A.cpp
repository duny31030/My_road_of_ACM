/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  http://codeforces.com/problemset/problem/17/E
 *
 *        Version:  1.0
 *        Created:  2018/09/27 12时00分42秒
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
const int MAXN = 2e6+100;
const int N = 26;
char s[MAXN];
struct Palindromic_Tree
{
    int next[MAXN][N];
    int fail[MAXN];
    int cnt[MAXN];
    int num[MAXN];
    int len[MAXN];
    int S[MAXN];
    int last;
    int n;
    int p;
    
    int newnode(int l)
    {
        for(int i = 0;i < N;i++)
            next[p][i] = 0;
        cnt[p] = 0;
        num[p] = 0;
        len[p] = l;
        return p++;
    }

    void init()
    {
        p = 0;
        newnode(0);
        newnode(-1);
        last = 0;
        n = 0;
        S[n] = -1;
        fail[0] = 1;
    }
    
    int get_fail(int x)
    {
        while(S[n-len[x]-1] != S[n])
            x = fail[x];
        return x;
    }
    
    void add(int c)
    {
        c -= 'a';
        S[++n] = c;
        int cur = get_fail(last);
        if(!next[cur][c])
        {
            int now = newnode(len[cur]+2);
            fail[now] = next[get_fail(fail[cur])][c];
            next[cur][c] = now;
            num[now] = num[fail[now]]+1;
        }
        last = next[cur][c];
        cnt[last]++;
    }
    
    void count()
    {
        for(int i = p-1;i >= 0;i--)
            cnt[fail[i]] += cnt[i];
    }
};

Palindromic_Tree pam;


int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int cas;
    scanf("%d",&cas);
    scanf("%s",s);
    pam.init();
    for(int i = 0;i < cas;i++)
    {
        pam.add(s[i]);
    }
    printf("%d\n",pam.p-2);
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

