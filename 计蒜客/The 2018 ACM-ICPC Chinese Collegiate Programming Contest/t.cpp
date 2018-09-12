#include <iostream>
#include <map>
using namespace std;
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
map<ll,ll> mp,mp2;
int a[15] = {0,1,2,4,8,16,32,64,128,256,512,11,12,13,14};

void dfs(int now,int step,ll sum,int stop)
{   
    if(step == stop || now > 10)
    {
        if(now <= 10)
            mp[sum]++;
        return ;
    }
    for(int i = now;i <= 10;i++)
    {
        dfs(now+1,step+1,sum+a[i],stop);
        dfs(now+1,step,sum,stop);
    }
    return ;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
    //    freopen("in.txt","r",stdin);
     freopen("out.txt","w",stdout); 
#endif
    ll sum = 0;
    for(int i = 1;i <= 10;i++)
        sum += a[i];
    cout << "sum = " << sum << endl;
    /*
    for(int i = 2;i <= 5;i++)
    {
        dfs(1,0,0,i);
        cout << "i = " << i << endl;
    }
     */
    for(int i = 1;i <= 10;i++)
    {
        for(int j = i+1;j <= 10;j++)
        {
            mp[a[i]+a[j]]++;
            mp[sum-a[i]-a[j]]++;

        }
    }
    for(int i = 1;i <= 10;i++)
    {
        for(int j = i+1;j <= 10;j++)
        {
            for(int k = j+1;k <= 10;k++)
            {
                mp[a[i]+a[j]+a[k]]++;
                mp[sum-a[i]-a[j]-a[k]]++;
            }
        }
    }
    for(int i = 1;i <= 10;i++)
    {
        for(int j = i+1;j <= 10;j++)
        {
            for(int k = j+1;k <= 10;k++)
                for(int l = k+1;l<= 10;l++)
                {
                    mp[a[i]+a[j]+a[k]+a[l]]++;
                    mp[sum-a[i]-a[j]-a[k]-a[l]]++;

                }
        }
    }
    for(int i = 1;i <= 10;i++)
    {
        for(int j = i+1;j <= 10;j++)
        {
            for(int k = j+1;k <= 10;k++)
                for(int l = k+1;l<= 10;l++)
                    for(int m = l+1;m <= 10;m++)
                    {
                        mp[a[i]+a[j]+a[k]+a[l]+a[m]]++;
                        mp[sum-a[i]-a[j]-a[k]-a[l]-a[m]]++;

                    }
        }
    }
    // cout << "Fuck!!" << endl;
    cout << "11111:::" <<mp.size() << endl;
    map<ll,ll>::iterator it;
       // cout << "yyyyy" << endl;
    for(it = mp.begin();it != mp.end();it++)
        if(it->second == 1)
            cout << it->first << endl;
    // cout << "Y" << endl;
     //   cout << it->first << " " << it->second << endl;

    fclose(stdin);
     fclose(stdout);
    return 0;
}
