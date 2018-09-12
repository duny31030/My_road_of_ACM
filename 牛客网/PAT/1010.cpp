#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct
{
    int store;
    int sum;
    double price;
}mooncake;

bool cmp(mooncake a,mooncake b)
{
    return a.price>b.price;
}

int main()
{
    int n,d;
    mooncake moon[1010];
    double profit=0;

    cin >> n >> d;

    for(int i=0;i<n;i++)
    {
        cin >> moon[i].store;
    }
    for(int i=0;i<n;i++)
    {
        cin >> moon[i].sum;
        moon[i].price=(moon[i].sum*1.0)/moon[i].store;
    }

    sort(moon,moon+n,cmp);

    for(int i=0;i<n && d>0;i++)
    {
        if(d >= moon[i].store)
        {
            profit += moon[i].sum;
            d -= moon[i].store;
        }
        else
        {
            profit += moon[i].price*d;
            d=0;
        }
    }

    printf("%.2f\n",profit);
    return 0;
}
