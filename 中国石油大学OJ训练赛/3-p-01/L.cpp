/*
 * =========================================================================
 *
 *       Filename:  L.cpp
 *
 *           Link:  http://exam.upc.edu.cn/problem.php?cid=1386&pid=11
 *
 *        Version:  1.0
 *        Created:  2018/07/08 12时25分29秒
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
int a[300000];
list<int> l;
int main()
{
#ifdef ONLINE_JUDGE 
#else 
    freopen("./in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d",&T);
    for(int i = 1;i <= T;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 1;i <= T;i++)
    {
        if(i % 2 == 0)
        {
            l.push_front(a[i]);
        }
        else 
        {
            l.push_back(a[i]);
        }
   }
    
 //       list<int>::iterator pos;
 //       pos = l.begin();
 //       cout << *pos;
 //       pos++;
 //       for(;pos != l.end();pos++)
 //       {
 //           cout << " " << *pos;
 //       }


    if(T % 2 == 0)
    {
        list<int>::iterator pos;
        pos = l.begin();
        cout << *pos;
        pos++;
        for(;pos != l.end();pos++)
        {
            cout << " " << *pos;
        }
   // cout << endl;
    }
    else 
    {
        list<int>::reverse_iterator pos;
        pos = l.rbegin();
        cout << *pos;
        pos++;
        for(;pos != l.rend();pos++)
        {
            cout << " " << *pos;
        }
   // cout << endl;
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

