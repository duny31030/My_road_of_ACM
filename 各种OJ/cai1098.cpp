/*
 * =========================================================================
 *
 *       Filename:  cai1098.cpp
 *
 *           Link:  http://caioj.cn/problem.php?id=1098
 *
 *        Version:  1.0
 *        Created:  2018/09/04 17时25分44秒
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
const int N = 500100;
int t,n,m,c,x,y;
int sum[N];
void add(int p,int x)   
{
    while(p <= n)
        sum[p] += x,p += p&(-p);
}
// 求位置p的前缀和
int ask(int p)
{
    int res = 0;
    while(p)
        res += sum[p],p -= p&(-p);
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
    scanf("%d",&t);
    while(t--)
    {
        clr(sum,0);
        scanf("%d %d",&n,&m);
        rep(i,1,m)
        {
            scanf("%d",&c);
            if(c)
            {
                scanf("%d %d",&x,&y);
                if(x > y)
                    swap(x,y);
                int t = ask(y-1)-ask(x-1);
                if(t == 0)
                    printf("1\n");
                else 
                    if(ask(x-1) == 0 && (ask(n)-ask(y-1)) == 0)
                        printf("1\n");
                    else 
                        printf("0\n");
            }
            else 
            {
                scanf("%d",&x);
                int t = ask(x)-ask(x-1);
                if(t)
                {
                    add(x,-1);
                }
                else 
                {
                    add(x,1);
                }
            }
        }
        printf("\n");
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

