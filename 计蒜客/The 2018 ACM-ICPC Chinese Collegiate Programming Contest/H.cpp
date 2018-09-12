/*
 * =========================================================================
 *
 *       Filename:  H.cpp
 *
 *           Link:  https://www.jisuanke.com/contest/1406/82620
 *
 *        Version:  1.0
 *        Created:  2018/07/17 16时08分48秒
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
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;

struct node
{
    int h,a;
    double bi;
};

bool cmp(node x,node y)
{
    if(x.bi-y.bi != eps)
    {
        return x.bi>y.bi;
    }
    else 
        if(x.a != y.a)
        {
            return x.a > y.a;
        }
    else 
        return x.h < y.h;

}

bool cmp2(node x,node y)
{
    if(x.a != y.a)
        return x.a > y.a;
    else 
        return x.h < y.h;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int T,n;
    cin >> T;
    int ca = 1;
    while(T--)
    {
        ll hou[100050];
        cin >> n;
        node nod[100050];
        for(int i = 1;i <= n;i++)
        {
            cin >> nod[i].h >> nod[i].a;
            nod[i].bi = (nod[i].a*1.0)/(nod[i].h*1.0);

        }
        hou[n+1] = 0;
        sort(nod+1,nod+1+n,cmp);
        for(int i = 1;i <= n;i++)
        {
            cout << nod[i].h << " " << nod[i].a << endl;
        }
        for(int i = n;i >= 1;i--)
        {
            hou[i] = hou[i+1]+nod[i].a;
        }

        ll hp = 0;
        for(int i = 1;i <= n;i++)
        {
            int ffl = 1;
            for(int j = 1;ffl && j <= 10000;j++)
            {
                hp += hou[i];
                if(nod[i].h-j > 0)
                {
                    nod[i].h -= j;
                }
                else 
                    ffl = 0;
            }
        }
        cout << "Case #" << ca << ": ";
        cout << hp << endl;
        ca++;
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

