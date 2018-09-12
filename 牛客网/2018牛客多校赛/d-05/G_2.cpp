/*
 * =========================================================================
 *
 *       Filename:  G_2.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/02 13时21分19秒
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
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

//================读入挂&&输出挂================

//====================end=====================

#include<iostream>  
using namespace std;      
const long N = 5e7+100;     
long prime[N] = {0},num_prime = 0;      
int isNotPrime[N] = {1, 1};     
ll c,n,p;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    for(long i = 2 ; i < N ; i ++)         
    {              
        if(! isNotPrime[i])                 
            prime[num_prime ++]=i;    
        //关键处1          
        for(long j = 0 ; j < num_prime && i * prime[j] <  N ; j ++)  
        {                 
            isNotPrime[i * prime[j]] = 1;    
            if( !(i % prime[j] ) )  //关键处2                    
                break;             
        }          
    }
    cin >> c >> n;
    p = c*c;
    if(c > n)
    {
        cout << "-1" << endl;
        return 0;
    }
    else 
    {
        n /= c;
        rep(i,0,num_prime)
        {
            if(prime[i] > n)
                break;
            else 
                p *= prime[i];
        }
    }
    cout << p/2 << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

