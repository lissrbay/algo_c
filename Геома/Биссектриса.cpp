#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    int n; double a,b,a2,b2,c,c2,al,bl,cl,A,B,C,x0,y0,x1,y1,x2,y2,x,y;
    freopen("bisector.in", "r", stdin);
    freopen("bisector.out", "w", stdout);
	cin>>x0>>y0>>x1>>y1>>x2>>y2;
	al=sqrt((x1-x0)*(x1-x0)+(y1-y0)*(y1-y0));
	bl=sqrt((x2-x0)*(x2-x0)+(y2-y0)*(y2-y0));
	a=y2-y0; b=x0-x2; c=x2*y0-x0*y2;
	a2=y1-y0; b2=x0-x1; c2=x1*y0-x0*y1;
	A=a*sqrt(a2*a2+b2*b2)+a2*(sqrt(a*a+b*b));
	B=b*sqrt(a2*a2+b2*b2)+b2*(sqrt(a*a+b*b));
	C=c*sqrt(a2*a2+b2*b2)+c2*(sqrt(a*a+b*b));
   printf("%f %f %f",A,B,C);
}