#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define mst(a,b) memset((a),(b),sizeof(a))
#define rush() int T;scanf("%d",&T);while(T--)

typedef long long ll;
const int maxn = 100005;
const ll mod = 1e9+7;

typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 1e9;
typedef long double ld;

int n,m,q;
string s1;
string s2;

int a[maxn];

int main()
{
    #ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif

    scanf("%d%d%d",&n,&m,&q);
    cin>>s1>>s2;
    int pre=0;
    for(int i=1;i<=n;i++)
    {
        string tmp=s1.substr(0,i);
        //cout<<tmp<<endl;
        int cnt=0;
        while(1)
        {
            int id=tmp.find(s2);
            if(id==-1) break;
            cnt++;
            int k=tmp.size();
            tmp=tmp.substr(id+1,k-(id+1)+1);
        }
        a[i]=cnt;
    }
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%d\n",a[r]-a[l+(m-2)]);
    }
        fclose(stdin);
    // fclose(stdout);

        return 0;
}
