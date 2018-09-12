/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  http://exam.upc.edu.cn/problem.php?cid=1387&pid=0
 *
 *        Version:  1.0
 *        Created:  2018/07/07 18时12分18秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  duny31030 (http://www.cnblogs.com/duny31030/), duny31030@126.com
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
int T,n,m;

int main()
{

    cin >> n >> m;
    if(((n+m)%3 == 0) || n%3 == 0 || m%3 == 0)
    {
        cout << "Possible" << endl;
    }
    else 
    {
        cout << "Impossible" << endl;
    }    
    
    return 0;
}

