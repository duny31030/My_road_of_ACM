/*
 * =========================================================================
 *
 *       Filename:  E.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=1358
 *
 *        Version:  1.0
 *        Created:  2018/08/05 19时40分45秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <iostream>
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

const int N =   1000010;
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
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif  
    int id = 1;
    while(scanf("%d",&tlen) && tlen != 0)
    {
        scanf("%s",T);
        get_Next();

        printf("Test case #%d\n",id++);
        rep(i,2,tlen)
        {
            int p = i-Next[i];
            if(i%p == 0 && Next[i])
                printf("%d %d\n",i,i/p);
        }
        printf("\n");
        // rep(i,1,tlen)
            // printf("%d%c",Next[i],i == tlen ? '\n' : ' ');
    }
    

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

