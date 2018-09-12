/*
 * =========================================================================
 *
 *       Filename:  J.cpp
 *
 *           Link:  https://www.jisuanke.com/contest/1404/80899
 *
 *        Version:  1.0
 *        Created:  2018/07/10 13时16分01秒
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
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
    freopen("./in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif 
    string s;
    int T;
    cin >> T;
    cout << T << endl;
    for(int ii = 1;ii <= T;ii++)
    {
        cin >> s;
        char a[400][400];   // 迷宫地图
        for(int i = 0;i < 400;i++)
            for(int j = 0;j < 400;j++)
                a[i][j] = '#';
        int I,J;   // 用于记录当前坐标
        I = 200,J = 200;
        int f,b,l,r;
        f = b = l = r = 200;
        int len = s.length();
        a[I][J] = '.';
        char bef = 'F';
        for(int k = 0;k < len;k++)
        {
            if(bef == 'F')
            {
                if(s[k] == 'F')
                {
                    J++;
                    bef = 'F';
                }
                if(s[k] == 'B')
                {
                    J--;
                    bef = 'B';
                }
                if(s[k] == 'L')
                {
                    I--;
                    bef = 'L';
                }
                if(s[k] == 'R')
                {
                    I++;
                    bef = 'R';
                }
            }
            else
            if(bef == 'B')
            {
                if(s[k] == 'F')
                {   
                    J--;
                    bef = 'B';
                }
                if(s[k] == 'B')
                {
                    J++;
                    bef = 'F';
                }
                if(s[k] == 'L')
                {
                    I++;
                    bef = 'R';
                }
                if(s[k] == 'R')
                {
                    I--;
                    bef = 'L';
                }
            }
            else
            if(bef == 'L')
            {
                if(s[k] == 'F')
                {
                    I--;
                    bef = 'L';
                }
                if(s[k] == 'B')
                {
                    I++;
                    bef = 'R';
                }
                if(s[k] == 'L')
                {
                    J--;
                    bef = 'B';
                }
                if(s[k] == 'R')
                {
                    J++;
                    bef = 'F';
                }
            }
            else
            if(bef == 'R')
            {
                if(s[k] == 'F')
                {
                    I++;
                    bef = 'R';
                }
                if(s[k] == 'B')
                {
                    I--;
                    bef = 'L';
                }
                if(s[k] == 'L')
                {
                    J++;
                    bef = 'F';
                }
                if(s[k] == 'R')
                {
                    J--;
                    bef = 'B';
                }
            }
         //   cout << "I = " << I << " J = " << J << endl;
            a[I][J] = '.';
         //   for(int i = 199;i <= 202;i++)
         //   {
         //       for(int j = 200;j <= 203;j++)
         //       {
         //           cout << a[i][j];
         //       }
         //       cout << endl;
         //   }
         //   cout << endl;
            if(I < l)
                l = I;
            if(I > r)
                r = I;
            if(J > f)
                f = J;
            if(J < b)
                b = J;
        }
        int si = l-1,sj = 200,ei = r+1,ej = f+1;
        int li = ei - si+1,lj = ej - sj+1;
        cout << li << " " << lj << endl;
        for(int i = si;i <= ei;i++)
        {
            for(int j = sj;j <= ej;j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }

    }



    fclose(stdin);
    // fclose(stdout);
    return 0;
}

