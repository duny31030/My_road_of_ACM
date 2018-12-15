/*
 * =========================================================================
 *
 *       Filename:  1054.cpp
 *
 *           Link:  http://210.44.144.221/problem.php?id=1054
 *
 *        Version:  1.0
 *        Created:  2018/10/25 19时48分38秒
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
const int N =1e5+100;
char s[N],t[N];
int dp[N];
struct node
{
    int son[26];
    int fail;
    int count;
}ac[N];
int tot = 0;

void Insert(char *s)
{
    int len = strlen(s);
    int now = 0;
    int tmp;
    for(int i = 0;i < len;i++)
    {
        tmp = s[i]-'a';
        if(ac[now].son[tmp] == 0)
            ac[now].son[tmp] = ++tot;
        now = ac[now].son[tmp];
    }
    ac[now].count = 1;
}

void MakeFail()
{
    queue<int>q;
    for(int i = 0;i < 26;i++)
    {
        if(ac[0].son[i] != 0)
        {
            ac[ac[0].son[i]].fail = 0;
            q.push(ac[0].son[i]);
        }
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0;i < 26;i++)
        {
            if(ac[u].son[i] != 0)
            {
                ac[ac[u].son[i]].fail = ac[ac[u].fail].son[i];
                q.push(ac[u].son[i]);
            }
            else 
                ac[u].son[i] = ac[ac[u].fail].son[i];
        }
    }
}

int Query(char *s)
{
    int len = strlen(s+1);
    int now = 0,ans = 0,tmp;
    dp[0] = 0;
    for(int i = 0;i <= len;i++)
    {
        if(dp[i] != i)
            continue;
        else 
            ans = i;
        for(int j = i+1;j <= len;j++)
        {
            tmp = s[j]-'a';
            now = ac[now].son[tmp];
            if(now == 0)    break;
            if(ac[now].count)
                dp[j] = j;
            // for(int t = now;t && ac[t].count != -1;t = ac[t].fail)
            // {
                // ans += ac[t].count;
                // ac[t].count = -1;
            // }
        }
    }
    return ans;
}

int n,m;

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++)
    {
        scanf("%s",s);
        getchar();
        Insert(s);
    }
    ac[0].fail = 0;
    MakeFail();
    for(int i = 1;i <= m;i++)
    {
        scanf("%s",t+1);
        getchar();
        printf("%d\n",Query(t));
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

