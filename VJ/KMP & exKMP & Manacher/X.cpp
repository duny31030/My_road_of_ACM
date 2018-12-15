/*
 * =========================================================================
 *
 *       Filename:  X.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=4763
 *
 *        Version:  1.0
 *        Created:  2018/08/28 15时27分15秒
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
bool f[N];
void getNext()
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

int slove()
{
    int ans = 0;
    for(int i = tlen-1;i > 1;i--)
    {
        int tmp = i;
        while(tmp > 0)
        {
            if(f[tmp] && i >= 2*tmp && tlen >= i+tmp)
            {
                ans = max(ans,tmp);
                break;
            }
            tmp = Next[tmp];
            // printf("!!tmp = %d\n",tmp);
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
    int n;
    scanf("%d",&n);
    rep(i,1,n)
    {
        scanf("%s",T);
        tlen = strlen(T);
        getNext();
        int tmp = tlen;
        while(tmp > 0)
        {
            if(tlen >= 2*tmp)
                f[tmp] = 1;
            tmp = Next[tmp];
            // printf("tmp = %d\n",tmp);
        }
        // rep(i,1,tlen)
        //     printf("%d ",Next[i]);
        // printf("\n");

        printf("%d\n",slove());
        clr(f,0);
        clr(T,0);
        clr(Next,0);
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

