/*
 * =========================================================================
 *
 *       Filename:  F.cpp
 *
 *           Link:  https://www.spoj.com/problems/REPEATS/en/
 *
 *        Version:  1.0
 *        Created:  2018/10/01 16时25分51秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
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
const int MAXN = 1e5+10;;

int wa[MAXN],wb[MAXN],wv[MAXN],ws[MAXN];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b] && r[a+l]==r[b+l];
}
int sa[MAXN],rk[MAXN],height[MAXN];
int n,a[MAXN];
char r[MAXN];
int minnum[MAXN][16];
void SA(char *r,int n,int m)
{
    int *x=wa,*y=wb;

    for(int i=0; i<m; ++i) ws[i]=0;
    for(int i=0; i<n; ++i) ++ws[x[i]=r[i]];
    for(int i=1; i<m; ++i) ws[i]+=ws[i-1];
    for(int i=n-1; i>=0; --i) sa[--ws[x[i]]]=i;

    int p=1;
    for(int j=1; p<n; j<<=1,m=p)
    {
        p=0;
        for(int i=n-j; i<n; ++i) y[p++]=i;
        for(int i=0; i<n; ++i) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(int i=0; i<n; ++i) wv[i]=x[y[i]];
        for(int i=0; i<m; ++i) ws[i]=0;
        for(int i=0; i<n; ++i) ++ws[wv[i]];
        for(int i=1; i<m; ++i) ws[i]+=ws[i-1];
        for(int i=n-1; i>=0; --i) sa[--ws[wv[i]]]=y[i];
        swap(x,y); x[sa[0]]=0; p=1;
        for(int i=1; i<n; ++i) x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }

    for(int i=1; i<n; ++i) rk[sa[i]]=i;
    int k=0;
    for(int i=0; i<n-1; height[rk[i++]]=k)
    {
        if(k) --k;
        for(int j=sa[rk[i]-1]; r[i+k]==r[j+k]; ++k);
    }
}

void initRMQ()   		//预处理  O(nlogn)
{	
    int i,j;	
    int m=(int)(log(n*1.0)/log(2.0));	
    for(i=1;i<=n;i++)		
        minnum[i][0]=height[i];	
    for(j=1;j<=m;j++)		
        for(i=1;i+(1<<j)-1<=n;i++)			
            minnum[i][j]=min(minnum[i][j-1],minnum[i+(1<<(j-1))][j-1]);
}

int Ask_MIN(int a,int b) 	//O(1)
{
	int k=int(log(b-a+1.0)/log(2.0));
	return min(minnum[a][k],minnum[b-(1<<k)+1][k]);
}
int lcp(int a,int b)
{
    a=rk[a],b=rk[b];
    if(a>b)
        swap(a,b);
    return Ask_MIN(a+1,b);
}


int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int t,i,j,k,l,ans,Max;
    scanf("%d",&t);
    // t = 1;
    getchar();       
    while(t--)
    {
        Max = 1;
        scanf("%d",&n);
        // n = 4;
        getchar();
        for(i = 0;i < n;i++)
        {    
            scanf("%c",&r[i]);
            getchar();
        }
        r[n] = 0;
        SA(r,n+1,130);
        initRMQ();
        for(l = 1;l < n;l++)   // 枚举长度
        {
            for(j = 0;j+l < n;j += l)
            {
                int tmp = lcp(j,j+l);
                k = j-(l-tmp%l);
                ans = tmp/l+1;
                if(k >= 0 && lcp(k,k+l) >= (l-tmp%l))
                    ans++;
                printf("ans = %d\n",ans);
                Max = max(Max,ans);
            }
        }
        printf("%d\n",Max);
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

