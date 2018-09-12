/*
 * =========================================================================
 *
 *       Filename:  F.cpp
 *
 *           Link:  https://www.nowcoder.com/acm/contest/147/F
 *
 *        Version:  1.0
 *        Created:  2018/09/03 15时56分49秒
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
const int N = 1e6+100;
queue<int> qq;
vector<int> vc[N];
int ans[N];
struct node
{
    int son[26];
    int fail;
    int f;
    int last;
    int val;
}ac[N];
int tot = 0;

void init()
{
    for(int i = 0;i < N;i++)
    {
        memset(ac[i].son,0,sizeof ac[i].son);
        ac[i].fail = 0;
        ac[i].val = 0;
    }
}

void Insert(char *s)
{
    int len = strlen(s);
    int now = 0;
    int tmp;
    for(int i = 0;i < len;i++)
    {
        tmp = s[i]-'a';
        if(ac[now].son[tmp] == 0)
        {
            ac[now].son[tmp] = ++tot;
            ac[tot].val = 0;
        }
        now = ac[now].son[tmp];
    }
    ac[now].val = 1;
}

void MakeFail()
{
    queue<int> q;
    ac[0].f = 0;
    for(int i = 0;i < 26;i++)
    {
        int u = ac[0].son[i];
        if(u)
        {
            ac[u].last = ac[u].fail = 0;
            q.push(u);
        }
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0;i < 26;i++)
        {
            int tmp = ac[u].son[i];
            if(!tmp)
            {
                ac[tmp].son[i] = ac[ac[u].fail].son[i];
            }
            q.push(tmp);
            int temp = ac[tmp].fail;
            while(temp && ac[tmp].son[i] == 0)
                temp = ac[temp].fail;
            ac[tmp].fail = ac[temp].son[i];
            ac[tmp].last = ac[ac[tmp].fail].val ? ac[tmp].fail : ac[ac[tmp].fail].last; 
        }
    }
    for(int i = 0;i <= tot;i++)
    {
        if(ac[ac[i].fail].val)
            ac[i].val = 1;
        if(ac[i].val)
        {
            ans[i] = 1;
            qq.push(i);
        }
    }
    for(int i = 0;i <= tot;i++)
        for(int j = 0;j < 26;j++)
            vc[ac[i].son[j]].push_back(i);

}

char txt[N];
char ss[5][N];

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int T;
    int n,m;
    while(scanf("%d",&n) != EOF)
    {
        while(!qq.empty())
            qq.pop();
        for(int i = 0;i < N;i++)
            
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

