/*
 * =========================================================================
 *
 *       Filename:  N.cpp
 *
 *           Link:  http://poj.org/problem?id=1308
 *
 *        Version:  1.0
 *        Created:  2018/09/24 02时59分21秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
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
const int N = 110;
int f[N];
bool vis[N];
int find(int x)
{
    if(f[x] != x)
    {
        f[x] = find(f[x]);
    }
    return f[x];
}
void init()
{
    for(int i = 0;i < N;i++)
    {
        f[i] = i;
        vis[i] = 0;
    }
}

int x,y;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int ca = 1;
    int flag = 0;
    int tmp = -1;
    init();
    while(scanf("%d %d",&x,&y) && (x != -1 && y != -1))
    {
        if(x == 0 && y == 0)
        {
            // printf("tmp = %d !!!\n",tmp);
            if(tmp != -1)
                tmp = find(tmp);
            // printf("tmp = %d !!!\n",tmp);
            for(int i = 0;i < N;i++)
            {
                if(vis[i])
                {
                    if(tmp != find(i))
                    {
                        // printf("%d\n",i);
                        flag = 1;
                        break;
                    }
                }
            }
            printf("Case %d ",ca++);
            if(flag)
            {
                printf("is not a tree.\n");
            }
            else 
            {
                printf("is a tree.\n");
            }
            flag = 0;
            tmp = -1;
            init();
            continue;
        }
        // printf("x = %d y = %d\n",x,y);
        if(tmp == -1)
            tmp = x;
        // printf("tmp = %d\n",tmp);
        int fx = find(x);
        int fy = find(y);
        // printf("fx = %d fy = %d\n",fx,fy);
        vis[x] = 1;
        vis[y] = 1;
        // printf("vis[%d] = %d vis[%d] = %d\n",x,vis[x],y,vis[y]);
        if(fx == fy)
        {
            flag = 1;
        }
        else 
        {
            // printf("f[%d] = %d\n",fy,fx);
            f[fy] = fx;
        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

