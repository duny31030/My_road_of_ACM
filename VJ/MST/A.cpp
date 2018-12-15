/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  http://poj.org/problem?id=1251
 *
 *        Version:  1.0
 *        Created:  2018/09/26 11时47分40秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
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
struct node{int u,v,w;}e[105];
int f[105],n,m,ans,tmp,eu,ev,cnt,temp;
char start,en;
inline bool cmp(node a,node b){return a.w<b.w;};
inline int find(int x)
{
    while(x != f[x])
        x = f[x] = f[f[x]];
    return x;
};
int kruskal()
{
    cnt = 0;
    ans = 0;
    for(int i = 0;i <= n;i++)   f[i] = i;
    sort(e,e+m,cmp);
    for(int i = 0;i < m;i++)
    {
        eu = find(e[i].u);  ev = find(e[i].v);
        if(eu == ev)    continue;
        ans += e[i].w;
        f[ev] = eu;
        if(++cnt == n-1)
            break;
    }
    return ans;
}


int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    // scanf("%d",&n);
    while(cin >> n)
    {
        if(n == 0)
            break;
        m = 0;
        for(int i = 0;i < n-1;i++)
        {
            // scanf("%c %d",&start,&tmp);
            cin >> start >> tmp;
            for(int j = 0;j < tmp;j++,m++)
            {
                // scanf("%c %d",&en,&temp);
                cin >> en >> temp;
                eu = start-'A',ev = en-'A';
                e[m].u = eu,e[m].v = ev,e[m].w = temp;
            }
        }
        // printf("%d\n",kruskal());
        cout << kruskal() << endl;
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

