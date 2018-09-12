/*
 * =========================================================================
 *
 *       Filename:  B.cpp
 *
 *           Link:  http://exam.upc.edu.cn/problem.php?cid=1387&pid=1
 *
 *        Version:  1.0
 *        Created:  2018/07/07 18时18分09秒
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
int N,K,n,m;
int l[100];
int main()
{
#ifdef ONLINE_JUDGE 
#else 
    freopen("./in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d",&N,&K);
    for(int i = 1;i <= N;i++)
    {
        scanf("%d",&l[i]);
    }
    sort(l+1,l+N+1);
    for(int i = N;i > N-K;i--)
    {
        n += l[i];   
    }
    printf("%d\n",n);
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

