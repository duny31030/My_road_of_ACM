/*
 * =========================================================================
 *
 *       Filename:  I.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=2594
 *
 *        Version:  1.0
 *        Created:  2018/08/06 16时02分36秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
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
const int N = 100050;
string s1,s2,s3;
int s1len,s2len,s3len;
int Next[N];

void get_Next(string s3)
{
    int j,k;
    j = 0;  k = -1; Next[0] = -1;
    while(j < s3len)
    {
        if(k == -1 || s3[j] == s3[k])
            Next[++j] = ++k;
        else 
            k = Next[k];
    }
}


int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    while(cin >> s1)
    {
        cin >> s2;
        s1len = s1.size();
        s2len = s2.size();
        s3 = s1+s2;
        s3len = s1len+s2len;
        get_Next(s3);
        int p = 0;
        p = Next[s3len];
        while(p > s1len || p > s2len)
        {
            p = Next[p];
        }
        if(p == 0)
        {
            printf("0\n");
        }
        else 
        {
            rep(i,0,p-1)
                printf("%c",s1[i]);
            printf(" %d\n",p);
        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

