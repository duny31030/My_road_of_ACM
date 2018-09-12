//https://www.nowcoder.com/pat/6/problems
//牛客网PAT乙级真题
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int i=1;i<=T;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if(a > c-b)
            printf("Case #%d: true\n",i);
        else
            printf("Case #%d: false\n",i);
    }
    return 0;
}
