/*
 * =========================================================================
 *
 *       Filename:  J.cpp
 *
 *           Link:  http://poj.org/problem?id=1511
 *
 *        Version:  1.0
 *        Created:  2018/08/15 21时39分06秒
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
#include <iostream>
#include <algorithm>
#include <queue>
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
const int MAXN=1000100;
struct node
{
    int to,w,net;
};
node e1[MAXN],e2[MAXN];
int head1[MAXN],head2[MAXN];
ll dis[MAXN],ans;
int cnt,n,a,b,c,N,P,Q;
bool vis[MAXN];
void add(int u,int v,int w,node e[],int head[])
{
    e[cnt].to = v;
    e[cnt].w = w;
    e[cnt].net = head[u];
    head[u] = cnt;
}

ll spfa(node e[],int head[])
{
    rep(i,1,P)
    {
        dis[i] = INF;
    }
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = head[u];i != -1;i = e[i].net)
        {
            if(dis[e[i].to] > dis[u]+e[i].w)
            {
                dis[e[i].to] = dis[u]+e[i].w;
                q.push(e[i].to);
            }
        }
    }
    ll res = 0;
    rep(i,1,P)
        res += dis[i];
    return res;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d",&N);
    while(N--)
    {
        ans = 0;
        cnt = 0;
        scanf("%d %d",&P,&Q);
        rep(i,1,P)
        {
            head1[i] = -1;
            head2[i] = -1;
        }
        rep(i,1,Q)
        {
            scanf("%d %d %d",&a,&b,&c);
            add(a,b,c,e1,head1);
            add(b,a,c,e2,head2);
            cnt++;
        }
        ans += spfa(e1,head1);
        // cout << "ans = " << ans << endl;
        ans += spfa(e2,head2);
        // cout << "ans = " << ans << endl;
        printf("%lld\n",ans);
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

