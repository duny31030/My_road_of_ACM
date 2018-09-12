/*
 * =========================================================================
 *
 *       Filename:  C.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=2087
 *
 *        Version:  1.0
 *        Created:  2018/08/05 18时30分34秒
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

const int N = 1010;
int Next[N];
char S[N],T[N];
int slen,tlen;

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

int KMP_Count()
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
    getNext();
    for(i = 0;i < slen;i++)
    {
        while(j > 0 && S[i] != T[j])
            j = Next[j];
        if(S[i] == T[j])
        {
            j++;
        }
        if(j == tlen)
        {
            ans++;
            // j = Next[j];
            j = 0;
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
    while(cin >> S)
    {
        if(S[0] == '#')
            break;
        cin >> T;
        slen = strlen(S);
        tlen = strlen(T);
        cout << KMP_Count() << endl;

    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

