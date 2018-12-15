/*
 * =========================================================================
 *
 *       Filename:  t2.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/23 17时07分39秒
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
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int date (int year);

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int a,b,c,d;
    scanf("%d\\%d",&a,&b);
    c=date(a);
    if(c==0)   
 	{        
        switch (b) 
        {
	     case 1:d=31;break;
       	 case 2:d=28;break;
	     case 3:d=31;break;
	     case 4:d=30;break;
	     case 5:d=31;break; 
	     case 6:d=30;break;
       	 case 7:d=31;break;
	     case 8:d=31;break;
	     case 9:d=30;break;
	     case 10:d=31;break; 
	     case 11:d=30;break;
       	 case 12:d=31;break;
        }  
        printf("%d",d); 
    }

    if(c==1)   
    {  
        switch (b) 
   	    {
	     case 1:d=31;break;
       	 case 2:d=29;break;
	     case 3:d=31;break;
	     case 4:d=30;break;
	     case 5:d=31;break; 
	     case 6:d=30;break;
       	 case 7:d=31;break;
	     case 8:d=31;break;
	     case 9:d=30;break;
	     case 10:d=31;break; 
	     case 11:d=30;break;
       	 case 12:d=31;break;
        }  
        printf("%d",d); 
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}
int date (int year)
{
	if(year%4!=0)
	{return 0;}
	if(year%4==0&&year%100!=0)
	{return 1;}
	if(year%4==0&&year%100==0&&year%400==0)
	{return 1;}
	if(year%4==0&&year%100==0&&year%400!=0)
	{return 0;} 
    return 0;
}
