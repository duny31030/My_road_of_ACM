/*
 * =========================================================================
 *
 *       Filename:  J.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=3336
 *
 *        Version:  1.0
 *        Created:  2018/08/06 21时45分44秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

const int N = 200010;
string S;
int Next[N],dp[N];
int slen,len;

void get_Next()
{
    int j,k;
    j = 0;  k = -1; Next[0] = -1;
    while(j < slen)
    {
        if(k == -1 || S[j] == S[k])
            Next[++j] = ++k;
        else 
            k = Next[k];
    }
}

int KMP_Count(string T,int tlen)
{
    int ans = 0;
    int i,j = 0;
        
    if(slen == 1 && tlen == 1)
    {
        if(S[0] == T[0])
            return 1;
        else 
            return 0;
    }
    //get_Next();
    for(i = 0;i < slen;i++)
    {
        while(j > 0 && S[i] != T[j])
            j = Next[j];
        if(S[i] == T[j])
            j++;
        if(j == tlen)
        {
            ans++;
            j = Next[j];
        }
    }
    return ans;
}


int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int t,pr;
    cin >> t;
    while(t--)
    {
        pr = 0;
        dp[0] = 0;
        cin >> slen;
        cin >> S;
        get_Next();
//        rep(i,1,slen)
//            printf("%d%c",Next[i],i == slen ? '\n' : ' ');
        rep(i,1,slen)
        {
            dp[i] = dp[Next[i]]+1;
            pr += dp[i];
            pr %= 10007;
        }
        cout << pr << endl;
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

