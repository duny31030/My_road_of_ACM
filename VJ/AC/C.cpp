/*
 * =========================================================================
 *
 *       Filename:  C.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=3065
 *
 *        Version:  1.0
 *        Created:  2018/09/26 23时12分29秒
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
const int N = 1005;
const int NN = 2001000;
char m[NN];
char vir[N][55];
int a[N];
struct node
{
    int son[27];
    int fail;
    int count;
    int number;
}ac[100*N];
int tot = 0;
void init()
{
    clr(a,0);
    for(int i = 0;i < 50000;i++)
    {
        memset(ac[i].son,0,sizeof ac[i].son);
        ac[i].count = 0;
        ac[i].fail = 0;
        ac[i].number = 0;
    }
}

void Insert(char *s,int num)
{
    int len = strlen(s);
    int now = 0;
    int tmp;
    for(int i = 0;i < len;i++)
    {
        tmp = s[i]-'A';
        if(ac[now].son[tmp] == 0)
            ac[now].son[tmp] = ++tot;
        now = ac[now].son[tmp];
    }
    ac[now].count++;
    ac[now].number = num;
}

void Insert1(char *s,int id)
{
    int len = strlen(s);
    int now = 0;
    int tmp;
    for(int i = 0;i < len;i++)
    {
        tmp = s[i]-'A';
        if(ac[now].son[tmp] == 0)
            ac[now].son[tmp] = ++tot;
        now = ac[now].son[tmp];
    }
    ac[now].count++;
    ac[now].number = id;
}

void MakeFail()
{
    queue<int> q;
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

void query(char *s)
{
    int len = strlen(s);
    int now = 0,tmp;
    for(int i = 0;i < len;i++)
    {
        tmp = s[i]-'A';
        if(tmp < 0 || tmp > 25)
            tmp = 26;
        now = ac[now].son[tmp];
        for(int t = now;t && ac[t].count != -1;t = ac[t].fail)
        {
            if(ac[t].number > 0)
            {
                a[ac[t].number]++;
            }
            // ans += ac[t].count;
            // ac[t].count = -1;
        }
    }
    // return ans;
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
        init();
        rep(i,1,n)
        {
            scanf("%s",vir[i]);
            Insert1(vir[i],i);
        }
        ac[0].fail = 0;
        MakeFail();
        scanf("%s",m);
        query(m);
        rep(i,1,n)
        {
            if(a[i])
                printf("%s: %d\n",vir[i],a[i]);
        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

