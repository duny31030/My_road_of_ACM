/*
 * =========================================================================
 *
 *       Filename:  H.cpp
 *
 *           Link:  http://exam.upc.edu.cn/problem.php?cid=1387&pid=7
 *
 *        Version:  1.0
 *        Created:  2018/07/07 19时16分04秒
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
int N,M,n,m;
map<int,int> m1,m2;
int main()
{
#ifdef ONLINE_JUDGE 
#else 
    freopen("./in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d",&N,&M);
    while(M--)
    {
        scanf("%d %d",&n,&m);
        if(n == 1 || m == 1)
        {
            if(n == 1)
            {
                m1[m]++;
            }
            else 
            {
                m1[n]++;
            }
        }
        else 
        {
            if(n == N || m == N)
            {
                if(n == N)
                {
                    m2[m]++;
                }
                else 
                {
                    m2[n]++;
                }
            }
        }
    }
    int flag = 0;
    map<int,int>::iterator it;
    pair<int,int> p;
    for(it = m1.begin();it != m1.end();it++)
    {
        p = *it;
        if(m2[p.first] != 0)
        {
            flag = 1;
        }
    }

    if(flag == 1)
    {
        printf("POSSIBLE\n");
    }
    else 
    {
        printf("IMPOSSIBLE\n");
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

