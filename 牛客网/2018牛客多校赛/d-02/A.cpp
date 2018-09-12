/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  https://www.nowcoder.com/acm/contest/140/A
 *
 *        Version:  1.0
 *        Created:  2018/07/21 12时17分46秒
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
const int mod = 1000000007;
const int N = 100050;
int q,k;
int A[N];
ll Q[N];
int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d",&q,&k);
    // cout << "1" << endl;
    for(int i = 1;i < k;i++)
    {
        A[i] = 1;
    }
    A[k] = 2;
    // cout << "1" << endl;
    for(int i = k+1;i < N;i++)
    {
        A[i] = A[i-1]+A[i-k-1];
    }
    // cout << "1" << endl;
    Q[0] = 0;
    for(int i = 1;i < N;i++)
    {
        Q[i] = A[i]+Q[i-1];
        Q[i] %= mod;
    }
    int l,r;
    for(int i = 1;i <= q;i++)
    {
        scanf("%d %d",&l,&r);
        ll temp = Q[r]-Q[l-1];
        if(temp < 0)
            temp += mod;
        printf("%lld\n",temp);
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

