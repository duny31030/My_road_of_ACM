/*
 * =========================================================================
 *
 *       Filename:  test.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/09/21 23时54分10秒
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
const int MAXN = 1e5+10;
int n;
int wa[MAXN],wb[MAXN],wv[MAXN],ws[MAXN];
int sa[MAXN],rk[MAXN],height[MAXN];
int ht[MAXN],c[MAXN],a[MAXN];
void SA(int *r,int n,int m){
    int *x=wa,*y=wb;

    for(int i=1; i<=m; ++i) ws[i]=0;
    for(int i=1; i<=n; ++i) ++ws[x[i]=r[i]];
    for(int i=1; i<=m; ++i) ws[i]+=ws[i-1];
    for(int i=n; i>=1; --i) sa[ws[x[i]]--]=i;

    int p=1;
    for(int k=1;k <= n;k<<=1)
    {
        p=0;
        for(int i=n-k+1;i <= n;++i) y[p++]=i;
        for(int i=1; i<=n; ++i) if(sa[i]>k) y[p++]=sa[i]-k;
        for(int i=1; i<=n; ++i) wv[i]=x[y[i]];
        for(int i=1; i<=m; ++i) ws[i]=0;
        for(int i=1; i<=n; ++i) ++ws[wv[i]];
        for(int i=1; i<=m; ++i) ws[i] += ws[i-1];
        for(int i=n; i>=1; --i) sa[ws[wv[i]]--]=y[i];
        swap(x,y); x[sa[1]]=1; p=1;
        for(int i=2; i<=n; ++i) 
            x[sa[i]]=(y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k])?p:++p;    
    }

    for(int i=1; i<=n; ++i) rk[sa[i]]=i;
    for(int i=1,j,k = 0; i<=n;i++)
    {
        if(k) --k;
        j = sa[rk[i]-1];
        while(r[i+k] == r[j+k])
            k++;
        height[rk[i]] = k;
    }
}


void build_sa(int *a,int n,int m){
    int i,*x=rk,*y=ht;
    for(i=1;i<=m;i++) c[i]=0;
    for(i=1;i<=n;i++) c[x[i]=a[i]]++;
    for(i=1;i<=m;i++) c[i]+=c[i-1];
    for(i=n;i;i--) sa[c[x[i]]--]=i;
    for(int k=1,p;k<=n;k<<=1){
        p=0;
        for(i=n-k+1;i<=n;i++) y[++p]=i;
        for(i=1;i<=n;i++) if(sa[i]>k) y[++p]=sa[i]-k;
        for(i=1;i<=m;i++) c[i]=0;
        for(i=1;i<=n;i++) c[x[y[i]]]++;
        for(i=1;i<=m;i++) c[i]+=c[i-1];
        for(i=n;i;i--) sa[c[x[y[i]]]--]=y[i];
        swap(x,y); x[sa[1]]=1; p=1;
        for(i=2;i<=n;i++)
            x[sa[i]]=(y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k])?p:++p;
        if(p==n) break; m=p;
    }
    for(i=1;i<=n;i++) rk[sa[i]]=i;
    for(int i=1,j,k=0;i<=n;i++){
        if(k) k--;
        j=sa[rk[i]-1];
        while(a[i+k]==a[j+k]) k++;
        ht[rk[i]]=k;
    }
}

int r[MAXN];

bool isok(int k)
{
    int mx = -INF,mn = INF;
    for(int i = 2;i <= n;i++)
    {
        if(height[i] >= k)
        {
            mn = min(sa[i],sa[i-1]);
            mx = max(sa[i],sa[i-1]);
            if(mx-mn >= k)
                return true;
            else 
            {
                mx = -INF;
                mn = INF;
            }
        }
    }
    return false;
}


void debug()
{
    printf("sa[]:\n");
    rep(i,0,n)
        printf("%d ",sa[i]);
    printf("\n");
    printf("rk[]:\n");
    rep(i,0,n)
        printf("%d ",rk[i]);
    printf("\n");
    printf("height[]:\n");
    rep(i,0,n)
        printf("%d ",height[i]);
    printf("\n");
}

int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    while(~scanf("%d",&n))
    {   
        if(n == 0)
            break;
        rep(i,0,n-1)
            scanf("%d",&a[i]);
        // scanf("%s",s);int len=strlen(s);
        for(int i=n-1;i;i--)    r[i]=a[i]-a[i-1]+100;
        // r[n] = 0;
        build_sa(r,n,200);
        // debug();
        int l = 0,r = n+1;
        while(l != r)
        {
            int mid = (l+r)>>1;
            if(isok(mid))
                l = mid+1;
            else 
                r = mid;
        }
        printf("%d\n",l);
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

