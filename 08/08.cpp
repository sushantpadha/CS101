#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void f1() {
    int x;
    int &r = x;
    // x = 5;
    printf("x=%d, r=%d\n", x, r);
    r = 10;
    printf("x=%d, r=%d\n", x, r);
    x = 20;
    printf("x=%d, r=%d\n", x, r);
    printf("x==r is %d\n", (x==r));
    printf("&x=%p, &r=%p\n", &x, &r);
}

void f2() {
    int x = 5;
    int y = 6;
    int *p;
    p = &x;
    p = &y;
    *p = 10;
    printf("%d\n", x);
    printf("%d\n", y);
}

void f3() {
    const int& a = int(12);
    printf("int& a is %d\n", a);
}

void swap(int& x, int& y) {
	int tmp = x; x = y; y = tmp;
}

int increment(int& x, const int y) {
    x += y;
    return x;
}

void sin_cos(double rad, double& sinx, double& cosx) {
    sinx = sin(rad); cosx = cos(rad);
}


int& maximum(int& x, int& y) {
	return ((x>y) ? x : y);
}

int main()
{
    int x = 2, y = 5;
    printf("x=%d, y=%d\n", x, y);
    swap(x, y);
    printf("x=%d, y=%d\n", x, y);
    printf("increment(x+y)=%d\n", increment(x,y));
    printf("x=%d, y=%d\n", x, y);

    printf("maximum(x,y)=%d\n", maximum(x,y));
    maximum(x,y) = 100;  // int& can be used as lvalue
    printf("maximum(x,y)=%d\n", maximum(x,y));
    printf("x=%d, y=%d\n", x, y);

    double t=3.14159/2, sint, cost;
    sin_cos(t, sint, cost);  // sets multiple variables
    printf("t=%f, sint=%f, cost=%f\n", t, sint, cost);
}

