/*
 * =========================================================================
 *
 *       Filename:  G.cpp
 *
 *           Link:  http://exam.upc.edu.cn/problem.php?cid=1387&pid=6
 *
 *        Version:  1.0
 *        Created:  2018/07/07 18时24分19秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  duny31030 (http://www.cnblogs.com/duny31030/), duny31030@126.com
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
int T,n,temp,m,mmax=-999,pr = 0;
int p[120];
int main()
{
    for(int i = 1;i <= 100;i++)
    {
        n = i;
        m = 0;
        while(n)
        {
            if(n / 2 * 2 == n)
            {
                n /= 2;
                m++;
            }
            else 
            {
                break;
            }
        }
        p[i] = m;
    }

#ifdef ONLINE_JUDGE 
#else 
    freopen("./in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d",&T);
    for(int i = 1;i <= T;i++)
    {
        if(p[i] > mmax)
        {
            mmax = p[i];
            pr = i;
        }
    }
    printf("%d\n",pr);

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

