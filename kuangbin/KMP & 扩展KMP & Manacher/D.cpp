/*
 * =========================================================================
 *
 *       Filename:  D.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=3746
 *
 *        Version:  1.0
 *        Created:  2018/08/05 18时42分30秒
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

const int N = 1000010;
int Next[N];
char T[N];
int tlen;

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

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int t;
    // cin >> t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",T);
        // cin >> T;
        tlen = strlen(T);
        getNext();
        if(Next[tlen] == 0)
            printf("%d\n",tlen);
            // cout << tlen << endl;
        else 
        {
            int p = tlen-Next[tlen];
            if(tlen%p == 0)
                printf("0\n");
                // cout << "0" << endl;
            else
                printf("%d\n",p-tlen%p);
                // cout << p-tlen%p << endl;
        }        
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

