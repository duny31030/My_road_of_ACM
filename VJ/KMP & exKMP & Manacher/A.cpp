/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=1711
 *
 *        Version:  1.0
 *        Created:  2018/08/05 16时38分39秒
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
int S[N],T[N];
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

int KMP_Index()
{
    int i = 0,j = 0;
    getNext();
    while(i < slen && j < tlen)
    {
        if(j == -1 || S[i] == T[j])
        {
            i++;    j++;
        }
        else 
            j = Next[j];
    }
    if(j == tlen)
        return i-tlen;
    else 
        return -1;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int TT;
    cin >> TT;
    while(TT--)
    {
        cin >> slen >> tlen;
        rep(i,0,slen-1)
            cin >> S[i];
        rep(i,0,tlen-1)
            cin >> T[i];
        int p = KMP_Index();
        cout << (p == -1 ? -1 : p+1) << endl;
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

