/*
 * =========================================================================
 *
 *       Filename:  M.cpp
 *
 *           Link:  https://www.jisuanke.com/contest/1444/83040
 *
 *        Version:  1.0
 *        Created:  2018/07/14 12时36分45秒
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

int cmp(int a,int b)
{
  if(a<b)
  return 1; //升序排列，如果改为 a >b，则为降序,要注意sort()中cmp()的返值只有1和0，不像qsort中存在－1！！！！
  else
  return 0;
}

int p[200050];

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int n,q,k,a,b,c;
    cin >> n >> q >> k;
    for(int i = 1;i <= n;i++)
        cin >> p[i];
    for(int i = 1;i <= q;i++)
    {
        cin >> a >> b >> c;
        if(c == 0)
        {
            sort(p+a,p+b+1);
        }   
        else 
        {
            sort(p+a,p+b+1,cmp);
        }
    }
    cout << p[k] << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

