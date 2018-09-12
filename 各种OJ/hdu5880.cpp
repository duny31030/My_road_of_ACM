/*
 * =========================================================================
 *
 *       Filename:  hdu5880.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=5880
 *
 *        Version:  1.0
 *        Created:  2018/09/03 10时59分43秒
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
const int N = 1000100;
char s[N],m[N];
struct node
{
    int son[26];
    int fail;
    int len;
    int f;
}ac[N];
int tot = 0;

void init()
{
    for(int i = 0;i < N;i++)
    {
        memset(ac[i].son,0,sizeof ac[i].son);
        ac[i].fail = 0;
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
            ac[now].son[tmp] = ++tot;
        ac[ac[now].son[tmp]].len = ac[now].len+1;
        now = ac[now].son[tmp];
    }
    ac[now].len = len;
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

int Query(char *s)
{
    int len = strlen(s);
    int now = 0,ans = 0,tmp;
    for(int i = 0;i < len;i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            tmp = s[i]-'a';
        else 
            if(s[i] >= 'A' && s[i] <= 'Z')
                tmp = s[i]-'A';
            else
            {
                now = 0;
                continue;
            }
        now = ac[now].son[tmp];
        for(;now && ac[now].son[tmp] == 0;now = ac[now].fail)
        {
            printf("now = %d\n",now);
        }
        if(ac[now].son[tmp] != -1)
            now = ac[now].son[tmp];
        // if(ac[now].f)

        
    }
    return ans;
}
int T,n;
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
        init();
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
        {
            scanf("%s",s);
            Insert(s);
        }
        ac[0].fail = 0;
        MakeFail();
        scanf("%s",m);
        printf("%d\n",Query(m));
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

