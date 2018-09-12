#include <bits/stdc++.h>

using namespace std;

int main()
{
	char s2[30];
	s2[0] = 'a';
	for(int i = 1;i <= 25;i++)
	{
		s2[i] = s2[i-1]+1;
	}

	char s1[1000010];
	cin >> s1;
	
	int ans = 0;
	int n = strlen(s1);
	for(int i = 0;i < n && ans <= 25;i++)
	{
		if(s1[i] <= s2[ans])
		{
			s1[i] = s2[ans];
			ans++;
		}
	}
	if(ans > 25 )
	{
		cout << s1 << endl;
	}
	else
	{
		cout << "-1" << endl;
	}
	return 0;
}