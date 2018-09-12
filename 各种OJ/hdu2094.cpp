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
	ios
	int n;
	while(cin >> n)
	{
		if(n == 0)
			break;
		string s1,s2;
		map<string,int> m1;
		map<string,int> m2;
		for(int i = 1;i <= n;i++)
		{
			cin >> s1;
			cin >> s2;
			if(m2[s1] == 0)
			{
				m1[s1] = 1;
			}

			if(m1[s2] != 0)
			{
				m1[s2] = 0;
			}

			m2[s2] = 1;
		}
		map<string,int>::iterator it;
		int ans = 0;
		for(it = m1.begin();it != m1.end();it++)
		{
			if(it->second == 1)
			ans++;
		}
		if(ans == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}
	

	return 0;
}


