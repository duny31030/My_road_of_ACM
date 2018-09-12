#include <cstdio>

using namespace std;

int a[10]={0},book[10]={0},n;

void dfs(int step)
{
    int i;
    if(step == n+1)
    {
        for(i=1;i<=n;i++)
        {   
            if(i!=n)
                printf("%d ",a[i]);
            if(i == n)
                printf("%d\n",a[i]);

        }
            
        return ;

    }

    for(i=1;i<=n;i++)
    {
        if(book[i]==0)
        {
            a[step]=i;
            book[i]=1;

            dfs(step+1);
            book[i]=0;
        }
    }
    return ;
}



int main()
{
    n=8;
    dfs(1);
    
    return 0;
}
