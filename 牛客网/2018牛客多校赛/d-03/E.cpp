/*
 * =========================================================================
 *
 *       Filename:  E.cpp
 *
 *           Link:  https://www.nowcoder.com/acm/contest/141/E
 *
 *        Version:  1.0
 *        Created:  2018/08/05 23时24分42秒
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
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

const int N = 1e6+10;
char T[N];
int Next[N];
int tlen;

void get_Next()
{
    int j,k;
    j = 0;  k = -1; Next[0] = -1;
    while(j < tlen)
    {
        if(k == -1 || T[j] == T[k])
            Next[++j] = ++k;
        else 
            k = Next[k];
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
    cin >> T;
    tlen = strlen(T);
    get_Next();
     //    printf("%d ",Next[i]);
    int p = tlen-Next[tlen];
    if(tlen%p == 0)
    {
        printf("%d\n",p);
        rep(i,0,p-1)
        {
            printf("%d",tlen/p);
            for(int j = i;j < tlen;j += p)
                printf(" %d",j);
            printf("\n");
        }
    }
    else 
    {
        printf("%d\n",tlen);
        rep(i,0,tlen-1)
            printf("1 %d\n",i);
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

