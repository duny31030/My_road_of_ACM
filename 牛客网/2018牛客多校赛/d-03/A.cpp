/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  https://www.nowcoder.com/acm/contest/141/A
 *
 *        Version:  1.0
 *        Created:  2018/07/26 13时52分34秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.github.io/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
struct node
{
    int p,a,c,m,g;
    int id;
}sc[10000];
bool cmp(const node a,const node b)
{
    if(a.p < b.p)
        return true;
    else 
        if(a.a < b.a)
            return true;
        else 
            if(a.c < b.c)
                return true;
            else 
                if(a.m < b.m)
                    return true;
                else 
                    if(a.g > b.g)
                        return true;
    return false;
};

bool cmp1(const node a,const node b)
{
    return a.g > b.g;
}
int pr[10000];
int P,A,C,M;
int N;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> N;
    rep(i,N)
    {
        cin >> sc[i].p >> sc[i].a >> sc[i].c >> sc[i].m >> sc[i].g;
        sc[i].id = i;
    }
    sort(sc,sc+N,cmp1);
    // rep(i,N)
    //     printf("%d %d %d %d %d\n",sc[i].p,sc[i].a,sc[i].c,sc[i].m,sc[i].g);
    cin >> P >> A >> C >> M;
    int cou = 0;
    rep(i,N)
    {
        if(P >= sc[i].p && A >= sc[i].a && C >= sc[i].c && M >= sc[i].m)
        {
            pr[cou++] = sc[i].id;
            P -= sc[i].p;
            A -= sc[i].a;
            C -= sc[i].c;
            M -= sc[i].m;
        }
    }
    cout << cou << endl;
    rep(i,cou)
        cout << pr[i] << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

