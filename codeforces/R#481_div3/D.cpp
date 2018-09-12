/*
 * =========================================================================
 *
 *       Filename:  D.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/26 14时06分15秒
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
const int N = 100100;
int n;
ll a[N],b[N];
ll q;
ll pr;
ll c;
ll xiu,nmin;
ll now;
bool check()
{
    xiu = 0;
    rep(i,1,n)   // 
    {
     if(abs(now-a[i]) <= 1)
     {
         if(now != a[i])
         {
             xiu++;
         }
     }
     else 
     {
         break;
     }
     now += c;
     if(i == n)
     {
        pr = min(pr,xiu);
        return true;
     }
   
   }
    return false;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d",&n);
    q = 0;
    xiu = 0;
    nmin = INF;
    pr = INF;
    rep(i,1,n)
    {
        scanf("%lld",&b[i]);
        q += a[i];
    }
    // sort(a+1,a+1+n);
    if(b[1] > b[n])
    {
        for(int i = 1;i <= n;i++)
            a[n-i+1] = b[i];
    }
    else 
    {
        for(int i = 1;i <= n;i++)
            a[i] = b[i];
    }
    if(a[1] == a[n] || n <= 2)
    {
        printf("0\n");
        return 0;
    }
    else 
    {
        if((a[n]-a[1])%(n-1) == 0)
        {
            // 都不变
            // cout << "2" << endl;
            c = (a[n]-a[1])/(n-1);
            xiu = 0;
            now = a[1];
            bool i = check();                
            // 都-1
            c = (a[n]-a[1])/(n-1);
            now = a[1]-1;   
            xiu = 0;
            i = check();

            // 都+1
            c = (a[n]-a[1])/(n-1);
            xiu = 0;
            now = a[1]+1;
            i = check();
            if(pr != INF)
                printf("%lld\n",pr);
            else 
                printf("-1");
        }
        else 
        {
            if((a[n]+1-a[1])%(n-1) == 0)
            {
                // a[1]-1 a[n]不变
                c = (a[n]+1-a[1])/(n-1);
                xiu = 0;
                now = a[1]-1;
                bool i = check();
                // a[1]不变 a[n]+1
                c = (a[n]+1-a[1])/(n-1);

                xiu = 0;
                now = a[1];
                i = check();
                if(pr != INF)
                    printf("%lld\n",pr);
                else 
                    printf("-1\n");
            }
            else 
            {
                if((a[n]-1-a[1])%(n-1) == 0)
                {
                    // a[1]+1 a[n]不变
                    c = (a[n]-1-a[1])%(n-1);
                    xiu = 0;
                    now = a[1]+1;
                    bool i = check();

                    // a[1]不变 a[n]-1
                    c = (a[n]+1-a[1])/(n-1);
                    xiu = 0;
                    now = a[1];
                    i = check();
                    if(pr != INF)
                        printf("%lld\n",pr);
                    else 
                        printf("-1\n");
                }
                else 
                {
                    if((a[n]-a[1]+2)%(n-1) == 0)
                    {
                        // a[1]-1 a[n]+1
                        c = (a[n]+2-a[1])/(n-1);
                        xiu = 0;
                        now = a[1]-1;
                        if(check())
                            printf("%lld\n",pr);
                        else 
                            printf("-1\n");
                    }
                    else 
                    {
                        if((a[n]-a[1]-2)%(n-1) == 0)
                        {
                            // a[1]+1 a[n]-1
                            c = (a[n]-2-a[1])/(n-1);
                            xiu = 0;
                            now = a[1]+1;
                            if(check())
                                printf("%lld\n",pr);
                            else 
                                printf("-1\n");
                        }
                        else 
                        {
                            printf("-1\n");
                            return 0;
                        }
                    }
                }
            }
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

