/*
 * =========================================================================
 *
 *       Filename:  ny0108.cpp
 *
 *           Link:  http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=108
 *
 *        Version:  1.0
 *        Created:  2018/07/20 20时14分37秒
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
const int N = 1e6+10;

int bit[N+1];
int n,q,l,r,p;
int a[N];
int sum(int i)
{
    int s = 0;
    while(i > 0)
    {
        s += bit[i];
        i -= (i&-i);
    }
    return s;
}

void add(int i,int x)
{
    while(i <=  n)
    {
        bit[i] += x;
        i += (i&-i);
    }
}


int main()
{
    ios 
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> n >> q;
    for(int i = 1;i <= n;i++)
        cin >> a[i];    
    for(int i = 1;i <= n;i++)
        add(i,a[i]);
    for(int i = 1;i <= q;i++)
    {
        cin >> l >> r;
        cout << sum(r)-sum(l-1) << endl;
        
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

