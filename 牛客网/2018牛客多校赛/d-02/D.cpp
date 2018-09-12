/*
 * =========================================================================
 *
 *       Filename:  D.cpp
 *
 *           Link:  https://www.nowcoder.com/acm/contest/140/D
 *
 *        Version:  1.0
 *        Created:  2018/07/21 12时37分46秒
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
const int N = 100050;
int a[N];
int T,n;
ll step,last,profit;
int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d",&T);
    while(T--)
    {
        step = 0,last = -1,profit = 0;
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        a[n+1] = -999;
        for(int i = 1;i <= n;i++)
        {
            if(a[i] <= a[i+1])
            {
                if(last == -1 && a[i] < a[i+1])
                    last = a[i];
            }
            else 
            {
                if(last != -1 && a[i] > last)
                {
                    // printf("last = %lld a[%d] = %d\n",last,i,a[i]);
                    step += 2;
                    profit += (a[i]-last);
                    last = -1;
                }
            }
        }
        printf("%lld %lld\n",profit,step);
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

