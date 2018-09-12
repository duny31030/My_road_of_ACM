/*
 * =========================================================================
 *
 *       Filename:  J.cpp
 *
 *           Link:  https://www.nowcoder.com/acm/contest/139/J
 *
 *        Version:  1.0
 *        Created:  2018/07/20 13时12分04秒
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

int a[200050],qi[200050];
struct node
{
    int l;
    int r;
    int i;
}qur[100050];
map<int,int> m;
int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int n,q;
    while(scanf("%d",&n) != EOF)
    {
        m.clear();
        memset(qur,0,sizeof qur);
        memset(a,0,sizeof a);
        memset(qi,0,sizeof qi);
        scanf("%d",&q);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i = 1;i <= q;i++)
        {
            scanf("%d %d",&qur[i].l,&qur[i].r);
            qur[i].i = i;
        }
        for(int i = n;i >= 1;i--)
        {
            m[a[i]]++;
            if(m[a[i]] > 1)
                a[i] = 0;
        }
        for(int i = 1;i <= n;i++)
            a[i+n] = a[i];
        a[0] = 0;
        for(int i = 1;i <= 2*n;i++)
        {
            if(a[i] == 0)
                qi[i] = qi[i-1];
            else 
                qi[i] = qi[i-1]+1;
        }
        // for(int i = 1;i <= 2*n;i++)
        //     printf("%d ",qi[i]);
        // printf("\n=====\n");
        for(int i = 1;i <= q;i++)
        {
            int pr = 0;
            if(qur[i].l == qur[i].r-1)
            {
                pr = qi[n];
            }
            else 
            {
                pr = qi[qur[i].l+n]-qi[qur[i].r-1];
            }
            printf("%d\n",pr);
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

