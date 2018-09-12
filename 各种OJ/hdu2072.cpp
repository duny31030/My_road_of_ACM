#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool cmp(const int &a,const int &b)
{
	return a>b;
}


int main()
{
	string s;
	while(getline(cin,s))
	{
		if(s[0] == '#')
			break;
		int p = 1;
		for(int i = 1;i < s.size();i++)
		{
			if(s[i] == ' ' && s[i+1] != ' ')
				p++;
		}
		printf("%d\n",p);
	}
	
	return 0;
}


