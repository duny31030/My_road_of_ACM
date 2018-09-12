//
//目前vim仍然对string头文件中的size()函数报错
//尚未解决
//
//
//
#include <iostream>
#include <cstdio>
#include <string>
 
using namespace std;
 
int main()
{
    string s1;
    string s2;
    string s3;
    string s4;
    cin>>s1>>s2>>s3>>s4;
    //输出周几
    int mark=0;
    for(int i=0;i<s1.size()&&i<s2.size();i++)
    {
        if(s1[i] == s2[i] && (s1[i]>='A' && s1[i]<='G'))
        {
            mark=i;
            switch(s1[i])
            {
                case 'A': cout <<"MON "; break;
                case 'B': cout <<"TUE "; break;
                case 'C': cout <<"WED "; break;
                case 'D': cout <<"THU "; break;
                case 'E': cout <<"FRI "; break;
                case 'F': cout <<"SAT "; break;
                case 'G': cout <<"SUN "; break;
            }
            break;
        }
    }
     
    //输出时间(时)
 
    for(int j=mark+1;j<s1.size()&&j<s2.size();j++)
    {
        if(s1[j] == s2[j] && ((s1[j]>='A' && s1[j]<='N') || (s1[j]>='0' && s1[j] <='9')))
        {
            if(s1[j]>='A' && s1[j]<='N')
            {
                int x=s1[j]-'A'+10;
                cout <<x/10<<x%10<<":";
            }
            else
            {
                int x=s1[j]-'0';
                cout <<x/10<<x%10<<":";
            }
            break;
        }
      
        
    }
     
    //输出时间(分)
    for(int i=0;i<=s3.size() && i<=s4.size();i++)
    {
        if(s3[i] == s4[i] && ((s3[i]>='A' && s3[i]<='Z') || (s3[i]>='a' && s3[i]<='z')))
        {
            cout<<i/10<<i%10<<endl;
            break;
        }
    }
     
     
    return 0;
}
