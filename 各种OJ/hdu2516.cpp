/*
 * =========================================================================
 *
 *       Filename:  hdu2516.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=2516
 *
 *        Version:  1.0
 *        Created:  2018/10/05 20时37分01秒
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
int f[210];
int MA;
void init()
{
    f[0] = 2;   f[1] = 3; 
    for(int i = 2;i <= 100;i++)
    {
        f[i] = f[i-1]+f[i-2];
    }
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
    init();
    // cout << f[MA-1] << endl;
    while(scanf("%d",&n))
    {
        if(!n)  break;
        for(int i = 0;i < 100;i++)
        {
            if(n == f[i])
            {
                printf("Second win\n");
                break;
            }
            else 
            {
                if(n < f[i])
                {
                    printf("First win\n");
                    break;
                }
            }
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

