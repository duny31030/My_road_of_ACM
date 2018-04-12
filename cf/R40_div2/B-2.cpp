#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int t = 0;
	for(int i = (s.size())/2;i >= 0;i--)
	{
		if(s.substr(0,i) == s.substr(i,i))
		{
			t = i;
			break;
		}
	}
	if(t > 0)
		cout << t+1+(n-(2*t));
	else
		cout << n;
	return 0;
}


