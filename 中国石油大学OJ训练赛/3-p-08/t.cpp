/*
 * =========================================================================
 *
 *       Filename:  t.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/17 01时11分27秒
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
const int N = 3e5+10;
int a[N];

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int n,k,indx;
    while(scanf("%d%d",&k,&n) != EOF)
    {
    indx=n;
    if(k%2==0)
    {
        a[1]=k/2;
        for(int i=2;i<=n;i++)
            a[i]=k;
    }
 
    else
    {
        int temp=n/2;
        for(int i=1;i<=n;i++)
            a[i]=(k+1)/2;
 
        while(temp--)
        {
            if(a[indx]==1)
                a[indx--]--;
 
            else
            {
                a[indx]--;
                while(indx<n)
                    a[++indx]=k;
            }
        }
    }
 
    for(int i=1;i<=indx-1;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[indx]);
    
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

