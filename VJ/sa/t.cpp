#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define o 20001
#define rep(i,a,b) for(int i=int(a),nn=int(b);i<=nn;i++)
#define vep(i,a,b) for(int i=int(a),nn=int(b);i>=nn;i--)
#define nep(i,a,b) for(int i=int(a),nn=int(b);i<nn;i++)
using namespace std;
int t1[o],t2[o],sa[o],Rank[o],height[o],s[o],cc[o],st[o][20],num[o],lq[o];
int n,k_k,len,ans,cnt;
bool cmp(int a,int b){return lq[a]<lq[b];}
bool compare(int *y,int a,int b,int k)
{
    int arank1,arank2,brank1,brank2;
    arank1=y[a];
    brank1=y[b];
    arank2=a+k>=len?-1:y[a+k];
    brank2=b+k>=len?-1:y[b+k];
    return arank1==brank1&&arank2==brank2;
}
void make_sa()
{
    int *x=t1,*y=t2,m=cnt+1;
    nep(i,0,m)cc[i]=0;
    nep(i,0,len)cc[x[i]=s[i]]++;
    nep(i,1,m)cc[i]+=cc[i-1];
    vep(i,len-1,0)sa[--cc[x[i]]]=i;
    for(int k=1;k<=len;k<<=1)
    {
        int p=0;
        nep(i,len-k,len)y[p++]=i;
        nep(i,0,len)if(sa[i]>=k)y[p++]=sa[i]-k;
        nep(i,0,m)cc[i]=0;
        nep(i,0,len)cc[x[y[i]]]++;
        nep(i,1,m)cc[i]+=cc[i-1];
        vep(i,len-1,0)sa[--cc[x[y[i]]]]=y[i];
        swap(x,y);
        m=1;x[sa[0]]=0;
        nep(i,1,len)
        x[sa[i]]=compare(y,sa[i],sa[i-1],k)?m-1:m++;
        if(m>=len)break;
    }
}
void make_height()
{
    nep(i,0,len)Rank[sa[i]]=i;
    int k=0;
    height[0]=0;
    nep(i,0,len)
    {
        if(!Rank[i])continue;
        int j=sa[Rank[i]-1];
        if(k)k--;
        while(s[i+k]==s[j+k])k++;
        height[Rank[i]]=k;
    }
}
void init()
{
    nep(i,0,n)st[i][0]=height[i];
    for(int j=1;(1<<j)<n;j++)
    for(int i=0;i+(1<<j)-1<n;i++)
    st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int query(int l,int r)
{
    int k=log2(r-l+1);
    return min(st[l][k],st[r-(1<<k)+1][k]);    
}
bool check(int length)
{
    int l=0,r=l+k_k-2;
    while(r<=n-1)
    {
        int ok=query(l,r);
        if(ok>=length)return true;
        l++;r++;
    }
    return false;
}
int main()
{
    #ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d%d",&n,&k_k);
    nep(i,0,n)scanf("%d",&lq[i]),num[i]=i;
    len=n;
    sort(num,num+n,cmp);
    s[num[0]]=1;
    cnt=1;
    for(int i=0;i<n-1;i++)
        if(lq[num[i]]!=lq[num[i+1]])s[num[i+1]]=++cnt;
        else s[num[i+1]]=cnt;
    make_sa();
    make_height();
    init();
    for(int i = 0;i <= n;i++)
        printf("%d ",height[i]);
    printf("\n");
    int l=1,r=n,answer=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))answer=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",answer);
}
