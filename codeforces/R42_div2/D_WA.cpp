// STL的嵌套使用  有点难
// WA
#define _CRT_SBCURE_NO_DEPRECATE
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int maxn = 1e9+7;
const int INF = 0x3f3f3f3f;

priority_queue<int,vector<int>,greater<int> >q[1000005];
map<ll,int>m;
ll a[1000005];
ll b[1000005];
int id[1000005],dd[1000005];

bool cmp(int x,int y)
{
    return id[x] < id[y];
}

int main()
{
    int n;
    scanf("%d",&n);
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(m[a[i]] == 0)
        {
            ans++;
            m[a[i]] = ans;
            b[ans] = a[i];
        }
        q[m[a[i]]].push(i);
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++)
    {
        ll s = a[i];
        for(int j = 1;j <= 64;j++)
        {
            if(q[m[s]].size() < 2)
                break;
            ll s2 = s*2;
            if(m[s2] == 0)
            {
                ans ++;
                m[s2] = ans;
                b[ans] = s2;
            }
            int d1 = m[s],d2 = m[s2];
            while(q[d1].size() >= 2)
            {
                q[d1].pop();
                int d = q[d1].top();
                q[d1].pop();
                q[d2].push(d);
            }
            s = s*2;
        }
    }
    int num = 0;
    for(int i = 1;i <= ans;i++)
    {
        dd[i] = i;
        if(q[i].size() == 1)
        {
            num++;
            id[i] = q[i].top();
        }
    }
    sort(dd+1,dd+1+ans,cmp);
    cout<<num<<endl;
    for(int i = 1;i <= ans;i++)
    {
        if(id[dd[i]] == 0x3f3f3f3f)
        {
            break;
        }
        cout << b[dd[i]] << " ";
    }
    cout << endl;
    return 0;
}


