#include<bits/stdc++.h>
using namespace std;
 
int main()
{   

 long n;
    cin>>n;
    long sum=0;
    long a[n];
    for(long i=0;i<n;i++)
    {cin>>a[i];sum+=a[i];}
    long temp=0;
    int index;
    for(long i=0;i<n;i++)
    {
        temp+=a[i];
        if(temp>=sum/2)
        {
            index=i;
            break;
        }
    }
    
    
    cout<<index+1<<endl;
}