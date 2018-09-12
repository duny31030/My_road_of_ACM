#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    ll a[22];
    a[0] = 0;
    a[1] = 0;
    a[2] = 1;
    for(int i = 3;i <= 20;i++)
    {
        a[i] = (i-1)*(a[i-1] + a[i-2]);
    }
    int c,temp;
    cin >> c;
    while(c--)
    {
        scanf("%d",&temp);
        ll s = 1;
        for(int i = 1;i <= temp;i++)
        {
            s *= i;
        }
        printf("%.2lf%%\n",(double)(a[temp]*1.0)*100.0/s);
    }
	
	return 0;
}
