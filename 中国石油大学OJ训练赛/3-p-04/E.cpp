/*
 * =========================================================================
 *
 *       Filename:  E.cpp
 *
 *           Link:  http://exam.upc.edu.cn/problem.php?cid=1389&pid=4
 *
 *        Version:  1.0
 *        Created:  2018/07/24 13时05分21秒
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
int a[1000500];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> N;
    for(int i = 1;i <= N;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+N+1);
    int pr = 0;
    for(int i = N;i >= 1;i--)
    {
        if(a[i] >= N-i)
            pr++;
        else 
            break;
    }
    cout << pr << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

