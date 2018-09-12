/*
 * =========================================================================
 *
 *       Filename:  ny0117.cpp
 *
 *           Link:  http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=117
 *
 *        Version:  1.0
 *        Created:  2018/07/20 21时33分45秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.github.io/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int N = 1000010;
int a[N],b[N],t[N],bit[N+1];
int T,n,m;
void add(int i,int x)
{
   //  printf("===========\n");
    while(i <= n)
    {
    //     printf("bit[%d] += %d\n",i,x);
        bit[i] += x;
        i += (i&-i);
    }
    // printf("===========\n");
}

int sum(int i)
{
    int s = 0;
    while(i > 0)
    {
        s += bit[i];
        i -= (i&-i);
    }
    return s;
}

void init()
{
    memset(bit,0,sizeof bit);    
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> T;
    while(T--)
    {
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(t,0,sizeof t);
        memset(bit,0,sizeof bit);
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
            t[i] = a[i];
        }
        sort(t+1,t+n+1);
        for(int i = 1;i <= n;i++)
            printf("%d ",t[i]);
        printf("\n");
        m = unique(t+1,t+n+1)-t-1;
        for(int i = 1;i <= n;i++)
        {
            a[i] = lower_bound(t+1,t+m+1,a[i])-t;
        }
        for(int i = 1;i <= n;i++)
            printf("%d ",a[i]);
        printf("\n");
        ll ans = 0;
        for(int i = 1;i <= n;i++)
        {
            add(a[i],1);
            // printf("%d-sum[%d] = %d\n",i,a[i],i-sum(a[i]));
            ans += i-sum(i);
        }
        printf("%lld\n",ans);
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

