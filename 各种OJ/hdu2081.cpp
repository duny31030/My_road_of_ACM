#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    int n;
    cin >> n;
    char s[12];
    while(n--)
    {
        scanf("%s",s);
        printf("6");
        for(int i = 6;i <= 10;i++)
            printf("%c",s[i]);
        printf("\n");
    }   
	
	return 0;
}
