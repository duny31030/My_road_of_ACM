/*
 * =========================================================================
 *
 *       Filename:  J.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/23 13时14分22秒
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
int t,n;
int tmp;
int a[3];

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
        scanf("%d",&n);
        clr(a,0);
        rep(i,1,2)
        {
            rep(j,1,n)
            {
                scanf("%d",&tmp);
                a[tmp%3]++;
            }
        }
        if(a[0] > n)
        {
            printf("NO\n");
        }
        else 
        {
            if(a[1] == 0 || a[2] == 0)
            {
                printf("YES\n");
            }
            else 
            {
                if(a[0] < 2)
                {
                    printf("NO\n");
                }
                else 
                {
                    if(a[0] == 2)
                    {
                        if(a[1]%2 == 1)
                        {
                            printf("YES\n");
                        }
                        else 
                        {
                            printf("NO\n");
                        }
                    }
                    else 
                    {
                        printf("YES\n");
                    }
                }
            }
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

