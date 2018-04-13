#define _CRT_SBCURE_NO_DEPRECATE
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	string s,s1,s2;
	s1 = "you";
	s2 = "we";
	int sign;
	while(getline(cin,s))
	{
		sign = s.find(s1,0);
		while(sign != string::npos)
		{
			s.replace(sign,3,s2);
			sign = s.find(s1,sign+1);
		}
		cout << s << endl;
	}
	
	return 0;
}


