/*
 * =========================================================================
 *
 *       Filename:  1049.cpp
 *
 *           Link:  http://172.17.21.15/problem.php?id=1049
 *
 *        Version:  1.0
 *        Created:  2018/10/16 18时30分36秒
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
char S[N],T[N];
int Next[N],tlen,slen;
int f[N];
char pr[N];
int top = 0;
void get_Next()
{
    int j,k;
    j = 0,k = -1;   Next[0] = -1;
    while(j < tlen)
    {
        if(k == -1 || T[j] == T[k])
            Next[++j] = ++k;
        else 
            k = Next[k];
    }
}

void KMP_count()
{
    int i,j = 0;
    get_Next();
    for(i = 0;i < slen;i++)
    {
        pr[++top] = S[i];
        while(j > 0 && S[i] != T[j])
            j = Next[j];
        if(S[i] == T[j])
            j++;
        f[top] = j;
        if(j == tlen)
        {
            top -= tlen;
            j = f[top];
            // cout << "j = " << j << endl;
        }
    }
    return ;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    top = 0;
    cin >> S;
    cin >> T;
    slen = strlen(S);   
    tlen = strlen(T);
    KMP_count();
    pr[++top] = '\0';
    cout << pr+1 << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

