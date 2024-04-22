#include <stdio.h>

double fn(double x)
{
    return x*x + 12*x +6;
}

double calc_trapezoid_area(double x1, double y1, double x2, double y2)
{
    double h = x2 - x1;
    return (y1+y2)*h/2.0;
}

double integrate_fn(double from, double to)
{
    double delta = 10e-9;
    double x1 = from, x2, y1, y2, area, sum = 0;

    y1 = fn(x1);
    do {
        x2 = x1 + delta;
        y2 = fn(x2);
        area = calc_trapezoid_area(x1, y1, x2, y2);
        sum += area;
        x1 = x2;
        y1 = y2;
    } while(x1 < to);

    return sum;
}

int main(int argc, const char* argv[])
{
    double r;
    puts("gecalculus by Raymond developed on the train to Lushan on April 18, 2024");

    r = integrate_fn(1, 5);

    printf("Integrate x*x+12x+6 from 0 to 5 gets %f\n", r);

    return 0;
}

