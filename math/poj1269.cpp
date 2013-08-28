//p2p1=(x2-x1,y2-y1)
//p3p4=(x4-x3,y4-y3)
//如果向量P2P1和p3p4平行，则p2p1Xp3p4=0;
//如果P2P1和p3p4共线，则p2p1Xp3p1=0 & p2p1Xp4p1=0
//如果p2p1和p3p4相交于点p0，则 p2p0Xp1p0=0 && p3p0Xp4p0=0
#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

#include <cmath>

using namespace std;
struct Point
{
	double x;
	double y;
};
Point p1,p2,p3,p4;

const double ERR = 0.000001;
void DealData();
double Direction(Point p1, Point p2, Point p3);
int main()
{
	freopen("1269.txt","r",stdin);
	int n = 0;
	scanf("%d", &n);
	printf("INTERSECTING LINES OUTPUT\n");
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y, &p4.x, &p4.y);
		DealData();
	}
	printf("END OF OUTPUT\n");
	return 0; 
}

/*	p1p2 与 p1p3的叉乘	*/

double Direction(Point p1, Point p2, Point p3)
{
	return (p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y);
}
void DealData()
{
	if (fabs(Direction(p1,p2,p3)) <= ERR 
		&& fabs(Direction(p1,p2,p4)) <= ERR)
			printf("LINE\n");
	else if ((p2.x - p1.x) * (p4.y - p3.y) == (p4.x - p3.x) * (p2.y - p1.y))
		printf("NONE\n");
	else
	{
		double a1 = p1.y - p2.y;
		double b1 = p2.x - p1.x;
		double c1 = p1.x*p2.y - p2.x*p1.y;
		double a2 = p3.y - p4.y;
		double b2 = p4.x - p3.x;
		double c2 = p3.x*p4.y - p4.x*p3.y;
		double x = (b1*c2 - b2*c1)/(a1*b2 - a2*b1);
		double y = (a2*c1 - a1*c2)/(a1*b2 - a2*b1);
		printf("POINT %.2f %.2f\n", x, y);

	}

}