/*
 * =========================================================================
 *
 *       Filename:  G.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/02 13时11分00秒
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

int c,n;
int pt[10000000];
int cnt=0;
int vis[10000000];
int fuck[10000000];

void el(ll ra)
{
	for(ll i = 2;i < ra;i++)
	{
        if(!vis[i])
        {
	        pt[cnt++] = i;
		    fuck[i]=1;
        }
		for(int j=0;j<cnt;j++)
		{
		if(i*pt[j] >= ra)
            break; 
		vis[i*pt[j]] = 1;
		if(i%pt[j] == 0)
            break;
		}
	}
//     cout << "gg" << endl;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin>>c>>n;
	if(c>n)
    {
    	cout<<"-1"<<endl;
	    return 0;
	}
    ll ans = c*c;
    ll temp = n/c;
    ll kk = 1;

    el(temp);

    // for(int i=1;i<=1000;i++)
    //     cout << fuck[i] << endl;

    for(ll i=2;i<=(ll)sqrt(temp);i++)
    {
	
	    if(!fuck[i] || temp%i != 0)
            continue;
	    int f=1;
	    while(temp > 1 && temp%i == 0)
        {
	        f *= i;
	        temp = temp/i;
	    }
        kk *= f;
    }   

    if(temp>1)
        kk*=temp;
    
    cout << kk*ans << endl;

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

