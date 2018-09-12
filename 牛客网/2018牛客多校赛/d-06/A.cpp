/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/04 12时57分12秒
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


int t,n;
int an[20],a[20000][16];
int id[100010];
int pr;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in2.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    rep(i,0,16)
        an[i] = pow(2,i);
    
    cin >> t;
    rep(cs,1,t)
    {
        clr(id,0);
        cin >> n;
        rep(i,1,an[n])
            rep(j,1,n)
            {
                cin >> a[i][j];
            }
        
        rep(i,1,an[n])
            sort(a[i]+1,a[i]+1+n);
        rep(i,an[n],an[n+1]-1)
            id[i] = i-an[n]+1;
        pre(i,n,1)
        {
            // cout << "n = " << i << "   an[" << i << "] = " << an[i] << endl;
            for(int j = an[i];j < an[i+1]-1;j += 2)
            {
                int t = a[id[j]][n];
                if(t > a[id[j]+1][n])
                {
                    // printf("j = %d   %d > %d\n",j,id[j],id[j+1]);
                    int tmp = lower_bound(a[id[j]]+1,a[id[j]]+n+1,a[id[j]+1][n])-a[id[j]];
                    a[id[j]][tmp] = 0;
                    sort(a[id[j]]+1,a[id[j]]+1+n);
                    id[j/2] = id[j];
                }
                else 
                {
                    // printf("j = %d   %d < %d\n",j,id[j],id[j+1]);
                    int tmp = lower_bound(a[id[j]+1]+1,a[id[j]+1]+n+1,a[id[j]][n])-a[id[j]+1];
                    a[id[j]+1][tmp] = 0;
                    sort(a[id[j]+1]+1,a[id[j]+1]+1+n);
                    id[j/2] = id[j+1];
                }
            }
        }

        rep(i,0,n)
        {
            rep(j,an[i],an[i+1]-1)
            {
                cout << id[j] << " ";
            }
            cout << endl;
        }



        cout << "Case #" << cs << ": " << id[1] << endl;
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

