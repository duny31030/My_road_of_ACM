#include <bits/stdc++.h>

using namespace std;



int main()
{
	std::map<char, int> map;
	char x = 'a';
	printf("%d\n",(int)map.size());
	map[x] = 1;
	printf("%d\n",map[x]);
	printf("%d\n",(int)map.size());
	printf("map[x] = %d\n",map[x] = 2);
	map[x] = 2;
	printf("%d\n",map[x]);
	printf("%d\n",(int)map.size());
	return 0;
}


