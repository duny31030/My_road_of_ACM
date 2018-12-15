/*
 * =========================================================================
 *
 *       Filename:  EE.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/09/11 18时07分49秒
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
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=n;i>=a;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5+20;
int a[N],b[N],T[N],L[N*20],R[N*20],sum[N*20];
int tot = 0,n,q,x,y,z,m;

int Build(int l,int r)
{
    int rt = ++tot;
    int mid = (l+r)>>1;
    if(l < r)
    {
        L[rt] = Build(l,mid);
        R[rt] = Build(mid+1,r);
    }
    return rt;
}

int update(int pre,int l,int r,int x)
{
    int rt = ++tot;
    int mid = (l+r)>>1;
    L[rt] = L[pre]; R[rt] = R[pre]; sum[rt] = sum[pre]+1;
    if(l < r)
    {
        if(x <= mid)
            L[rt] = update(L[pre],l,mid,x);
        else 
            R[rt] = update(R[pre],mid+1,r,x);
    }
    return rt;
}

int query(int u,int v,int l,int r,int Ll,int Rr)
{
    if(Ll > Rr)
        return 0;
    if(l >= Ll && r <= Rr)
        return sum[v]-sum[u];
    int mid = (l+r)>>1;
    int ans = 0;
    if(mid >= Ll)
        ans += query(L[u],L[v],l,mid,Ll,Rr);
    if(mid < Rr)
        ans += query(R[u],R[v],mid+1,r,Ll,Rr);
    return ans;
}


int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int t;
    int cas = 1;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",cas++);
        tot = 0;
        clr(T,0);   clr(sum,0); clr(L,0);   clr(R,0);   clr(a,0);   clr(b,0);
        scanf("%d %d",&n,&q);
        rep(i,1,n)
        {
            scanf("%d",&a[i]);
            b[i] = a[i];
        }   
        sort(b+1,b+1+n);
        m = unique(b+1,b+1+n)-b-1;
        T[0] = Build(1,m);
        rep(i,1,n)
        {
            a[i] = lower_bound(b+1,b+1+m,a[i])-b;
            T[i] = update(T[i-1],1,m,a[i]);
        }
        rep(i,1,q)
        {
            scanf("%d %d %d",&x,&y,&z);
            int pos = upper_bound(b+1,b+1+m,z)-b-1;
            // if(pos > 1)
            // {   
                int p = query(T[x],T[y+1],1,m,1,pos);
                printf("%d\n",p);
            // }
            // else 
               //  printf("0\n");
        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

