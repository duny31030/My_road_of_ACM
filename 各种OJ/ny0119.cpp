/*
 * =========================================================================
 *
 *       Filename:  ny0119.cpp
 *
 *           Link:  http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=119
 *
 *        Version:  1.0
 *        Created:  2018/07/21 10时53分34秒
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
int n,q;
vector<int> Q;
int dp_min[N][30],dp_max[N][30];
void RMQ_init(const vector<int>& A)
{
    for(int i = 0;i < n;i++)
    {
        dp_min[i][0] = A[i];
        dp_max[i][0] = A[i];
    }
    for(int j = 1;(1 << j) <= n;j++)
        for(int i = 0;i + (1 << j) - 1 < n;i++)
        {
            dp_min[i][j] = min(dp_min[i][j-1],dp_min[i+(1 << (j-1))][j-1]);
            dp_max[i][j] = max(dp_max[i][j-1],dp_max[i+(1 << (j-1))][j-1]);
        }
}

int RMQ_min(int L,int R)
{
    int k = 0;
    while((1 << (k+1)) <= (R-L+1))   // 如果2^(k+1) <= R-L+1,那么k还可以加1
    {    
        k++;
    }
    // cout << "min = " << min(dp_min[L][k],dp_min[R-(1 << k)+1][k]) << endl;
    return min(dp_min[L][k],dp_min[R-(1 << k)+1][k]);
}

int RMQ_max(int L,int R)
{
    int k = 0;
    while((1 << (k+1)) <= (R-L+1))   // 如果2^(k+1) <= R-L+1,那么k还可以加1
    {    
        k++;
    }
    // cout << "max = " << max(dp_max[L][k],dp_max[R-(1 << k)+1][k]) << endl;
    return max(dp_max[L][k],dp_max[R-(1 << k)+1][k]);
}


int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int l,r,a;
    scanf("%d %d",&n,&q);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a);
        Q.push_back(a);
    }
    RMQ_init(Q);
    for(int i = 1;i <= q;i++)
    {
        scanf("%d %d",&l,&r);
        int tmp = RMQ_max(l-1,r-1)-RMQ_min(l-1,r-1);
        printf("%d\n",tmp);
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

