// 不知道怎么错的  原因不明

#include<iostream>
using namespace std;
int n;
int s[1001];
int t[1001];
int x[1001];
int main()
{
    while(cin>>n)
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>s[i]>>t[i];
            if(t[i]==1||t[i]==2)cin>>x[i];
        }
        int left=0,right=0;
        while(right<n)
        {
            int index=left;
            while(s[++right]>=s[index++]);
            for(int i=right-1;i>=left;i--)
            {
                switch(t[i])
                {
                    case 1:ans+=x[i];
                    break;
                    case 2:ans+=x[i]*(i-left+1);
                    break;
                    case 3:i=left;
                    break;
                    case 4:i--;
                    break;
                }
            }
            left=right;
        }
        cout<<ans<<endl;
    }
    return 0;
}