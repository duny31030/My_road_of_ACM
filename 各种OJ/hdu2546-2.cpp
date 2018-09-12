/*
 * =========================================================================
 *
 *       Filename:  hdu2546-2.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=2546
 *
 *        Version:  1.0
 *        Created:  2018/07/15 11时15分51秒
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
int price[1020];
int total[1020][1020];
int dfs(int m,int k)
{
    int s;
    if(total[m][k] >= 0)
        return total[m][k];
    if(k == 1)
    {
        if(m >= price[1])
            s = price[1];
        else 
            s = 0;
    }
    else 
        if(m >= price[k])
            s = max((dfs(m-price[k],k-1)+price[k]),dfs(m,k-1));
        else 
            s = dfs(m,k-1);
    total[m][k] = s;
    return s;
}


int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int n,i,sum,s;
    while(cin >> n && n != 0)
    {
        memset(total,-1,sizeof total);
        for(i = 1;i <= n;i++)
        {
            cin >> price[i];
        }
        cin >> sum;
        if(sum <= 4)
            cout << sum << endl;
        else 
        {
            sort(price+1,price+n+1);
            s = sum;
            sum = dfs(sum-5,n-1);
            sum = s-sum-price[n];
            cout << sum << endl;
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

