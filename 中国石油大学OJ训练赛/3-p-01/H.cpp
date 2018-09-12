/*
 * =========================================================================
 *
 *       Filename:  H.cpp
 *
 *           Link:  http://exam.upc.edu.cn/problem.php?cid=1386&pid=7
 *
 *        Version:  1.0
 *        Created:  2018/07/08 13时23分47秒
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
ll x,y,z,a[5];

int main()
{
#ifdef ONLINE_JUDGE 
#else 
    freopen("./in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%lld %lld %lld",&x,&y,&z);
    a[1] = x+y;
    a[2] = x+z;
    a[3] = y+z;
    sort(a+1,a+4);
//    printf("%d %d %d\n",a[1],a[2],a[3]);
    printf("%lld",a[1]);
    
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

