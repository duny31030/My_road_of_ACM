/*
 * =========================================================================
 *
 *       Filename:  C.cpp
 *
 *           Link:  http://exam.upc.edu.cn/problem.php?cid=1387&pid=2
 *
 *        Version:  1.0
 *        Created:  2018/07/07 18时59分29秒
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
ll a[200010];
int main()
{
// #ifdef ONLINE_JUDGE 
// #else 
//     freopen("./in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
// #endif
    ll temp1 = 0;
    int T,n;

    scanf("%d",&T);
    for(int i = 1;i <= T;i++)
    {
        scanf("%d",&n);
        temp1 += n;
        a[i] += a[i-1] + n;
    }
    ll mmin = 2e14;
    for(int i = 1;i < T;i++)
    {
        mmin = min(abs(2*a[i]-temp1),mmin);    
    }

    printf("%lld",mmin);
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}

