/*
 * =========================================================================
 *
 *       Filename:  K.cpp
 *
 *           Link:  http://exam.upc.edu.cn/problem.php?cid=1386&pid=10
 *
 *        Version:  1.0
 *        Created:  2018/07/15 21时40分12秒
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
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    char T[300];
    scanf("%s",T);
    int tlen = strlen(T);
    if(tlen%2 == 1)
        tlen--;
    int tlen2 = tlen/2;
    int flag = 1;
    while(flag)
    {
        tlen -= 2;
        tlen2 -= 1;
        flag = 0;
        for(int i = 0;i < tlen2;i++)
        {
            if(T[i] != T[i+tlen2])
                flag = 1;
        }
    }
    cout << tlen << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

