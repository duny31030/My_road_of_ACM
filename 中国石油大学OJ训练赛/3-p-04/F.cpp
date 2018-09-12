/*
 * =========================================================================
 *
 *       Filename:  F.cpp
 *
 *           Link:  http://exam.upc.edu.cn/problem.php?cid=1389&pid=5
 *
 *        Version:  1.0
 *        Created:  2018/07/24 12时32分04秒
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
int N;
char p[5][10];
string a[120];
string str;
map<char,int> mp;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    p[1][1] = p[1][2] = p[1][3] = '*';
    p[4][6] = p[4][7] = p[4][8] = '*';
    p[1][4] = 'A';
    for(int i = 1;i <= 4;i++)
        p[1][4+i] = p[1][3+i]+1;
    p[2][1] = 'F';
    for(int i = 1;i <= 7;i++)
        p[2][1+i] = p[2][i]+1;
    p[3][1] = 'N';
    for(int i = 1;i <= 7;i++)
        p[3][1+i] = p[3][i]+1;
    p[4][1] = 'V';
    for(int i = 1;i <= 4;i++)
        p[4][1+i] = p[4][i]+1;
    /*
    for(int i = 1;i <= 4;i++)
    {
        for(int j = 1;j <= 8;j++)
        {
            printf("%c",p[i][j]);
        }
        printf("\n");
    }
    */
    cin >> N;
    for(int i = 1;i <= N;i++)
    {
        cin >> a[i];
    }
    cin >> str;
    // int slen = str.size();
    for(int i = 1;i <= N;i++)
    {   
        if(a[i].find(str) == 0)
            mp[a[i][str.size()]]++;
    }
    /*
    map<char,int>::iterator it;
    for(it = mp.begin();it != mp.end();it++)
    {
        cout << it->first << " ";
    }
    */
    for(int i = 1;i <= 4;i++)
    {
        for(int j = 1;j <= 8;j++)
        {
            if(mp[p[i][j]] > 0)
                printf("%c",p[i][j]);
            else 
                printf("*");
        }
        printf("\n");
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

