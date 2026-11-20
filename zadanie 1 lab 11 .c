#include <stdio.h>
#include <math.h>

struct point {
    float x;
    float y;
    char name;
};
typedef struct point Point;
void put_point(Point z)
{
    printf("Точка %c (%.1f, %.1f)\n", z.name, z.x, z.y);
}
float dist(Point z, Point w)
{
    return sqrtf((z.x - w.x) * (z.x - w.x) +
                 (z.y - w.y) * (z.y - w.y));
}
Point midpoint(Point z, Point w)
{
    Point m;
    m.x = (z.x + w.x) / 2;
    m.y = (z.y + w.y) / 2;
    m.name = 'M';
    return m;
}
int quarter(Point z)
{
    if (z.x > 0 && z.y > 0)
        return 1;
    if (z.x < 0 && z.y > 0)
        return 2;
    if (z.x < 0 && z.y < 0)
        return 3;
    if (z.x > 0 && z.y < 0)
        return 4;
    return 0;
}
int main(void)
{
    Point a, b, m;
    int q;
    a.name = 'A';
    b.name = 'B';
    printf("Введите координаты точки A (x y): ");
    scanf("%f %f", &a.x, &a.y);
    printf("Введите координаты точки B (x y): ");
    scanf("%f %f", &b.x, &b.y);
    put_point(a);
    put_point(b);
    printf("Расстояние между точками: %.2f\n", dist(a, b));
    m = midpoint(a, b);
    printf("Середина отрезка:\n");
    put_point(m);
    q = quarter(a);
    if (q == 0)
        printf("Точка A лежит на оси координат.\n");
    else
        printf("Точка A относится к четверти %d.\n", q);
    q = quarter(b);
    if (q == 0)
        printf("Точка B лежит на оси координат.\n");
    else
        printf("Точка B относится к четверти %d.\n", q);
    return 0;
}