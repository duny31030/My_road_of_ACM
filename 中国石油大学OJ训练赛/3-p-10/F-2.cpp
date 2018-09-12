/*
 * =========================================================================
 *
 *       Filename:  F-2.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/10 16时26分51秒
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
const int maxn = 2e5+10;
int a[maxn],n,kl = 0;

int kaka[maxn];
int temp1 = 0;
int fl = 0;
int vis[maxn];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin>>n>>kl;
   memset(vis,0,sizeof(vis));
   for(int i = 0;i < n;i++)
   {
       cin>>a[i];
   }
   for(int i = 0;i < n;i++)
   {
       int num1 = 0;
       if(vis[i] != 1)
       {
           vis[i] = 1;
           num1++;
            for(int j = 0;j < n;j++)
            {
                if(a[i] == a[j] && i != j)
                {
                    vis[j] = 1;
                    num1++;
                }
            }
            kaka[fl++] = num1;
            // temp1 += 1;
       }
       else
       {
           continue;
       }
   }
   if(fl <= 0)
   {
       cout<<"0";
   }
   else
   {
        int y = fl-1;
        sort(kaka,kaka+fl);
        int temp = 0;
        for(int i = y - 1;i > i-kl;i--)
        {
            temp = temp + kaka[i];
        }
        cout<<n-temp;
   }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

