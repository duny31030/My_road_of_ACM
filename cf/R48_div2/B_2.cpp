/*
 * =========================================================================
 *
 *       Filename:  B_2.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/04 00时02分46秒
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

char s1[1010],W[1010],T[1010];
int wlen,tlen,q,x,y,n,m;
int nex[10010];
void getNext()
{
    int j,k;
    j=0;
    k=-1;
    nex[0]=-1;
    while(j<wlen)
    {
        if(k==-1||W[j]==W[k])
        {
            nex[++j]=++k;
        }
        else k=nex[k];
    }
}
int KMP_count()
{
    int ans=0;
    int i,j=0;
    if(wlen==1&&tlen==1)
    {
        if(W[0]==T[0])return 1;
        else return 0;
    }
    getNext();
    for(i=0;i<tlen;i++)
    {
        while(j>0&&T[i]!=W[j])
          j=nex[j];
        if(W[j]==T[i])j++;
        if(j==wlen)
        {
            ans++;
            j=nex[j];
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
    cin >> n >> m >> q;
    cin >> s1 >> W;
    wlen = strlen(W);
    if(m > n)
    {
        rep(i,1,q)
            cout << "0" << endl;
    }
    else 
    {
        rep(i,1,q)
        {
            cin >> x >> y;
            x--;    y--;
            strncpy(T,s1+x,y-x+1);
            T[y-x+1] = '\0';
            tlen = strlen(T);
            cout << KMP_count() << endl;
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

