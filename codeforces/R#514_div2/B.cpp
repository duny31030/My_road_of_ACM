/*
 * =========================================================================
 *
 *       Filename:  B.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/05 23时21分03秒
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
const int N = 1e3+10;
int n,m;
char a[N][N];
char t[N][N];

int tx[] = {-1,-1,-1,0,0,1,1,1};
int ty[] = {-1,0,1,-1,1,-1,0,1};

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++)   scanf("%s",a[i]+1);
    memset(t,'.',sizeof t);
    for(int i = 2;i < n;i++)
        for(int j = 2;j < m;j++)
        {
            bool flag = 1;
            for(int k = 0;k < 8;k++)
            {
                if(a[i+tx[k]][j+ty[k]] != '#')
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
            {
                for(int k = 0;k < 8;k++)
                    t[i+tx[k]][j+ty[k]] = '#';
            }
        }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(a[i][j] != t[i][j])
            { 
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

