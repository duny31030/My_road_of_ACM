/*
 * =========================================================================
 *
 *       Filename:  D-2.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/01 18时58分30秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include<cstdio>
#include<cstring>
#include<algorithm>
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
const int maxn=50010;
int sa[maxn],rk[maxn],height[maxn],t[maxn],t2[maxn],c[maxn],d[maxn][23];
char str[maxn];
int n,len;
void build_sa(int m)
{    
    int *x=t,*y=t2;    
    for(int i=0;i<m;i++)c[i]=0;    
    for(int i=0;i<n;i++)c[x[i]=str[i]]++;    
    for(int i=1;i<m;i++)c[i]+=c[i-1];    
    for(int i=n-1;i>=0;i--)sa[--c[x[i]]]=i;    
    for(int k=1;k<=n;k<<=1)    
    {        
        int p=0;        
        for(int i=n-k;i<n;i++)y[p++]=i;        
        for(int i=0;i<n;i++)if(sa[i]>=k)y[p++]=sa[i]-k;        
        for(int i=0;i<m;i++)c[i]=0;        
        for(int i=0;i<n;i++)c[x[y[i]]]++;        
        for(int i=1;i<m;i++)c[i]+=c[i-1];        
        for(int i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];        
        swap(x,y);        
        x[sa[0]]=0;p=1;        
        for(int i=1;i<n;i++)            
            x[sa[i]]=(y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k])?p-1:p++;      
        if(p>=n)break;        
        m=p;    
    }
}
void getheight()
{    
    int k=0;    
    for(int i=1;i<=n;i++)rk[sa[i]]=i;    
    for(int i=0;i<n;i++)    
    {        
        if(k)k--;        
        int j=sa[rk[i]-1];        
        while(str[i+k]==str[j+k])k++;        
        height[rk[i]]=k;    
    }
}
void InitRMQ()
{    
    for(int i=0;i<=n;i++)
        d[i][0]=height[i];    
    for(int j=1;(1<<j)<=n;j++)        
        for(int i=0;i+(1<<j)-1<=n;i++)//为什么要减个1        
            d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}
int lcp(int a,int b)
{    
    int l=rk[a],r=rk[b];    
    if(l>r)swap(l,r);l++;    
    int k=0;    
    while((1<<(k+1))<=(r-l+1))k++;    
    return min(d[l][k],d[r-(1<<k)+1][k]);
}
void solve()
{    
    int maxv=0;    
    for(int l=1;l<n;l++)   
    {        
        for(int i=0;i+l<n;i+=l)        
        {            
            int m=lcp(i,i+l);            
            int ans=m/l+1;            
            int k=i-(l-m%l);            
            if(k>=0)            
            {                
                if(lcp(k,k+l)>=(l-m%l))                    
                    ans++;            
            }            
            if(ans>maxv)                
                maxv=ans;        
        }    
    }    
    printf("%d\n",maxv);
}

int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int T;    
    scanf("%d",&T);    
    while(T--)    
    {        
        scanf("%d",&n);        
        getchar();        
        for(int i=0;i<n;i++)
            scanf("%c\n",&str[i]);        
        str[n]='\0';        
        n++;        
        build_sa(128);        
        n--;        
        getheight();        
        InitRMQ();        
        solve();    
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

