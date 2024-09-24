#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double area(Point A, Point B, Point C) {
    return fabs(A.x * B.y - B.x * A.y + B.x * C.y - C.x * B.y + C.x * A.y - A.x * C.y) / 2.0;
}

int main() {
    Point A = {2.5, 6.0};
    Point B = {1.0, 2.2};
    Point C = {10.0, 6.0};

    double dist_AB = distance(A, B);
    printf("%.2f\n", dist_AB);

    double areaa = area(A, B, C);
    printf("%.2f\n", areaa);

    return 0;
}
