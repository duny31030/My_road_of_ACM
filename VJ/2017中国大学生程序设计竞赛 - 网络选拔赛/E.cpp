/*
 * =========================================================================
 *
 *       Filename:  E.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/22 20时26分15秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
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

ll a[100010];
ll f;
int T;


void find()
{
    ll pos = upper_bound(a,a+40000,f)-a;

     pos--;
     ll x = pos*2-1;
     if(a[pos] == f)
     {   
         printf("%lld\n",pos*4);
     }
     else 
     {
        if(f <= a[pos]+2+x)
        {
            if(f == a[pos]+1)
                printf("%lld\n",pos*4+1);
            else 
                if(f <= a[pos]+1+x)
                    printf("%lld\n",pos*4+2);
                else 
                    printf("%lld\n",pos*4+3);
        }
        else 
        {
            printf("%lld\n",pos*4+4);
        }
     }

}



int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    for(ll i = 1;i <= 40000;i++)
    {
        a[i] = i*i*2;
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&f);
        if(f == 1)
        {
            printf("4\n");
        }
        else 
            if(f == 2)
            {
                printf("4\n");
            }
            else 
            {
                if(f == 3)
                {
                    printf("6\n");
                }
                else 
                {
                    if(f == 4)
                    {
                        printf("6\n");
                    }
                    else 
                    {
                        if(f == 5)
                        {
                            printf("7\n");
                        }
                        else 
                        {
                            if(f == 6)
                            {
                                printf("8\n");
                            }
                            else 
                            {
                                if(f == 7)
                                {
                                    printf("8\n");
                                }
                                else 
                                {
                                    if(f == 8)
                                    {
                                        printf("8\n");
                                    }
                                    else 
                                    {
                                        find();
                                    }
                                }
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

