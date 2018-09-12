#include <bits/stdc++.h>
using namespace std;  
  
const int C = 10;  
const int n = 5;  
const int w[] = {0,2,2,6,5,4};  
const int v[] = {0,6,3,5,4,6};  
int Make(int i, int j)  
{    
    int r1 = 0;  
    int r2 = 0;  
    int r = 0;  
      
    if (i == 0)  
    {  
        return 0;  
    }  
  
    if(j >= w[i])   //背包剩余空间可以放下物品 i    
    {  
        r1 = Make(i-1,j - v[i]) + w[i]; //第i件物品放入所能得到的价值  
        r2 = Make(i-1,j); //第i件物品不放所能得到的价值    
        r = (r1>r2)?r1:r2;  
    }     
  
    return r;  
}  
  
  
int main()  
{  
    printf("==========================\n背包内最大总价值为：%d\n==========================\n",Make(n,C));
    return 0;
}  