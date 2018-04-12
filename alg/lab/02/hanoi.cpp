#include <bits/stdc++.h>

using namespace std;

int ans = 0;

void hanoi(int n,int a,int b,int c)
{
    if(n)
    {
        hanoi(n-1,a,c,b);
        printf("第%3.d步 : %d -> %d\n",++ans,a,b);
        hanoi(n-1,c,b,a);
    }
}

int main()
{
    int n;
    printf("请输入汉诺塔高度：");
    scanf("%d",&n);
    hanoi(n,1,2,3);
    printf("移动完成。\n共经历%d步。\n",ans);
    
    return 0;
}
