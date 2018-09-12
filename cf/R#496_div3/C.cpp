/*
 * =========================================================================
 *
 *       Filename:  C.cpp
 *
 *           Link:  :http://codeforces.com/contest/1005/problem/C
 *
 *        Version:  1.0
 *        Created:  2018/07/10 00时03分29秒
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

int pow2(int a,int i)
{
  if (i==0) 
      return 1;
  int temp=pow(a,i>>1);
  temp = temp*temp;
  if (i&1)
      temp=(ll)temp*a;
  return temp;
}

map<int,int> m;
int a[120050],b[33];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("./in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif 
    for(int i = 0;i <= 31;i++)
    {
        b[i+1] = pow2(2,i);
    }
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        m[a[i]]++;
    }
    int flag = 0;
    if(n == 1 || n == 0)
    {
        if(n == 1)
            flag = 1;
        else 
            flag = 0;
    }
    else
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= 32;j++)
            {
                if(b[j] > a[i])
                {
                    int tmp = b[j]-a[i];
                    if(tmp != a[i])
                    {
                        if(m[tmp] > 0)
                        {
                            break;
                        }
                    }
                    else 
                    {
                        if(m[tmp] >= 2)
                        {
                             break;
                        }
                    }

                }
                if(j == 32)
                    flag++;
            }
        }
    }

    cout << flag << endl;


    fclose(stdin);
    // fclose(stdout);
    return 0;
}

