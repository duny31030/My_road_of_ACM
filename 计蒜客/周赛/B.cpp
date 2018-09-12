/*
 * =========================================================================
 *
 *       Filename:  B.cpp
 *
 *           Link:  https://www.jisuanke.com/contest/1444/83076
 *
 *        Version:  1.0
 *        Created:  2018/07/14 12时15分16秒
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

int cmp ( const void *a , const void *b )

{

  return *(int *)a - *(int *)b;  //升序排序

//return *(int *)b - *(int *)a; //降序排序

/*可见：参数列表是两个空指针，现在他要去指向你的数组元素。所以转型为你当前的类型，然后取值。

        升序排列时，若第一个参数指针指向的“值”大于第二个参数指针指向的“值”，则返回正；若第一个参数指针指向的“值”等于第二个参数指针指向的“值”，则返回零；若第一个参数指针指向的“值”小于第二个参数指针指向的“值”，则返回负。

        降序排列时，则刚好相反。

*/

}



int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif

    int n,q,a,b;
    int p[100050];
    memset(p,0,sizeof p);
    cin >> n >> q;
    for(int i = 0;i < n;i++)
        cin >> p[i];
    while(q--)
    {
        cin >> a >> b;
        if(a == 1)
        {
            for(int i = 0;i < n;i++)
            {
                p[i] ^= b;
            }
        }
        else 
        {
            if(a == 2)
            {
                p[n] = b;
                n++;
            }
            else 
            {
                // sort(p+1,p+n+1);
                qsort(p,n,sizeof(p[0]),cmp);
                cout << p[b-1] << endl;
            }
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

