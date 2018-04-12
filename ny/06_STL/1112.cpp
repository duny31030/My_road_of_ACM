#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main() 
{
    int n;
    scanf("%d",&n);
    
    while(n--)
    {
        int m;
        scanf("%d",&m);
        map<string,int> a;
        int ans = 0;
        string str;
        //scanf("%d",&m);
        cin >> str;
        // cout << str.length() << endl;
        for(int i = 0;i <= str.length()-m;i++)
        {
            string s = str.substr(i,m);
            if(a[s] != 0)
                ans++;
            else
                a[s] = 1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
