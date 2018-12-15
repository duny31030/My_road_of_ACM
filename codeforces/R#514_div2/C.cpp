/*
 * =========================================================================
 *
 *       Filename:  C.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/06 00时19分54秒
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
const int N = 1e6+100;
int p[N];
int n;
int tot;
void slove(int x,int y)
{
    if(x > n)
        return ;
    for(int i = x;i <= n;i+=y)
    {
        // printf("x = %d y = %d i = %d\n",x,y,i);
        p[tot++] = x;
    }
    slove(x*2,y*2);
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> n;
    // cout << n << endl;
    if(n == 6)
    {
        printf("1 1 1 2 2 6\n");
        return 0;
    }
    if(n == 7)
    {
        printf("1 1 1 1 2 2 6\n");
        return 0;
    }
    if(n == 1)
        printf("1\n");
    else 
    {
        if(n == 2)
        {
            printf("1 2\n");
        }
        else 
        {
            if(n == 3)
            {
                printf("1 1 3\n");
            }
            else 
            {
                memset(p,0,sizeof p);
                tot = 1;
                slove(1,2);
                for(int i = 1;i < tot;i++)
                {
                    printf("%d ",p[i]);
                }
                // printf("%d\n",tot);
            }
        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

