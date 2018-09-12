/*
 * =========================================================================
 *
 *       Filename:  C.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/07/17 11时59分34秒
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
char a[60],b[60],c[60];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int T;
    cin >> T;
    int n,m;
    int flag = 1;
    while(T--)
    {
        cin >> n >> m;
        cin >> a;
        cin >> b;
        cin >> c;
        int cha = b[0]-a[0];
        if(cha < 0)
            cha += 26;
        // cout << cha << endl;
        for(int i = 0;i < m;i++)
        {
            c[i] -= cha;
            if(c[i] < 'A')
                c[i] += 26;
        }
        cout << "Case #" << flag << ": ";
        cout << c << endl;
        flag++;
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

