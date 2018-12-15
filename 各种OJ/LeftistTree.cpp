/*
 * =========================================================================
 *
 *       Filename:  LeftistTree.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/29 11时09分00秒
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
const int N = 1e5+100;
int ch[N][2],v[N],ht[N],f[N];
int n,q,tmp,x,y;

int gf(int u)
{
    while(f[u]) u = f[u];
    return u;
}

// 这里为小根堆
//
int merge(int x,int y)
{
    if(!x || !y)    return x+y;
    if(v[x] > v[y] || (v[x] == v[y] && x > y))  swap(x,y);
    ch[x][1] = merge(ch[x][1],y);
    f[ch[x][1]] = x;
    if(ht[ch[x][0]] < ht[ch[x][1]])  swap(ch[x][0],ch[x][1]);
    ht[x] = ht[ch[x][1]]+1;
    return x;
}

void pop(int x)
{
    v[x] = -1;  f[ch[x][0]] = f[ch[x][1]] = 0;
    merge(ch[x][0],ch[x][1]);
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d",&n,&q);
    rep(i,1,n)  scanf("%d",&v[i]);
    rep(i,1,q)
    {
        scanf("%d",&tmp);
        if(tmp == 1)
        {
            scanf("%d %d",&x,&y);
            if(v[x] == -1 || v[y] == -1)    continue;
            x = gf(x);  y = gf(y);  
            if(x == y)  continue;
            merge(x,y);
        }
        else 
        {
            scanf("%d",&x);
            if(v[x] == -1)
                printf("-1\n");
            else 
            {
                y = gf(x);
                printf("%d\n",v[y]);
                pop(y);
            }
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

