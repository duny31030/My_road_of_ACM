/*
 * =========================================================================
 *
 *       Filename:  I.cpp
 *
 *           Link:  https://www.nowcoder.com/acm/contest/140/I
 *
 *        Version:  1.0
 *        Created:  2018/07/21 14时36分16秒
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
int n,m,x,y;
ll mmax = 0;
int m1[100010],m2[100010];
int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d",&n,&m);
    if(n%2 == 1)   // 奇数
        mmax = n*2-1;
    else   // 偶数
        mmax = n*2;
    memset(m1,-1,sizeof m1);
    memset(m2,-1,sizeof m2);
    
    for(int i = 1;i <= m;i++)
    {
        scanf("%d %d",&x,&y);
        
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

