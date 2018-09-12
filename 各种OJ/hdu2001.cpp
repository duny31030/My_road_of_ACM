#include <bits/stdc++.h>

using namespace std;

int main()
{
	double x1,x2,y1,y2;
	double out;
	while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)!=EOF)
	{
		double t1,t2;
		t1 = abs(x2-x1);
		t2 = abs(y2-y1);
		out = sqrt(t1*t1+t2*t2);
		printf("%.2f\n",out);
	}
	return 0;
}