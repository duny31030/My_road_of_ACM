/*
 * =========================================================================
 *
 *       Filename:  SG.cpp
 *
 *           Link:  https://www.cnblogs.com/ECJTUACM-873284962/p/6921829.html
 *
 *        Version:  1.0
 *        Created:  2018/10/05 10时47分30秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=n;i>=a;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 10;
const int MAXN = 1000;
int f[N];         // f[N]:可改变当前状态的方式，N为方式的种类
                  // f[N]要在getSG()之前预处理
int SG[MAXN];     // SG[]:0~n的SG函数值
int S[MAXN];      // S[]:为x后记状态的集合
int n,m;
void getSG()
{
    int i,j;
    memset(SG,0,sizeof(SG));
    // 因为SG[0]始终等于0，所以i从1开始
    for(i = 1;i <= n;i++)
    {
        // 每次都要讲上一状态的后继集合重置
        memset(S,0,sizeof S);
        for(j = 0;f[j] <= i && j <= N;j++)
            S[SG[i-f[j]]] = 1;   // 将后继状态的SG函数值进行标记
        for(j = 0;;j++)          // 查询当前后继状态SG值中的最小的非零值
            if(!S[j])
            {
                SG[i] = j;
                break;
            }
    }
}
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif



    fclose(stdin);
    // fclose(stdout);
    return 0;
}

