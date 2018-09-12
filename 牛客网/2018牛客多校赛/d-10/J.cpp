/*
 * =========================================================================
 *
 *       Filename:  J.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/19 14时59分18秒
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
const int N = 1e6+10;
char s[N];

char flag,tem;
int slen,xlen,t,n,xst;
int snow;

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
        memset(s,0,sizeof s);
        scanf("%d",&n);
        scanf("%s",s);
        snow = slen = strlen(s);
        flag = s[slen-1];
        for(int i = 2;i <= n;i++)
        {
            char x[N];
            scanf("%s",x);
            xlen = strlen(x);
            tem = 'z';
            xst = -1;
            for(int j = 0;j < xlen;j++)
            {
                if(x[j] == flag)
                {
                    // printf("j = %d\n",j);
                    if(j != xlen-1)
                    {
                        if(x[j+1] <= tem)
                        {
                            tem = x[j+1];
                            xst = j;
                        }
                    }
                    else 
                    {
                        // xst = j;
                    }
                }
            }
            for(int j = xst+1;j < xlen;j++)
            {
                s[snow++] = x[j];
            }
            flag = s[snow-1];
        }
        printf("%s\n",s);

    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

