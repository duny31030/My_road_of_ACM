/*
 * =========================================================================
 *
 *       Filename:  B.cpp
 *
 *           Link:  http://exam.upc.edu.cn/problem.php?cid=1388&pid=1
 *
 *        Version:  1.0
 *        Created:  2018/07/22 12时08分53秒
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
    int n,a[1000030];
    memset(a,0,sizeof a);
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    int ans = 0;
    for(int i = n;i > 1;i--)
    {
        if(ans >= a[i])
            break;
        for(int j = i-1;j >= 1;j--)
        {
            if(ans >= a[j])
                break;
            ans = max(ans,(a[i]&a[j]));
        }
    }
    cout << ans << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}
