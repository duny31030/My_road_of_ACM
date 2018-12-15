/*
 * =========================================================================
 *
 *       Filename:  t1.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/09/23 17时51分57秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=n;i>=a;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double pi = 3.1415926535897;

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif

    int a[3];
	while(cin>>a[0]>>a[1]>>a[2])
	{
		sort(a,a+3);
		if((a[0]+a[1]>a[2])&&(a[2]-a[1]<a[0]))
		{
			if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2])
			cout<<"yes\n";
			else
			cout<<"no\n";
		}
		else
		cout<<"not a triangle\n";
	}

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

