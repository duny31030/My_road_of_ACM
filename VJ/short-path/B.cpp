/*
 * =========================================================================
 *
 *       Filename:  B.cpp
 *
 *           Link:  http://poj.org/problem?id=1125
 *
 *        Version:  1.0
 *        Created:  2018/08/11 21时32分53秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long

const double eps = 1e-6;
const int INF = 1010;
const int mod = 1e9 + 7;
const int N = 1010;
int e[N][N];
int i,j,k,n,tmp,cat,ti;
int maxlength,minlength,flag;
void floyd()
{
    for(k = 1;k <= n;k++)
        for(i = 1;i <= n;i++)
            for(j = 1;j <= n;j++)
                if(i != j && e[i][j] > e[i][k]+e[k][j])
                    e[i][j] = e[i][k]+e[k][j];
}

void find()
{
    maxlength = 0;
    minlength = INF;
    for(i = 1;i <= n;i++)
    {
        maxlength = 0;
        for(j = 1;j <= n;j++)
        {
            if(i != j && maxlength < e[i][j])
                maxlength = e[i][j];
        }
        if(minlength > maxlength)
        {
            flag = i;
            minlength = maxlength;
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
    while(scanf("%d",&n) && n)
    {
        for(i = 1;i < N;i++)
            for(j = 1;j < N;j++)
                e[i][j] = INF;
        for(i = 1;i <= n;i++)
        {
            scanf("%d",&tmp);
            for(j = 1;j <= tmp;j++)
            {
                scanf("%d %d",&cat,&ti);
                e[i][cat] = ti;
            }
        }
        floyd();
        find();
        if(minlength == INF)
            printf("disjoint\n");
        else 
            printf("%d %d\n",flag,minlength);
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

