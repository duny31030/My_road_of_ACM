/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  https://nanti.jisuanke.com/t/28401
 *
 *        Version:  1.0
 *        Created:  2018/07/17 12时16分57秒
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
int a[5000010];
int top;
ll prin = 0;
int n, p, q, m; 
unsigned int SA, SB, SC; 
unsigned int rng61()
{
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1; 
    unsigned int t = SA; 
    SA = SB;
    SB = SC;
    SC ^= t ^ SA; 
    return SC;
}
void gen()
{
    scanf("%d %d %d %d %u %u %u", &n, &p, &q, &m, &SA, &SB, &SC); 
    for(int i = 1; i <= n; i++)
    {
        if(rng61() % (p + q) < p)
        {
            a[++top] = (rng61()%m+1);
            a[top] = max(a[top],a[top-1]);
        }   
        else
        {
            top = max(top-1,0);
        }
        prin ^= (1LL*i*a[top]);
    } 
}

int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif 
    
    int T;
    cin >> T;
    int flag = 1;
    while(T--)
    {
        a[0] = 0;
        top = 0;
        prin = 0;
        gen();

        cout << "Case #" << flag++ << ": ";
        cout << prin << endl;
    }
    fclose(stdin);
   //  fclose(stdout);
    return 0;
}

