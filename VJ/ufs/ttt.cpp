/*
 * =========================================================================
 *
 *       Filename:  ttt.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/09/24 13时26分59秒
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
const int N = 1e6+100;

char a[N],b[N];

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("5.in","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%s %s",a,b);
    int alen = strlen(a);
    int blen = strlen(b);

    int i = 0,j = 0;
    while(i < alen && j < blen)
    {
        if(a[i] != b[j])
        {
            i = i-(j-1);
            j = 0;
        }
        else 
        {
            i++;
            j++;
        }
    }
    if(j == blen)
        printf("Y\n");
    else 
        printf("N\n");

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

